#include "GameState.h"


GameState::GameState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer) : eventQueue_{ &eventQueue }, graficsBuffer_{ &graficsBuffer }
{
}


GameState::~GameState()
{
}
