#ifndef TANK_H
#define TANK_H

#include <chrono>

class World;

class Tank
{
public:
	Tank(const std::chrono::milliseconds& reloadTimeInMilliseconds);
	virtual ~Tank();

	virtual void fire(World& world) = 0;
	const bool isReadyToFire();
	void reloading();
private:
	std::chrono::milliseconds reloadTimeInMilliseconds_;
	std::chrono::high_resolution_clock::time_point currentTimePoint_;
	std::chrono::high_resolution_clock::time_point shootTimePoint_;
};

#endif // !TANK_H



