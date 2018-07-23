#include "DynamicEntity.h"

namespace entities
{

	DynamicEntity::DynamicEntity(const helpers::Point& position, const wchar_t& graficsPresent, const enumerations::Direction& direction)
		: entities::GameEntity{ position, graficsPresent }, direction_(direction)
	{
	}


	DynamicEntity::~DynamicEntity()
	{
	}

}//namespase entities
