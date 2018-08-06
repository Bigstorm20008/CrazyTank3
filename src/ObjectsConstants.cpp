#include "ObjectsConstants.h"

namespace constants
{

	ObjectsConstants::ObjectsConstants()
	{
	}


	ObjectsConstants::~ObjectsConstants()
	{
	}


	unsigned int ObjectsConstants::getDefaultTankHealth()
	{
		return { 3 };
	}


	wchar_t ObjectsConstants::getDefaultPlaerTankPresents()
	{
		return { 'T' };
	}


	unsigned int ObjectsConstants::getDefaultObjectSpeed()
	{
		return { 1 };
	}


	std::chrono::milliseconds ObjectsConstants::getPlayerTankReloadingTime()
	{
		return std::chrono::milliseconds{ 200 };
	}


	wchar_t ObjectsConstants::getDefaultEnemyTankPresent()
	{
		return{ 'S' };
	}


	std::chrono::milliseconds ObjectsConstants::getEnemyTankReloadingTime()
	{
		return std::chrono::milliseconds{ 800 };
	}


	std::chrono::milliseconds ObjectsConstants::getEnemyTankLogicSpeed()
	{
		return std::chrono::milliseconds{ 150 };
	}


	std::wstring ObjectsConstants::getDefaultWallBlockPresents()
	{
		return { L"XKI" };
	}

	std::wstring ObjectsConstants::getDefaultStrongholdBlocksPresents()
	{
		return{ L"HTL" };
	}

}