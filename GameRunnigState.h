#ifndef GAME_RUNNING_STATE_H
#define GAME_RUNNING_STATE_H

#include "GameState.h"

class GameRunnigState : public GameState
{
public:
	GameRunnigState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer);
	virtual ~GameRunnigState();

	void initialize()override;
	void processEvent(const Event& Event)override;
	void update()override;
};


#endif // !GAME_RUNNING_STATE_H


