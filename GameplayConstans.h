#ifndef GAMEPLAY_CONSTANTS_H
#define GAMEPLAY_CONSTANTS_H

#include <string>

namespace constants
{

	class GameplayConstans
	{
	public:
		GameplayConstans();
		~GameplayConstans();

		const std::wstring getMainMenuTitle()const;
		const std::wstring getFirstMenuElement()const;
		const std::wstring getSecondMenuElement()const;
	};

}//namespace constants

#endif // !GAMEPLAY_CONSTANTS_H



