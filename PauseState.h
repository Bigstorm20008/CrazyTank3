#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include "GameState.h"

class PauseState :
	public GameState
{
public:
	PauseState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer);
	~PauseState();
};

#endif // !PAUSE_STATE_H



