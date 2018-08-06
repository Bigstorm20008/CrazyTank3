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

	inline void addEvent(const events::GameEvent&& gameEvent);
	inline void addEvent(const events::GameEvent& gameEvent);

	inline void sendNextEvent();

private:
	std::queue<const events::GameEvent> eventsQueue_;
};




inline void EventQueue::addEvent(const events::GameEvent&& gameEvent)
{
	eventsQueue_.emplace(std::move(gameEvent));
}


inline void EventQueue::addEvent(const events::GameEvent& gameEvent)
{
	eventsQueue_.emplace(gameEvent);
}


inline void EventQueue::sendNextEvent()
{
	if (eventsQueue_.empty() == false)
	{
		notify(eventsQueue_.front());
		eventsQueue_.pop();
	}
}


#endif // !EVENT_QUEUE_H



