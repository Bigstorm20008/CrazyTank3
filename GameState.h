#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "GameEvent.h"
#include "EventQueue.h"
#include "GraficsBuffer.h"

class GameState
{
public:
	explicit GameState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer);
	virtual ~GameState();

	virtual void initialize() = 0;
	virtual void processEvent(const Event& Event) = 0;
	virtual void update() = 0;

protected:
	EventQueue* const eventQueue_;
	GraficsBuffer* const graficsBuffer_;
};

#endif // !GAME_STATE_H



