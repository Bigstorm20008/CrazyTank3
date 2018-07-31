#include "GameObject.h"


GameObject::GameObject(const helpers::Point& position, const wchar_t& graficsPresent, const unsigned int& health)
	: position_{ position }, graficsPresent_{ graficsPresent }, health_{ health }
{
}


GameObject::~GameObject()
{
}
