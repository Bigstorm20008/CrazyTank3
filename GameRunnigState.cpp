#include "GameRunnigState.h"

namespace gamestates
{

	GameRunnigState::GameRunnigState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer)
		: GameState{ eventQueue, graficsBuffer }, gameTimer_{}, entityStore_{}
	{
		
	}


	GameRunnigState::~GameRunnigState()
	{
		if (gameTimer_ != nullptr)
		{
			delete gameTimer_;
			gameTimer_ = nullptr;
		}
	}


	void GameRunnigState::initialize()
	{
		graficsBuffer_->clear();

		gameTimer_ = new GameTimer;
		gameTimer_->start();
		isPaused_ = false;
	}


	void GameRunnigState::processEvent(const enumerations::Event& event)
	{
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
				break;
		}
	}


	void GameRunnigState::update()
	{
		if (isPaused_ == false){
			graficsBuffer_->clear();

			const std::wstring elapsedTime = gameTimer_->getElapsedTime();
			const std::wstring textToOut = std::move(L"Elapsed time: " + elapsedTime);
			graficsBuffer_->drawText(helpers::Point(0, 0), enumerations::Direction::RIGHT, textToOut);

			entityStore_.updateEntities();
		}
		else{
			graficsBuffer_->clear();
			graficsBuffer_->drawText(helpers::Point(0, 0), enumerations::Direction::RIGHT, L"GamePaused");
		}
	}

}//namespace gamestates
