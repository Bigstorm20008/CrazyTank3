#ifndef GAME_RUNNING_STATE_H
#define GAME_RUNNING_STATE_H

#include "GameState.h"
#include "GameTimer.h"

namespace gamestates
{
	class GameRunnigState : public GameState
	{
	public:
		GameRunnigState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer);
		virtual ~GameRunnigState();

		void initialize()override;
		void processEvent(const enumarations::Event& Event)override;
		void update()override;

	private:
		GameTimer* gameTimer_;
		bool isPaused_;
	};

} //namespace gamestates

#endif // !GAME_RUNNING_STATE_H


