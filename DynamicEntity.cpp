#include "DynamicEntity.h"

namespace entities
{

	DynamicEntity::DynamicEntity(const helpers::Point& position,
		                         const wchar_t& graficsPresent,
								 const unsigned int& health,
								 const enumerations::Direction& direction)
		: entities::GameEntity{ position, graficsPresent,health }, direction_(direction)
	{
	}


	DynamicEntity::~DynamicEntity()
	{
	}


	void DynamicEntity::move(const enumerations::Direction& direction)
	{
		using namespace enumerations;
		using namespace helpers;

		direction_ = direction;

		switch (direction)
		{
		case Direction::UP:
			--position_.y;
			break;

		case Direction::DOWN:
			++position_.y;
			break;

		case Direction::LEFT:
			--position_.x;
			break;

		case Direction::RIGHT:
			++position_.x;
			break;

		default:
			break;
		}

	}



}//namespase entities
