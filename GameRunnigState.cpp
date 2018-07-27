#include "GameRunnigState.h"

namespace gamestates
{

	GameRunnigState::GameRunnigState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer)
		: GameState{ eventQueue, graficsBuffer }, gameTimer_{}, world_{}, playerTank_{}
	{
		
	}


	GameRunnigState::~GameRunnigState()
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
		playerTank_.reset();
	}


	void GameRunnigState::initialize()
	{
		using namespace enumerations;
		using namespace helpers;

		graficsBuffer_->clear();

		gameTimer_ = new GameTimer;
		gameTimer_->start();
		isPaused_ = false;

		helpers::Rect worldRect;
		worldRect.left = 0;
		worldRect.bottom = graficsBuffer_->getHeight();
		worldRect.right = graficsBuffer_->getWidth();
		worldRect.top = 2;
		world_ = new World(worldRect);

		factories::EntityFactory entityFactory;
		playerTank_ = entityFactory.createEntity( EntityId::PLAYER_TANK, Point{ 5, 5 } );
		world_->storeEntity( playerTank_ );
		eventQueue_->attach(reinterpret_cast<EventObserver*>(playerTank_.get()));

	}


	void GameRunnigState::processEvent(const enumerations::Event& event)
	{
		using namespace enumerations;
		using namespace entities;
		using namespace helpers;

		switch (event)
		{
			case enumerations::Event::PAUSE_GAME :
				if (isPaused_ == false){
					isPaused_ = true;
					gameTimer_->pause();
				}
				else{
					gameTimer_->resume();
					isPaused_ = false;
				}	

			case enumerations::Event::UP_ARROW_KEY_PRESSED:
			{
				PlayerTank* tank = dynamic_cast<PlayerTank*>(playerTank_.get());
				const Point& currentPosition = tank->getPosition();
				const Point nextPosition{ currentPosition.x, currentPosition.y - 1 };
				if (world_->checkCollisionAtPoint(nextPosition) == true)
				{
					tank->move(Direction::UP);
				}
				break;
			}

			case enumerations::Event::DOWN_ARROW_KEY_PRESSED :
			{
				PlayerTank* tank = dynamic_cast<PlayerTank*>(playerTank_.get());
				const Point& currentPosition = tank->getPosition();
				const Point nextPosition{ currentPosition.x, currentPosition.y + 1 };
				if (world_->checkCollisionAtPoint(nextPosition) == true)
				{
					tank->move(Direction::DOWN);
				}
				break;
			}

			case enumerations::Event::LEFT_ARROW_KEY_PRESSED :
			{
				PlayerTank* tank = dynamic_cast<PlayerTank*>(playerTank_.get());
				const Point& currentPosition = tank->getPosition();
				const Point nextPosition{ currentPosition.x - 1, currentPosition.y };
				if (world_->checkCollisionAtPoint(nextPosition) == true)
				{
					tank->move(Direction::LEFT);
				}
				break;
			}

			case enumerations::Event::RIGHT_ARROW_KEY_PRESSED :
			{
				PlayerTank* tank = dynamic_cast<PlayerTank*>(playerTank_.get());
				const Point& currentPosition = tank->getPosition();
				const Point nextPosition{ currentPosition.x + 1, currentPosition.y };
				if (world_->checkCollisionAtPoint(nextPosition) == true)
				{
					tank->move(Direction::RIGHT);
				}
				break;
			}

			case enumerations::Event::SPACE_KEY_PRESSED :
				dynamic_cast<PlayerTank*>(playerTank_.get())->fire();
				break;

			default:
				break;
		}
	}


	void GameRunnigState::update()
	{
		using namespace helpers;
		using namespace enumerations;

		if (isPaused_ == false){
			graficsBuffer_->clear();

			const std::wstring elapsedTime = gameTimer_->getElapsedTime();
			const std::wstring textToOut = std::move(L"Elapsed time: "  + elapsedTime);
			graficsBuffer_->drawText(Point(0, 0), Direction::RIGHT, textToOut);

			world_->updateEntities();
			world_->drawEntities(*graficsBuffer_);
		}
		else{
			graficsBuffer_->clear();
			graficsBuffer_->drawText(Point(0, 0), Direction::RIGHT, { L"GamePaused" });
		}
	}

}//namespace gamestates
