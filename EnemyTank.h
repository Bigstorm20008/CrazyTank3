#ifndef ENEMY_TANK_H
#define ENEMY_TANK_H

#include "GameEntity.h"
#include "DynamicObject.h"
#include "Tank.h"
#include "World.h"
#include "RandomEngine.h"
#include "Bullet.h"

namespace objects
{
	class EnemyTank :
		public GameEntity, public DynamicObject, public Tank
	{
	public:
		EnemyTank(const helpers::Point& position,
			      const wchar_t& graficsPresent,
			      const unsigned int& health,
			      const ObjectId& objectId,
			      const enumerations::Direction& direction,
			      const unsigned int& speed,
			      const std::chrono::milliseconds& reloadTimeInMillseconds,
			      const std::chrono::milliseconds& logicPeriodInMilliseconds);

		virtual ~EnemyTank();

	private:
		void move(const enumerations::Direction direction) override;
		void doLogic(World& world) override;
		void fire(World& world) override;

		void doMovementLogic(const World& world);
		const GameObject* const findTargets(const World& world) const;
		const enumerations::Direction computeDirectionToTarget(const GameObject& target) const;
	};

}//namespace objects

#endif // !ENEMY_TANK_H



