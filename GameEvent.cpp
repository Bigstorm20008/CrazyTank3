#include "GameEvent.h"


namespace events
{

	
	GameEvent::GameEvent(const Event& eventId) : id_(eventId)
	{
	}


	GameEvent::~GameEvent()
	{
	}


	const Event GameEvent::getId() const
	{
		return id_;
	}


}
