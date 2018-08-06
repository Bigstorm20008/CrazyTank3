#ifndef WALL_CREATOR_H
#define WALL_CREATOR_H

#include <vector>
#include <memory>

#include "WallBlock.h"
#include "World.h"
#include "RandomEngine.h"
#include "GameObjectFactory.h"

class WallCreator
{
public:
	WallCreator();
	~WallCreator();

	std::vector<std::shared_ptr<objects::GameObject>> createWall(const World& world);

};

#endif // !WALL_CREATOR_H



