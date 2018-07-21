#include "GameEvent.h"


namespace events
{

	
	GameEvent::GameEvent(const enumarations::Event& eventId) : id_{ eventId }
	{
	}


	GameEvent::~GameEvent()
	{
	}


	const enumarations::Event& GameEvent::getId() const
	{
		return id_;
	}


}//namespace events
