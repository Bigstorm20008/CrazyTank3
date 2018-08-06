#include "DynamicObject.h"

namespace objects
{

	DynamicObject::DynamicObject(const helpers::Point& position,
		                         const wchar_t& graficsPresent,
		                         const unsigned int& health,
		                         const ObjectId& objectId,
		                         const enumerations::Direction& direction,
		                         const unsigned int& speed) :
		                         GameObject{ position, graficsPresent, health, objectId },
		                         direction_{ direction }, speed_{ speed }
	{
	}


	DynamicObject::~DynamicObject()
	{
	}


	void DynamicObject::defaultMove(const enumerations::Direction direction)
	{
		using namespace enumerations;

		direction_ = direction;

		switch (direction_)
		{
		case Direction::UP:
			position_.y -= speed_;
			break;

		case Direction::DOWN:
			position_.y += speed_;
			break;

		case Direction::LEFT:
			position_.x -= speed_;
			break;

		case Direction::RIGHT:
			position_.x += speed_;
			break;

		default:
			break;
		}
	}

}//namespace objects