#include "EnemyTank.h"


EnemyTank::EnemyTank(const helpers::Point& position,
	                 const wchar_t& graficsPresent,
	                 const unsigned int& health,
	                 const enumerations::Direction& direction,
	                 const unsigned int& speed,
					 const std::chrono::milliseconds& reloadTimeInMillseconds) :
					 DynamicObject{ position, graficsPresent, health, direction, speed },
					 Tank{ reloadTimeInMillseconds }
{
}


EnemyTank::~EnemyTank()
{
}


void EnemyTank::update(const World& world)
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
				auto result = std::find_if(checkedDirections.cbegin(), checkedDirections.cend(), [&](const Direction& direction){ return direction == directionToCheck; });

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


void EnemyTank::move(const enumerations::Direction direction)
{
	defaultMove(direction);
}


void EnemyTank::fire(World& world)
{

}
