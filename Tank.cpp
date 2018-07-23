#include "Tank.h"

namespace entities
{
	Tank::Tank(const helpers::Point& position, const wchar_t& graficsPresent, const enumerations::Direction& direction)
		: entities::DynamicEntity {position, graficsPresent,direction}
	{
	}


	Tank::~Tank()
	{
	}


	void Tank::update()
	{

	}
}