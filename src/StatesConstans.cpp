#include "StatesConstans.h"

namespace constants
{

	StatesConstans::StatesConstans()
	{
	}


	StatesConstans::~StatesConstans()
	{
	}


	const std::wstring StatesConstans::getMainMenuTitle()const
	{
		return{ L"Main Menu" };
	}


	const std::wstring StatesConstans::getFirstMenuElement()const
	{
		return{ L"Press S key to start" };
	}


	const std::wstring StatesConstans::getSecondMenuElement()const
	{
		return{ L"Press Q key to exit" };
	}

}//namespace constants