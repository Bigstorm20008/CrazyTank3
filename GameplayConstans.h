#ifndef GAMEPLAY_CONSTANTS_H
#define GAMEPLAY_CONSTANTS_H

#include <string>

class GameplayConstans
{
public:
	GameplayConstans();
	~GameplayConstans();

	const std::wstring getMainMenuTitle()const;
	const std::wstring getFirstMenuElement()const;
	const std::wstring getSecondMenuElement()const;
};

#endif // !GAMEPLAY_CONSTANTS_H



