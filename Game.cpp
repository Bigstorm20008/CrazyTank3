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
	gameState_.reset(new gamestates::MainMenuState{ *eventQueue_, *graficsBuffer_ });
	gameState_.get()->initialize();
	isActive_ = true;
}


void Game::processEvent(const events::GameEvent& gameEvent)
{

	const enumarations::Event event = gameEvent.getId();

	switch (event)
	{
		case enumarations::Event::QUIT_GAME:
		{
			isActive_ = false;
			break;
		}

		case enumarations::Event::START_GAME:
		{	
			setState({ new gamestates::GameRunnigState{ *eventQueue_, *graficsBuffer_ } });
			break;
		}

		/*case enumarations::Event::PAUSE_GAME:
		{
			if (gameState_)
			{
				gameState_.reset({ new gamestates::PauseState{ *eventQueue_, *graficsBuffer_ } });
				gameState_->initialize();
			}
			break;
		}*/

		default:
		{
			gameState_->processEvent(event);
			break;
		}
	}
	
}


void Game::setState(gamestates::GameState* gamestate)
{
	if (typeid(*gamestate) != typeid(*gameState_))
	{
		gameState_.reset(gamestate);
		gameState_->initialize();
	}
}







