#ifndef STATES_CONSTANTS_H
#define STATES_CONSTANTS_H

#include <string>

namespace constants
{

	class StatesConstans
	{
	public:
		StatesConstans();
		~StatesConstans();

		const std::wstring getMainMenuTitle()const;
		const std::wstring getFirstMenuElement()const;
		const std::wstring getSecondMenuElement()const;
	};

}//namespace constants

#endif // !STATES_CONSTANTS_H



