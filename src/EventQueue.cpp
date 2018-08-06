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





