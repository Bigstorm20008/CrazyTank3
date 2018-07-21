#include "PauseState.h"

namespace gamestates
{

	PauseState::PauseState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer) : GameState{ eventQueue, graficsBuffer }
	{
	}


	PauseState::~PauseState()
	{
	}


	void PauseState::initialize()
	{
		graficsBuffer_->clear();
		graficsBuffer_->drawText(helpers::Point(0, 0), enumarations::Direction::RIGHT, { L"Pause state" });
	}


	void PauseState::processEvent(const enumarations::Event& Event)
	{

	}


	void PauseState::update()
	{

	}

}//namespace gamestates
