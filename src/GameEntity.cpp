#include "GameEntity.h"


GameEntity::GameEntity(const std::chrono::milliseconds& logicPeriodInMilliseconds)
	: logicPeriodInMilliseconds_{ logicPeriodInMilliseconds },
	  currentTimePoint_{ std::chrono::high_resolution_clock::now() },
	  previousLogicTimePoint_{ std::chrono::high_resolution_clock::now() }
{
}


GameEntity::~GameEntity()
{
}

void GameEntity::update(World& world)
{
	currentTimePoint_ = std::chrono::high_resolution_clock::now();

	bool isTimeToLogic = std::chrono::duration_cast<std::chrono::milliseconds>(
		                 currentTimePoint_ - previousLogicTimePoint_) >=
						 logicPeriodInMilliseconds_;

	if (isTimeToLogic == true){
		doLogic(world);
		previousLogicTimePoint_ = currentTimePoint_;
	}
}
