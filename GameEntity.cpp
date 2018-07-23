#include "GameEntity.h"

namespace entities
{

	GameEntity::GameEntity(const helpers::Point& position, const wchar_t& graficsPresent,
		                   const unsigned int& health)
		: position_(position), graficsPresent_(graficsPresent), health_(health)
	{
	}


	GameEntity::~GameEntity()
	{
	}


}//namespace entities

