#include "Game.h"


Game::Game(EventQueue& eventQueue, GraficsBuffer& backGraficsBuffer) : eventQueue_{ &eventQueue }, 
                                                                       graficsBuffer_{ &backGraficsBuffer }, 
																	   gameState_{}, isActive_{ false }
{
}


Game::~Game()
{
	gameState_.reset();
}


void Game::initialize()
{
	gameState_.reset( new MainMenuState{ *eventQueue_ , *graficsBuffer_ } );
	isActive_ = true;
}


void Game::update()
{
	gameState_->update();
}


void Game::processEvent(const events::GameEvent& gameEvent)
{
	if (gameEvent.getId() == Event::QUIT_GAME)
	{
		isActive_ = false;
	}
	else {
		gameState_->processEvent(gameEvent);
	}
}


const bool  Game::isActiveState() const
{
	return isActive_;
}

