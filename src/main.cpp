#include "vld.h"
#include <thread>

#include "GameController.h"


std::unique_ptr<GameController> gameController{};

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
		gameController.reset(new GameController);
		gameController->initialize();
		gameController->run();
	}
	else{
		std::cout << "Could not set control handler" << std::endl;
	}

	return 0;
}

