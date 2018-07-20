#include "Game.h"


Game::Game(EventQueue& eventQueue, GraficsBuffer& backGraficsBuffer) : eventQueue_{ &eventQueue }, 
                                                                       graficsBuffer_{ &backGraficsBuffer }, 
																	   gameState_{}, 
																	   isActive_{ false }
{
}


Game::~Game()
{
	gameState_.reset();
}


void Game::initialize()
{
	gameState_.reset(new MainMenuState{ *eventQueue_, *graficsBuffer_ });
	gameState_.get()->initialize();
	isActive_ = true;
}


void Game::update()
{
	gameState_->update();
}


void Game::processEvent(const events::GameEvent& gameEvent)
{

	const Event event = gameEvent.getId();

	switch (event)
	{
		case Event::QUIT_GAME :
		{
			isActive_ = false;
			break;
		}

		case Event::START_GAME :
		{
			if (gameState_)
			{
				gameState_.reset({ new GameRunnigState{ *eventQueue_, *graficsBuffer_ } });
				gameState_->initialize();
			}
			break;
		}

		case Event::PAUSE_GAME :
		{
			if (gameState_)
			{
				gameState_.reset({ new PauseState{ *eventQueue_, *graficsBuffer_ } });
				gameState_->initialize();
			}
			break;
		}

		default:
		{
			gameState_->processEvent(event);
			break;
		}
	}
	
}


const bool  Game::isActiveState() const
{
	return isActive_;
}





