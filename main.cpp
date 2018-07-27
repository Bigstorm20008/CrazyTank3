#include "vld.h"
#include <thread>

#include "GameController.h"

GameController* gameController = nullptr;

BOOL CtrlHandler(DWORD fdwCtrlType)
{

	switch (fdwCtrlType)
	{

	case CTRL_CLOSE_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_SHUTDOWN_EVENT:
		if (gameController != nullptr)
		{
			gameController->exitGame();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(20000));
		return TRUE;

	default:
		return FALSE;
	}
}

int main()
{	
	

	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE) == TRUE)
	{
		gameController = new GameController;
		gameController->initialize();
		gameController->run();
	}
	else{
		std::cout << "Could not set control handler" << std::endl;
	}

	delete gameController;
	gameController = nullptr;

	
	return 0;
}

