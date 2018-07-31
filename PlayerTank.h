#ifndef PLAYER_TANK_H
#define PLAYER_TANK_H

#include "Actor.h"
#include "Tank.h"
#include "DynamicObject.h"
#include "World.h"
#include "Bullet.h"

class PlayerTank :
	public Actor, public DynamicObject, public Tank
{
public:
	PlayerTank(const helpers::Point& position,
		       const wchar_t& graficsPresent,
		       const unsigned int& health,
			   const enumerations::Direction& direction,
		       const unsigned int& speed,
			   const std::chrono::milliseconds& reloadTimeInMillseconds);

	~PlayerTank();

	void processEvent(const enumerations::Event& currentEvent, World& world) override;
	void move(const enumerations::Direction direction) override;
	void fire(World& world) override;
};

#endif // !PLAYER_TANK_H



