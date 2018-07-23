#include "GameEntity.h"

namespace entities
{

	GameEntity::GameEntity(const helpers::Point& position, const wchar_t& graficsPresent)
		: position_(position), graficsPresent_(graficsPresent)
	{
	}


	GameEntity::~GameEntity()
	{
	}

}//namespace entities

