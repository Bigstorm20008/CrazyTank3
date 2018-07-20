#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "GameState.h"
#include "GameplayConstans.h"

class MainMenuState : public GameState
{
public:
	MainMenuState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer);
	~MainMenuState();

	void initialize() override;
	void processEvent(const Event& event) override;
	void update() override;
};


#endif // !MAIN_MENU_STATE_H



