#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}


void Game::update()
{

}


void Game::processEvent(const events::GameEvent& gameEvent)
{
	
	auto ev = gameEvent.getId();
	switch (ev)
	{
	case Event::SPACE_KEY_PRESSED:
	{
		std::cout << "Space key pressed" << std::endl;
		break;
	}

	case Event::UP_ARROW_KEY_PRESSED:
	{
		std::cout << "Up arrow key pressed" << std::endl;
		break;
	}

	default:
		break;
	}
}
