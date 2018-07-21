#include "GameState.h"

namespace gamestates
{

	GameState::GameState(EventQueue& eventQueue, GraficsBuffer& graficsBuffer) : eventQueue_{ &eventQueue }, graficsBuffer_{ &graficsBuffer }
	{
	}


	GameState::~GameState()
	{
	}

}//namespace gamestates
