#ifndef ENEMY_TANK_H
#define ENEMY_TANK_H

#include "GameEntity.h"
#include "DynamicObject.h"
#include "Tank.h"
#include "World.h"
#include "RandomEngine.h"

class EnemyTank :
	public GameEntity, public DynamicObject, public Tank
{
public:
	EnemyTank(const helpers::Point& position,
		      const wchar_t& graficsPresent,
		      const unsigned int& health,
		      const enumerations::Direction& direction,
		      const unsigned int& speed,
			  const std::chrono::milliseconds& reloadTimeInMillseconds);

	virtual ~EnemyTank();

	void update(const World& world) override;

private:
	void move(const enumerations::Direction direction) override;
	void fire(World& world) override;
};

#endif // !ENEMY_TANK_H



