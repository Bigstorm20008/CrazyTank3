#include "Bullet.h"

namespace objects
{

	Bullet::Bullet(const helpers::Point& position,
		           const wchar_t& graficsPresent,
		           const unsigned int& health,
		           const ObjectId& objectId,
		           const enumerations::Direction& direction,
		           const unsigned int& speed,
		           const std::chrono::milliseconds& logicPeriodInMilliseconds) :
		           GameEntity{ logicPeriodInMilliseconds },
		           DynamicObject{ position, graficsPresent, health, objectId, direction, speed }

	{
	}


	Bullet::~Bullet()
	{
	}


	void Bullet::move(const enumerations::Direction direction)
	{
		defaultMove(direction);
	}

	void Bullet::doLogic(World& world)
	{
		helpers::Point nextPosition = helpers::getNextPoint(position_, direction_, speed_);

		if (world.checkCollisionAtPoint(nextPosition) == true){
			move(direction_);
		}
		else{
			GameObject* object = world.findEntityAtPoint(nextPosition);

			if (object != nullptr){
				doDamage(*object);
			}
			this->decreaseHealth();
		}
	}


	void Bullet::doDamage(GameObject& object)
	{
		switch (this->objectId_)
		{
		case ObjectId::ENEMY_BULLET:
			object.decreaseHealth();
			break;

		case ObjectId::PLAYER_BULLET:
			object.decreaseHealth();
			break;

		default:
			break;
		}
	}

}