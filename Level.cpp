#include "Level.h"


Level::Level(EventQueue* const eventQueue) 
	: eventQueue_{ eventQueue }, enemiesInWorld_{ 0 },
	  wallsInWorld_{ 0 }, playerShore_{ 0 },
	  levelState_{LevelState::UNKNOWN}
{
}


Level::~Level()
{
	if (world_ != nullptr)
	{
		delete world_;
		world_ = nullptr;
	}
	if (gameTimer_ != nullptr)
	{
		delete gameTimer_;
		gameTimer_ = nullptr;
	}
}


void Level::initialize(GraficsBuffer& graficsBuffer)
{
	using namespace enumerations;
	using namespace helpers;
	using namespace objects;

	graficsBuffer.clear();

	gameTimer_ = new GameTimer;

	Rect worldRect;
	worldRect.left = 0;
	worldRect.bottom = graficsBuffer.getHeight();
	worldRect.right = graficsBuffer.getWidth();
	worldRect.top = 2;
	world_ = new World(worldRect);
	world_->attach(this);

	GameObjectFactory gameObjectFactory;
	actor_ = gameObjectFactory.createGameObject(Point(5, 5), ObjectId::PLAYER_TANK);
	world_->addActor(actor_);

	WallCreator wallCreator;
	wallsInWorld_ = 100;
	for (int i = 0; i < wallsInWorld_; ++i){
		auto wall = wallCreator.createWall(*world_);
		for (auto wallblock : wall)
		{
			world_->storeEntity(wallblock);
		}
	}

	enemiesInWorld_ = 10;
	for (int i = 0; i < enemiesInWorld_; ++i)
	{ 
		Point tankPosition = world_->getRandomFreePointInWorld();
		world_->storeEntity(gameObjectFactory.createGameObject(tankPosition, ObjectId::ENEMY_TANK));
	}
	
	Point tankPosition = world_->getRandomFreePointInWorld();
	Rect rectToFind;
	rectToFind.left = tankPosition.x - 3;
	rectToFind.right = tankPosition.x + 3;
	rectToFind.top = tankPosition.y - 3;
	rectToFind.bottom = tankPosition.y + 3; 
	auto founded = world_->findObjectInRectbyId(ObjectId::ENEMY_TANK, rectToFind); 

	levelState_ = LevelState::RUNNING;
	gameTimer_->start();
}


void Level::processEvent(const enumerations::Event& currentEvent)
{
	world_->processEvent(currentEvent);
}


void Level::pause()
{
	gameTimer_->pause();
}


void Level::resume()
{
	gameTimer_->resume();
}

void Level::update()
{
	if (levelState_ == LevelState::RUNNING){
		world_->updateEntities();
	}
}


void Level::draw(GraficsBuffer& graficsBuffer)
{

	using namespace helpers;
	using namespace enumerations;

	if (levelState_ == LevelState::PLAYER_LOSE)
	{
		const std::wstring loseTitle = { L"You Lose" };
		graficsBuffer.drawText(Point(0, 0), Direction::RIGHT, loseTitle);

		const std::wstring timeInfo = std::move(L"Elapsed time: " + elapsedTime_);
		graficsBuffer.drawText(Point(0, 1), Direction::RIGHT, timeInfo);

		const std::wstring shoreInfo = std::move(L"Shore: " + std::to_wstring(playerShore_));
		graficsBuffer.drawText(Point(0, 2), Direction::RIGHT, shoreInfo);

		const std::wstring helpInfo = { L"Press Q for exit" };
		graficsBuffer.drawText(Point(0, 3), Direction::RIGHT, helpInfo);

	}

	if (levelState_ == LevelState::PLAYER_WIN)
	{
		const std::wstring winTitle = { L"Congratulation!!! You win!!!" };
		graficsBuffer.drawText(Point(0, 0), Direction::RIGHT, winTitle);

		const std::wstring timeInfo = std::move(L"Elapsed time: " + elapsedTime_);
		graficsBuffer.drawText(Point(0, 1), Direction::RIGHT, timeInfo);

		const std::wstring shoreInfo = std::move(L"Shore: " + std::to_wstring(playerShore_));
		graficsBuffer.drawText(Point(0, 2), Direction::RIGHT, shoreInfo);

		const std::wstring helpInfo = { L"Press Q for exit" };
		graficsBuffer.drawText(Point(0, 3), Direction::RIGHT, helpInfo);
	}

	if(levelState_ == LevelState::RUNNING){
		elapsedTime_ = gameTimer_->getElapsedTime();
		const std::wstring timeInfo = std::move(L"Elapsed time: " + elapsedTime_);
		graficsBuffer.drawText(Point(0, 0), Direction::RIGHT, timeInfo);

		const std::wstring shoreInfo = std::move(L"Shore: " + std::to_wstring(playerShore_));
		graficsBuffer.drawText(Point(timeInfo.length() + 1, 0), Direction::RIGHT, shoreInfo);

		const std::wstring playerHealthInfo = std::move(L"Player health: " + std::to_wstring(actor_->getHealth()));
		graficsBuffer.drawText(Point(0, 1), Direction::RIGHT, playerHealthInfo);

		world_->drawEntities(graficsBuffer);
	}
	
}


void Level::processChangedObject(const objects::GameObject& gameObject)
{
	const objects::ObjectId objectId = gameObject.getId();

	switch (objectId)
	{
		case objects::ObjectId::PLAYER_TANK :
			levelState_ = LevelState::PLAYER_LOSE;
			break;

		case objects::ObjectId::ENEMY_TANK :
			--enemiesInWorld_;
			++playerShore_;
			if (enemiesInWorld_ == 0){
				levelState_ = LevelState::PLAYER_WIN;
			}

			break;

		default:
			break;
	}
}
