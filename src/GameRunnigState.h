#ifndef GAME_RUNNING_STATE_H
#define GAME_RUNNING_STATE_H

#include <vector>
#include <memory>

#include "GameState.h"
#include "Level.h"




namespace gamestates
{
	class GameRunnigState : public GameState
	{
	public:
		GameRunnigState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer);
		virtual ~GameRunnigState();

		void initialize()override;
		void processEvent(const enumerations::Event& Event)override;
		void update()override;

	private:
		Level* level_;
		bool isPaused_;
	};

} //namespace gamestates

#endif // !GAME_RUNNING_STATE_H


