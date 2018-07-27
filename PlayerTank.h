#ifndef PLAYER_TANK_H
#define PLAYER_TANK_H


#include "Tank.h"
#include "EventObserver.h"

namespace entities
{
	class PlayerTank : public Tank , public EventObserver
	{
	public:

		PlayerTank(const helpers::Point& position, const wchar_t& graficsPresent,
			       const unsigned int& health, const enumerations::Direction& direction);

		virtual ~PlayerTank();


		void fire()override;
		void update(World& world)override;

		void processEvent(const events::GameEvent& gameEvent)override;
	};

}//namespace entities

#endif // !PLAYER_TANK_H



