#include "PauseState.h"


PauseState::PauseState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer) : GameState { eventQueue , graficsBuffer }
{
}


PauseState::~PauseState()
{
}


void PauseState::initialize()
{
	graficsBuffer_->clear();
	graficsBuffer_->drawText(Point(0, 0), Direction::RIGHT, { L"Pause state" });
}


void PauseState::processEvent(const Event& Event)
{

}


void PauseState::update()
{

}
