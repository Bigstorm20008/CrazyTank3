#include "GameObject.h"

namespace objects
{

	GameObject::GameObject(const helpers::Point& position,
		const wchar_t& graficsPresent,
		const unsigned int& health,
		const ObjectId& objectId) :
		position_{ position },
		graficsPresent_{ graficsPresent },
		health_{ health },
		objectId_{ objectId }
	{
	}


	GameObject::~GameObject()
	{
	}

}//namespace objects