#include "GameObjectFactory.h"


GameObjectFactory::GameObjectFactory()
{
}


GameObjectFactory::~GameObjectFactory()
{
}


std::shared_ptr<objects::GameObject> 
GameObjectFactory::createGameObject(const helpers::Point& objectPosition,
                                    const objects::ObjectId& objectId)
{
	using namespace objects;
	std::shared_ptr<GameObject> gameObject{};
	constants::ObjectsConstants objectConstants;

	switch (objectId)
	{
		
		case ObjectId::ENEMY_TANK:
		{
			gameObject.reset(new EnemyTank{ objectPosition,
				                            objectConstants.getDefaultEnemyTankPresent(),
											objectConstants.getDefaultTankHealth(),
											objectId,
											{ enumerations::Direction::UP },
											objectConstants.getDefaultObjectSpeed(),
											objectConstants.getEnemyTankReloadingTime(),
											objectConstants.getEnemyTankLogicSpeed() } );
			break;
		}

		case ObjectId::PLAYER_TANK:
		{
			
			const std::chrono::milliseconds reloadingTime = objectConstants.getPlayerTankReloadingTime();
			const unsigned int playerTankHealth = objectConstants.getDefaultTankHealth();

			gameObject.reset(new PlayerTank{ objectPosition,
				                             objectConstants.getDefaultPlaerTankPresents(),
											 objectConstants.getDefaultTankHealth(),
											 objectId,
											 { enumerations::Direction::UP },
											 objectConstants.getDefaultObjectSpeed(),
											 objectConstants.getPlayerTankReloadingTime() });
			break;
		}

		case ObjectId::WALL_BLOCK:
		{
			std::wstring allWallBlockPresents = objectConstants.getDefaultWallBlockPresents();
			std::chrono::milliseconds logicSpeed{ 0 };

			gameObject.reset(new WallBlock{ objectPosition,
				                            allWallBlockPresents.at(0),
											allWallBlockPresents.length(),
											objectId,
											logicSpeed,
											allWallBlockPresents });
			break;
		}

		case ObjectId::STRONGHOLD_BLOCK:
		{
			std::wstring allWallBlockPresents = objectConstants.getDefaultStrongholdBlocksPresents();
			std::chrono::milliseconds logicSpeed{ 0 };

			gameObject.reset(new WallBlock{ objectPosition,
				                            allWallBlockPresents.at(0),
											allWallBlockPresents.length(),
											objectId,
											logicSpeed,
											allWallBlockPresents });
			break;
		}

		default:
			break;
	}

	return gameObject;
}