#ifndef GAME_RUNNING_STATE_H
#define GAME_RUNNING_STATE_H

#include <vector>
#include <memory>

#include "GameState.h"
#include "GameTimer.h"
#include "GameEntity.h"
#include "PlayerTank.h"
#include "EntityFactory.h"
#include "World.h"



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
		GameTimer* gameTimer_;
		bool isPaused_;
		World* world_;

		std::shared_ptr<entities::GameEntity> playerTank_;

	};

} //namespace gamestates

#endif // !GAME_RUNNING_STATE_H


