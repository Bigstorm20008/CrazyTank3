#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "GameState.h"

class MainMenuState : public GameState
{
public:
	MainMenuState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer);
	~MainMenuState();

	void initialize() override;
	void processEvent(const events::GameEvent& gameEvent) override;
	void update() override;

private:
	Point startPos_;
};


#endif // !MAIN_MENU_STATE_H



