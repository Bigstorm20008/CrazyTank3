#include "GameRunnigState.h"


GameRunnigState::GameRunnigState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer) 
	: GameState {eventQueue, graficsBuffer}
{
}


GameRunnigState::~GameRunnigState()
{
}


void GameRunnigState::initialize()
{
	graficsBuffer_->clear();
	graficsBuffer_->drawText(Point(0, 0), Direction::RIGHT, { L"Running state" });
}


void GameRunnigState::processEvent(const Event& Event)
{

}


void GameRunnigState::update()
{

}
