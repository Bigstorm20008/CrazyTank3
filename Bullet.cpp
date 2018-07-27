#include "Bullet.h"

namespace entities
{

	Bullet::Bullet(const helpers::Point& position, const wchar_t& graficsPresent,
		           const unsigned int& health, const enumerations::Direction& direction) :
				   DynamicEntity{position,graficsPresent,health,direction}
	{
	}


	Bullet::~Bullet()
	{
	}

}//namespace entities
