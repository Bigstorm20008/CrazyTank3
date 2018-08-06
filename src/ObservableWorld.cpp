#include "ObservableWorld.h"


ObservableWorld::ObservableWorld()
{
}


ObservableWorld::~ObservableWorld()
{
}


void ObservableWorld::attach(WorldObserver* const worldObserver)
{
	observers_.push_back(worldObserver);
}


void ObservableWorld::detach(WorldObserver* const worldObserver)
{

}


void ObservableWorld::notify(const objects::GameObject& gameObject)const
{
	for (auto& observer : observers_)
	{
		observer->processChangedObject(gameObject);
	}
}
