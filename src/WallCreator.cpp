#include "WallCreator.h"


WallCreator::WallCreator()
{
}


WallCreator::~WallCreator()
{
}


std::vector<std::shared_ptr<objects::GameObject>> 
WallCreator::createWall(const World& world)
{
	std::vector<std::shared_ptr<objects::GameObject>> wall{};
	GameObjectFactory gameObjectFactory;

	helpers::RandomEngine* engineInstance = nullptr;
	const auto randomEngine = engineInstance->getInstance();

	const unsigned int wallSize = randomEngine->getRandomInteger(2, 6);
	const enumerations::Direction wallDirection = static_cast<enumerations::Direction>( randomEngine->getRandomInteger(0, 3));

	bool isWallConstructed = false;
	while (isWallConstructed == false)
	{
		helpers::Point startWallPosition = world.getRandomFreePointInWorld();
		wall.push_back(gameObjectFactory.createGameObject(startWallPosition, objects::ObjectId::WALL_BLOCK));
		helpers::Point nextPoint = helpers::getNextPoint(startWallPosition, wallDirection, 1);
		while (wall.size() != wallSize)
		{	
			if (world.checkCollisionAtPoint(nextPoint) == true){
				wall.push_back(gameObjectFactory.createGameObject(nextPoint, objects::ObjectId::WALL_BLOCK));
				nextPoint = helpers::getNextPoint(nextPoint, wallDirection, 1);
				if (wall.size() == wallSize){
					isWallConstructed = true;
					break;
				}
			}
			else{
				wall.clear();
				break;
			}
		}
	}
	
	return wall;
}
