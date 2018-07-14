#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "EventObserver.h"

class Game :
	public EventObserver
{
public:
	Game();
	~Game();

	void update();
	
private:
	void processEvent(const events::GameEvent& gameEvent) override;
};

#endif // !GAME_H




