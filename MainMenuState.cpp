#include "MainMenuState.h"


MainMenuState::MainMenuState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer) : GameState { eventQueue , graficsBuffer }
{
}


MainMenuState::~MainMenuState()
{
}


void MainMenuState::processEvent(const events::GameEvent& gameEvent)
{
	const Event eventId = gameEvent.getId();

	switch (eventId)
	{
	case Event::UP_ARROW_KEY_PRESSED :
	{
		--startPos_.y;
		break;
	}

	case Event::SPACE_KEY_PRESSED :
	{
		++startPos_.y;
		break;
	}

	default:
		break;
	}
}


void MainMenuState::update()
{
	graficsBuffer_->clear();
	graficsBuffer_->drawText(startPos_, Direction::RIGHT, { L"text" });
}


void MainMenuState::initialize()
{
	startPos_.x = 5;
	startPos_.y = 5;
	//graficsBuffer_->drawText(Point(5, 5), Direction::RIGHT, { L"text" });
}
