#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include <typeinfo>

#include "EventObserver.h"
#include "EventQueue.h"

#include "GameState.h"
#include "MainMenuState.h"
#include "GameRunnigState.h"


#include "GraficsBuffer.h"


class Game : public EventObserver
{
public:
	explicit Game(EventQueue& eventQueue, GraficsBuffer& backGraficsBuffer);
	~Game();

	void initialize();

	inline void update();

	inline const bool isActiveState() const;
private:
	EventQueue* const eventQueue_;
	GraficsBuffer* const graficsBuffer_;
	std::unique_ptr<gamestates::GameState> gameState_;
	bool isActive_;

	void processEvent(const events::GameEvent& gameEvent) override;
	void setState(gamestates::GameState* gamestate);
};



inline void Game::update()
{
	gameState_->update();
}


inline const bool  Game::isActiveState() const
{
	return isActive_;
}



#endif // !GAME_H




