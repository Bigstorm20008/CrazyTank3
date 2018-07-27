#ifndef BULLET_H
#define BULLET_H

#include "DynamicEntity.h"

namespace entities
{

	class Bullet :
		public DynamicEntity
	{
	public:
		Bullet(const helpers::Point& position, const wchar_t& graficsPresent,
			   const unsigned int& health, const enumerations::Direction& direction);
		virtual ~Bullet();
	};

}//namespace entities
#endif // !BULLET_H



