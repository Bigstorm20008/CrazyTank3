#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>

//Forward declaration
class GameEvent;

#include "EventObserver.h"

class Observable
{
public:
	Observable();
	~Observable();


	void attach(EventObserver* const eventObserver);
	void detach(EventObserver* const eventObserver);

protected:
	void notify(const events::GameEvent& gameEvent)const;
	std::vector<EventObserver* const> observers_;
};



#endif // !OBSERVABLE_H


