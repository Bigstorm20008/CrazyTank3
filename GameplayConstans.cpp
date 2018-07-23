#include "GameplayConstans.h"

namespace constants
{

	GameplayConstans::GameplayConstans()
	{
	}


	GameplayConstans::~GameplayConstans()
	{
	}


	const std::wstring GameplayConstans::getMainMenuTitle()const
	{
		return{ L"Main Menu" };
	}


	const std::wstring GameplayConstans::getFirstMenuElement()const
	{
		return{ L"Press S key to start" };
	}


	const std::wstring GameplayConstans::getSecondMenuElement()const
	{
		return{ L"Press Q key to exit" };
	}

}//namespace constants