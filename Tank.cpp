#include "Tank.h"

namespace entities
{

	Tank::Tank(const helpers::Point& position, const wchar_t& graficsPresent,
		       const unsigned int& health, const enumerations::Direction& direction)
		  : entities::DynamicEntity {position, graficsPresent, health, direction}
	{
	}


	Tank::~Tank()
	{
	}
	
}//namespace entities