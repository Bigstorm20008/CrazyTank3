#include "GameRunnigState.h"

namespace gamestates
{

	GameRunnigState::GameRunnigState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer)
		: GameState{ eventQueue, graficsBuffer }, level_{}
	{
		
	}


	GameRunnigState::~GameRunnigState()
	{
		if (level_ != nullptr)
		{
			delete level_;
			level_ = nullptr;
		}
	}


	void GameRunnigState::initialize()
	{
		graficsBuffer_->clear();

		level_ = new Level{ eventQueue_ };
		level_->initialize( *graficsBuffer_ );
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
					level_->pause();
				}
				else{
					level_->resume();
					isPaused_ = false;
				}
			}

			default:
				if (isPaused_ == false)
					level_->processEvent(event);
				break;
		}
		
	}


	void GameRunnigState::update()
	{
		using namespace helpers;
		using namespace enumerations;

		graficsBuffer_->clear();

		if (isPaused_ == false){
			
			level_->update();
			level_->draw(*graficsBuffer_);
		}
		else{
			graficsBuffer_->drawText(Point(0, 0), Direction::RIGHT, { L"GamePaused" });
		}
	}

}//namespace gamestates
