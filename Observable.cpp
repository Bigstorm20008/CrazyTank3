#include "Observable.h"


Observable::Observable()
{
}


Observable::~Observable()
{
}


void Observable::attach(EventObserver* const eventObserver)
{
	observers_.push_back( eventObserver );
}


void Observable::detach(EventObserver* const eventObserver)
{

}


void Observable::notify(const events::GameEvent& gameEvent)const
{
	for (auto& observer : observers_)
	{
		observer->processEvent( gameEvent );
	}
}
