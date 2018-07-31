#ifndef BULLET_H
#define BULLET_H

#include "DynamicObject.h"
#include "GameEntity.h"
#include "World.h"

class Bullet :
	public DynamicObject, public GameEntity
{
public:
	Bullet(const helpers::Point& position,
		   const wchar_t& graficsPresent,
		   const unsigned int& health,
		   const enumerations::Direction& direction,
		   const unsigned int& speed);

	virtual ~Bullet();

	void move(const enumerations::Direction direction) override;
	void update(const World& world) override;
};

#endif // !BULLET_H



