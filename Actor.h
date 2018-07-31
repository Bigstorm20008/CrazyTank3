#ifndef ACTOR_H
#define ACTOR_H

class World;

#include "Events.h"

class Actor
{
public:
	Actor();
	virtual ~Actor();

	virtual void processEvent(const enumerations::Event& currentEvent, World& world) = 0;
};

#endif // !ACTOR_H



