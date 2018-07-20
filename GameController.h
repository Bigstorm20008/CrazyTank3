#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <conio.h>

#include "EventQueue.h"
#include "Input.h"
#include "Game.h"
#include "ConsoleView.h"
#include "ConsoleConstants.h"


class GameController
{
public:
	GameController();
	~GameController();

	void initialize();
	const int run();
	
private:
	bool isInitialized_;
	bool isGameActive_;

	EventQueue eventQueue_;
	Input* input_;
	Game* game_;
	ConsoleView* consoleView_;

	void gameLoop();
};


#endif // !GAME_CONTROLLER_H


