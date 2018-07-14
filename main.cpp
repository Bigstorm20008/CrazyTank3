#include "vld.h"

#include "GameController.h"

int main()
{	
	GameController gameController;
	gameController.initialize();
	return gameController.run();
}