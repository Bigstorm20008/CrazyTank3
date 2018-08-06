#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <chrono>

class World;

class GameEntity
{
public:
	GameEntity(const std::chrono::milliseconds& logicPeriodInMilliseconds);
	virtual ~GameEntity();

	void update(World& world);
private:
	const std::chrono::milliseconds logicPeriodInMilliseconds_;
	std::chrono::high_resolution_clock::time_point currentTimePoint_;
	std::chrono::high_resolution_clock::time_point previousLogicTimePoint_;

	virtual void doLogic(World& world) = 0;
};

#endif // !GAME_ENTITY_H



