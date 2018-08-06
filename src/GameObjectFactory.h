#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include <memory>

#include "GameObject.h"
#include "PlayerTank.h"
#include "Bullet.h"
#include "EnemyTank.h"
#include "WallBlock.h"
#include "RandomEngine.h"
#include "ObjectsConstants.h"

class GameObjectFactory
{
public:
	GameObjectFactory();
	~GameObjectFactory();

	std::shared_ptr<objects::GameObject> 
	createGameObject(const helpers::Point& objectPosition,
	                 const objects::ObjectId& objectId);

};

#endif // !GAME_OBJECT_FACTORY_H



