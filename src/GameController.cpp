#include "GameController.h"


GameController::GameController() 
	: isInitialized_( false ), isGameActive_( false ),
	  eventQueue_{}, input_{}, game_{}, consoleView_{}
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

	if (consoleView_ != nullptr)
	{
		delete consoleView_;
		consoleView_ = nullptr;
	}
}


void GameController::initialize()
{
	input_ = new Input{ eventQueue_ };

	
	consoleView_ = new ConsoleView{};
	constants::ConsoleConstants consoleConstants;
	consoleView_->initialize( consoleConstants.getDefaultWidth(),
		                      consoleConstants.getDefaultHeight() );
	
	GraficsBuffer& backBuffer = consoleView_->getBackBuffer();
	game_ = new Game{ eventQueue_ , backBuffer};
	game_->initialize();
	eventQueue_.attach( game_ );

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
	std::chrono::high_resolution_clock::time_point currentTimePoint;
	std::chrono::high_resolution_clock::time_point previousTimePoint;
	std::chrono::milliseconds milliseconds25 { 25 };
	currentTimePoint = previousTimePoint = std::chrono::high_resolution_clock::now();

	while (isGameActive_ == true)
	{
		if (_kbhit()){
			const enumerations::Key key{ static_cast<enumerations::Key>(_getch()) };
			input_->inputHandler(key);
		}
		currentTimePoint = std::chrono::high_resolution_clock::now();
		bool timeToUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(currentTimePoint - previousTimePoint) >= milliseconds25;
		if (timeToUpdate)
		{
			eventQueue_.sendNextEvent();
			game_->update();
			consoleView_->render();

			isGameActive_ = game_->isActiveState();
			previousTimePoint = currentTimePoint;
		}
	}
}


void GameController::exitGame()
{
	eventQueue_.addEvent({ enumerations::Event::QUIT_GAME });
}
