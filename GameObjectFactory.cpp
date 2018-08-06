#include "GameObjectFactory.h"


GameObjectFactory::GameObjectFactory()
{
}


GameObjectFactory::~GameObjectFactory()
{
}


std::shared_ptr<objects::GameObject> GameObjectFactory::createGameObject(const helpers::Point& objectPosition, const objects::ObjectId& objectId)
{
	using namespace objects;
	std::shared_ptr<GameObject> gameObject{};

	switch (objectId)
	{
		case ObjectId::ENEMY_BULLET:
		{
			std::chrono::milliseconds bulletLogicSpeed{ 15 };
			gameObject.reset(new Bullet{ objectPosition, { '*' }, 1, objectId, { enumerations::Direction::UP }, 1, bulletLogicSpeed });
			break;
		}

		case ObjectId::ENEMY_TANK:
		{
			helpers::RandomEngine* engineInstance = nullptr;
			const auto randomEngine = engineInstance->getInstance();
			std::chrono::milliseconds reloadingTime = static_cast<std::chrono::milliseconds>(randomEngine->getRandomInteger(500, 800));
			std::chrono::milliseconds enemyLogicSpeed{ 150 };
			gameObject.reset(new EnemyTank{ objectPosition, 'S', 3, objectId, { enumerations::Direction::UP }, 1, reloadingTime, enemyLogicSpeed });
			break;
		}

		case ObjectId::PLAYER_BULLET:
		{
			std::chrono::milliseconds bulletLogicSpeed{ 15 };
			gameObject.reset(new Bullet{ objectPosition, { '*' }, 1, objectId, { enumerations::Direction::UP }, 1, bulletLogicSpeed });
			break;
		}

		case ObjectId::PLAYER_TANK:
		{
			
			std::chrono::milliseconds reloadingTime(200);
			gameObject.reset(new PlayerTank{ objectPosition, { 'T' }, 3, objectId, { enumerations::Direction::UP }, 1, reloadingTime });
			break;
		}

		case ObjectId::WALL_BLOCK:
		{
			std::wstring allWallBlockPresents = { L"XKI" };
			std::chrono::milliseconds logicSpeed{ 0 };
			gameObject.reset(new WallBlock{ objectPosition, allWallBlockPresents.at(0), allWallBlockPresents.length(), objectId, logicSpeed, allWallBlockPresents });
			break;
		}

		case ObjectId::STRONGHOLD_BLOCK:
		{
			std::wstring allWallBlockPresents = { L"HTL" };
			std::chrono::milliseconds logicSpeed{ 0 };
			gameObject.reset(new WallBlock{ objectPosition, allWallBlockPresents.at(0), allWallBlockPresents.length(), objectId, logicSpeed, allWallBlockPresents });
			break;
		}

		default:
			break;
	}

	return gameObject;
}