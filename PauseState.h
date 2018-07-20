#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include "GameState.h"

class PauseState : public GameState
{
public:
	PauseState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer);
	~PauseState();

	void initialize()override;
	void processEvent(const Event& Event)override;
	void update()override;
};

#endif // !PAUSE_STATE_H



