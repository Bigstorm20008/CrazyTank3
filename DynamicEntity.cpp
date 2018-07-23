#include "DynamicEntity.h"

namespace entities
{

	DynamicEntity::DynamicEntity(const helpers::Point& position,
		                         const wchar_t& graficsPresent,
								 const unsigned int& health,
								 const enumerations::Direction& direction)
		: entities::GameEntity{ position, graficsPresent,health }, direction_(direction)
	{
	}


	DynamicEntity::~DynamicEntity()
	{
	}

}//namespase entities
