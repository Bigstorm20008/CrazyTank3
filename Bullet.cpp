#include "Bullet.h"


Bullet::Bullet(const helpers::Point& position,
	           const wchar_t& graficsPresent,
	           const unsigned int& health,
	           const enumerations::Direction& direction,
	           const unsigned int& speed) :
			   DynamicObject{position, graficsPresent,health,direction,speed}
{
}


Bullet::~Bullet()
{
}


void Bullet::move(const enumerations::Direction direction)
{
	defaultMove(direction);
}


void Bullet::update(const World& world)
{
	helpers::Point nextPosition = position_;
	switch (direction_)
	{
		case enumerations::Direction::DOWN :
			++nextPosition.y;
			break;

		case enumerations::Direction::UP :
			--nextPosition.y;
			break;

		case enumerations::Direction::LEFT :
			--nextPosition.x;
			break;

		case enumerations::Direction::RIGHT :
			++nextPosition.x;
			break;

		default:
			break;
	}

	if(world.checkCollisionAtPoint(nextPosition) == true)
		move(direction_);
	else{
		health_ = 0;
	}
}
