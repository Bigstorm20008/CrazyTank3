#include "EventQueue.h"


EventQueue::EventQueue()
{
	

	
}


EventQueue::~EventQueue()
{
	while (eventsQueue_.empty() == false)
	{	
		eventsQueue_.pop();
	}
}



void EventQueue::addEvent(const events::GameEvent& gameEvent)
{
	eventsQueue_.emplace(gameEvent);
}

void EventQueue::sendNextEvent()
{
	if (eventsQueue_.empty() == false)
	{
		notify(eventsQueue_.front());
		eventsQueue_.pop();
	}
}

