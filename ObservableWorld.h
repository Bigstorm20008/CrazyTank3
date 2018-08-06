#ifndef OBSERVABLE_WORLD_H
#define OBSERVABLE_WORLD_H

#include <vector>

#include "WorldObserver.h"


class ObservableWorld
{
public:
	ObservableWorld();
	~ObservableWorld();

	void attach(WorldObserver* const worldObserver);
	void detach(WorldObserver* const worldObserver);

protected:
	void notify(const objects::GameObject& gameObject)const;
	std::vector<WorldObserver* const> observers_;
};

#endif // !OBSERVABLE_WORLD_H



