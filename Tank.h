#ifndef TANK_H
#define TANK_H

#include "DynamicEntity.h"
#include "EntityStore.h"

namespace entities
{
	class Tank :
		public DynamicEntity
	{
	public:

		Tank(const helpers::Point& position, const wchar_t& graficsPresent,
			 const unsigned int& health, const enumerations::Direction& direction);

		virtual ~Tank();

		void update(EntityStore& entityStore)override;
	};

}//namespace entities

#endif // !TANK_H


