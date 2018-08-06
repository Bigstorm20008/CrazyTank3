#ifndef BULLET_H
#define BULLET_H


#include "DynamicObject.h"
#include "GameEntity.h"
#include "World.h"


namespace objects
{

	class Bullet :
		public DynamicObject, public GameEntity
	{
	public:
		Bullet(const helpers::Point& position,
			   const wchar_t& graficsPresent,
			   const unsigned int& health,
			   const ObjectId& objectId,
			   const enumerations::Direction& direction,
			   const unsigned int& speed,
			   const std::chrono::milliseconds& logicPeriodInMilliseconds);

		virtual ~Bullet();

		void move(const enumerations::Direction direction) override;


	private:
		void doLogic(World& world) override;
		void doDamage(GameObject& object);
	};

}//namespace objects
#endif // !BULLET_H



