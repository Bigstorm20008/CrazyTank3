#ifndef DYNAMIC_ENTITY_H
#define DYNAMIC_ENTITY_H

#include "GameEntity.h"
#include "Direction.h"


namespace entities
{

	class DynamicEntity :
		public GameEntity
	{
	public:
		DynamicEntity(const helpers::Point& position, const wchar_t& graficsPresent,
			          const unsigned int& health, const enumerations::Direction& direction);
		virtual ~DynamicEntity();

		inline const enumerations::Direction& getDirection()const;

		void move(const enumerations::Direction& direction);

	protected:
		enumerations::Direction direction_;
	};


	inline const enumerations::Direction& DynamicEntity::getDirection()const
	{
		return direction_;
	}

}//namespace entities

#endif // !DYNAMIC_ENTITY_H


