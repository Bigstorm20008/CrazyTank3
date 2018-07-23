#include "vld.h"

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
		Sleep(20000);
		return(TRUE);

	default:
		return FALSE;
	}
}

int main()
{	

	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE) == true)
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

