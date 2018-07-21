#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include "GameState.h"

namespace gamestates
{
	class PauseState : public GameState
	{
	public:
		PauseState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer);
		~PauseState();

		void initialize()override;
		void processEvent(const enumarations::Event& Event)override;
		void update()override;
	};

}//namespace gamestates

#endif // !PAUSE_STATE_H



