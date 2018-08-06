#ifndef OBJECTS_CONSTANTS_H
#define OBJECTS_CONSTANTS_H

#include <chrono>
#include <string>

namespace constants
{

	class ObjectsConstants
	{
	public:
		ObjectsConstants();
		~ObjectsConstants();

		unsigned int getDefaultTankHealth();
		unsigned int getDefaultObjectSpeed();

		wchar_t getDefaultPlaerTankPresents();
		std::chrono::milliseconds getPlayerTankReloadingTime();

		wchar_t getDefaultEnemyTankPresent();
		std::chrono::milliseconds getEnemyTankReloadingTime();
		std::chrono::milliseconds getEnemyTankLogicSpeed();

		std::wstring getDefaultWallBlockPresents();

		std::wstring getDefaultStrongholdBlocksPresents();

	};

}//namespace constants

#endif // !OBJECTS_CONSTANTS_H



