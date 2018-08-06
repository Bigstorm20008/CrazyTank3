#ifndef EVENT_OBSERVER_H
#define EVENT_OBSERVER_H

#include "GameEvent.h"

class EventObserver
{
public:
	EventObserver();
	~EventObserver();

	virtual void processEvent(const events::GameEvent& gameEvent) = 0;
};

#endif // !EVENT_OBSERVER_H



