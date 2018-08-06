#include "GameEvent.h"


namespace events
{

	
	GameEvent::GameEvent(const enumerations::Event& eventId) : id_{ eventId }
	{
	}


	GameEvent::~GameEvent()
	{
	}


	const enumerations::Event& GameEvent::getId() const
	{
		return id_;
	}


}//namespace events
