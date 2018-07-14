#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include <queue>

//Forward declaration
enum class Event;

#include "Observable.h"




class EventQueue : public Observable
{
public:
	EventQueue();
	~EventQueue();

	void addEvent(const events::GameEvent& gameEvent);
	void sendNextEvent();

private:
	std::queue<const events::GameEvent> eventsQueue_;
};


#endif // !EVENT_QUEUE_H



