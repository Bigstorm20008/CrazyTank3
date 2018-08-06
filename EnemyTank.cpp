#include "EnemyTank.h"

namespace objects
{

	EnemyTank::EnemyTank(const helpers::Point& position,
		const wchar_t& graficsPresent,
		const unsigned int& health,
		const ObjectId& objectId,
		const enumerations::Direction& direction,
		const unsigned int& speed,
		const std::chrono::milliseconds& reloadTimeInMillseconds,
		const std::chrono::milliseconds& logicPeriodInMilliseconds) :
		GameEntity{ logicPeriodInMilliseconds },
		DynamicObject{ position, graficsPresent, health, objectId, direction, speed },
		Tank{ reloadTimeInMillseconds }
	{
	}


	EnemyTank::~EnemyTank()
	{
	}


	void EnemyTank::move(const enumerations::Direction direction)
	{
		defaultMove(direction);
	}


	void EnemyTank::fire(World& world)
	{
		using namespace helpers;
		using namespace enumerations;

		Point firstBulletPosition = getNextPoint(position_, direction_, 1);


		if (isReadyToFire() == true){
			if (world.checkCollisionAtPoint(firstBulletPosition) == true){
				std::chrono::milliseconds bulletLogicSpeed{ 15 };

				const auto bullet = std::make_shared<Bullet>(firstBulletPosition,
					'*',
					1,
					ObjectId::ENEMY_BULLET,
					direction_,
					1,
					bulletLogicSpeed);
				world.storeEntity(bullet);
				reloading();
			}
			else{
				GameObject* const objectInPoint = world.findEntityAtPoint(firstBulletPosition);
				if (objectInPoint != nullptr)
					objectInPoint->decreaseHealth();
			}
		}

	}



	void EnemyTank::doLogic(World& world)
	{
		const GameObject* const foundedTarget = findTargets(world);

		if (foundedTarget != nullptr){
			direction_ = computeDirectionToTarget(*foundedTarget);
			fire(world);
		}
		else{
			doMovementLogic(world);
		}
	}

	void EnemyTank::doMovementLogic(const World& world)
	{
		using namespace helpers;
		using namespace enumerations;

		Point nextPosition = getNextPoint(position_, direction_, speed_);



		if (world.checkCollisionAtPoint(nextPosition) == true)
			move(direction_);
		else{
			RandomEngine* engine = nullptr;
			auto randomGenerator = engine->getInstance();

			size_t directionCount = sizeof(Direction);

			std::vector<Direction> checkedDirections;
			checkedDirections.reserve(directionCount);
			checkedDirections.push_back(direction_);

			bool directionFound = false;

			while (checkedDirections.size() <= directionCount)
			{
				Direction directionToCheck;
				bool isDirectionChecked = true;

				while (isDirectionChecked == true)
				{
					directionToCheck = static_cast<Direction>(randomGenerator->getRandomInteger(0, directionCount));

					auto result = std::find_if(checkedDirections.cbegin(), checkedDirections.cend(),
						[&](const Direction& direction){
						return direction == directionToCheck; });

					if (result == checkedDirections.cend())
						isDirectionChecked = false;
				}

				Point nextPosition = getNextPoint(position_, directionToCheck, speed_);
				if (world.checkCollisionAtPoint(nextPosition) == true){
					move(directionToCheck);
					directionFound = true;
					break;
				}
				else{
					checkedDirections.push_back(directionToCheck);
				}

			}
		}
	}


	const GameObject* const EnemyTank::findTargets(const World& world) const
	{
		using namespace helpers;
		using namespace enumerations;

		GameObject* foundedObject = nullptr;

		size_t directionCount = sizeof(Direction);

		for (int direction = 0; direction < directionCount; ++direction)
		{
			foundedObject = findFirstObjectOnWay(world, static_cast<Direction>(direction), position_);
			if (foundedObject != nullptr)
			{
				if ((foundedObject->getId() == ObjectId::PLAYER_TANK))
					break;
				else
					foundedObject = nullptr;
			}
		}

		return foundedObject;
	}


	const enumerations::Direction EnemyTank::computeDirectionToTarget(const GameObject& target) const
	{
		using namespace helpers;
		using namespace enumerations;

		const Point targetPosition = target.getPosition();

		Direction foundedDirection;

		if (this->position_.x == targetPosition.x){
			if (this->position_.y < targetPosition.y)
				foundedDirection = Direction::DOWN;
			else
				foundedDirection = Direction::UP;
		}
		else{
			if (this->position_.y == targetPosition.y){
				if (this->position_.x < targetPosition.x)
					foundedDirection = Direction::RIGHT;
				else
					foundedDirection = Direction::LEFT;
			}
		}

		return foundedDirection;
	}

}//namespace objects