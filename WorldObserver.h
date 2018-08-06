#ifndef WORLD_OBSERVER_H
#define WORLD_OBSERVER_H

#include "GameObject.h"

class WorldObserver
{
public:
	WorldObserver();
	~WorldObserver();

	virtual void processChangedObject(const objects::GameObject& gameObject) = 0;
};

#endif // !WORLD_OBSERVER_H



