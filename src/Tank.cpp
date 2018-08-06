#include "Tank.h"


Tank::Tank(const std::chrono::milliseconds& reloadTimeInMilliseconds)
	          : reloadTimeInMilliseconds_{ reloadTimeInMilliseconds },
	            currentTimePoint_{ std::chrono::high_resolution_clock::now() },
	            shootTimePoint_{ std::chrono::high_resolution_clock::now() }
{
}


Tank::~Tank()
{
}

const bool Tank::isReadyToFire()
{
	currentTimePoint_ = std::chrono::high_resolution_clock::now();
	bool isReady = std::chrono::duration_cast<std::chrono::milliseconds>(currentTimePoint_ - shootTimePoint_) >= reloadTimeInMilliseconds_;

	return isReady;
}


void Tank::reloading()
{
	shootTimePoint_ = std::chrono::high_resolution_clock::now();
}
