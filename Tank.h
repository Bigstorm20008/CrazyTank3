#ifndef TANK_H
#define TANK_H

#include "DynamicEntity.h"
#include "World.h"

namespace entities
{
	class Tank :
		public DynamicEntity
	{
	public:

		Tank(const helpers::Point& position, const wchar_t& graficsPresent,
			 const unsigned int& health, const enumerations::Direction& direction);

		virtual ~Tank();

		virtual void fire() = 0;
	};

}//namespace entities

#endif // !TANK_H


