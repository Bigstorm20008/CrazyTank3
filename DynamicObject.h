#ifndef DYNAMIC_OBJECT_H
#define DYNAMIC_OBJECT_H

#include "GameObject.h"
#include "Direction.h"

namespace objects
{

	class DynamicObject : public GameObject
	{
	public:
		DynamicObject(const helpers::Point& position,
			          const wchar_t& graficsPresent,
			          const unsigned int& health,
			          const ObjectId& objectId,
			          const enumerations::Direction& direction,
			          const unsigned int& speed);

		virtual ~DynamicObject();

		virtual void move(const enumerations::Direction direction) = 0;

	protected:
		void defaultMove(const enumerations::Direction direction);

		enumerations::Direction direction_;
		unsigned int speed_;
	};

}//namespace objects

#endif // !DYNAMIC_OBJECT_H



