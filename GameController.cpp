#include "GameController.h"


GameController::GameController() : isInitialized_{ false }, isGameActive_{ false }, eventQueue_{}, input_{}, game_{}
{
}


GameController::~GameController()
{
	if (input_ != nullptr)
	{
		delete input_;
		input_ = nullptr;
	}
	if (game_ != nullptr)
	{
		delete game_;
		game_ = nullptr;
	}
}


void GameController::initialize()
{
	input_ = new Input(eventQueue_);
	game_ = new Game();
	eventQueue_.attach(game_);
	isInitialized_ = true;
}


const int GameController::run()
{
	if (isInitialized_ == true)
	{	
		isGameActive_ = true;
		gameLoop();
	}

	return 0;
}


void GameController::gameLoop()
{
	while (isGameActive_)
	{
		if (_kbhit())
		{
			Key key = static_cast<Key>(_getch());
			input_->inputHandler(key);
		}

		eventQueue_.sendNextEvent();
		//game->update();
		//view->render();
	}
}