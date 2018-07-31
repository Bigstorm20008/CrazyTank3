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
		
		Rect worldRect;
		worldRect.left = 0;
		worldRect.bottom = graficsBuffer_->getHeight();
		worldRect.right = graficsBuffer_->getWidth();
		worldRect.top = 2;
		world_ = new World(worldRect);

		std::chrono::milliseconds reloadingTime{ 500 };
		playerTank_.reset(new PlayerTank(Point(5, 5), { 'T' }, 3, Direction::UP, 1, reloadingTime));
		
		std::shared_ptr<GameObject> enemyTank = std::make_shared<EnemyTank>(EnemyTank{ Point(5, 10), 'S', 3, Direction::UP, 1, reloadingTime });
		world_->storeEntity(enemyTank);

		std::shared_ptr<GameObject> enemyTank2 = std::make_shared<EnemyTank>(EnemyTank{ Point(5, 11), 'S', 3, Direction::UP, 1, reloadingTime });
		world_->storeEntity(enemyTank2);

		std::shared_ptr<GameObject> enemyTank3 = std::make_shared<EnemyTank>(EnemyTank{ Point(5, 12), 'S', 3, Direction::UP, 1, reloadingTime });
		world_->storeEntity(enemyTank3);

		std::shared_ptr<GameObject> enemyTank4 = std::make_shared<EnemyTank>(EnemyTank{ Point(5, 13), 'S', 3, Direction::UP, 1, reloadingTime });
		world_->storeEntity(enemyTank4);

		isPaused_ = false;

		gameTimer_->start();
	}


	void GameRunnigState::processEvent(const enumerations::Event& event)
	{
		using namespace enumerations;

		switch (event)
		{
			case enumerations::Event::PAUSE_GAME:
			{
				if (isPaused_ == false){
					isPaused_ = true;
					gameTimer_->pause();
				}
				else{
					gameTimer_->resume();
					isPaused_ = false;
				}
			}

			default:
				if (isPaused_ == false)
					playerTank_->processEvent(event, *world_);
				break;
		}
		
	}


	void GameRunnigState::update()
	{
		using namespace helpers;
		using namespace enumerations;

		graficsBuffer_->clear();

		if (isPaused_ == false){
			const std::wstring elapsedTime = gameTimer_->getElapsedTime();
			const std::wstring timeInfo = std::move( L"Elapsed time: " + elapsedTime );
			graficsBuffer_->drawText( Point(0, 0), Direction::RIGHT, timeInfo );

			const std::wstring playerHealthInfo = std::move( L"Player health: " + std::to_wstring(playerTank_->getHealth()) );
 			graficsBuffer_->drawText(Point(0, 1), Direction::RIGHT, playerHealthInfo);

			graficsBuffer_->drawSymbol(playerTank_->getPosition().x,
				                       playerTank_->getPosition().y,
									   playerTank_->getGraficsPresent());
			world_->updateEntities();
			world_->drawEntities(*graficsBuffer_);
		}
		else{
			
			graficsBuffer_->drawText(Point(0, 0), Direction::RIGHT, { L"GamePaused" });
		}
	}

}//namespace gamestates
