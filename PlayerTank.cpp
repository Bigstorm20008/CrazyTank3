#include "PlayerTank.h"

namespace entities
{

	PlayerTank::PlayerTank(const helpers::Point& position, const wchar_t& graficsPresent,
		                   const unsigned int& health, const enumerations::Direction& direction) :
						   Tank {position,graficsPresent,health,direction}
	{
	}


	PlayerTank::~PlayerTank()
	{
	}


	void PlayerTank::fire()
	{

	}


	void PlayerTank::update(World& world)
	{

	}

	void PlayerTank::processEvent(const events::GameEvent& gameEvent)
	{

	}

}
