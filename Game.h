#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>

#include "EventObserver.h"
#include "EventQueue.h"

#include "GameState.h"
#include "MainMenuState.h"

#include "GraficsBuffer.h"


class Game : public EventObserver
{
public:
	explicit Game(EventQueue& eventQueue, GraficsBuffer& backGraficsBuffer);
	~Game();

	void initialize();

	void update();

	const bool isActiveState() const;
private:
	EventQueue* const eventQueue_;
	GraficsBuffer* const graficsBuffer_;
	std::unique_ptr<GameState> gameState_;
	bool isActive_;

	void processEvent(const events::GameEvent& gameEvent) override;
};

#endif // !GAME_H




