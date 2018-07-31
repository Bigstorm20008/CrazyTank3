#include "PlayerTank.h"


PlayerTank::PlayerTank(const helpers::Point& position,
	                   const wchar_t& graficsPresent,
	                   const unsigned int& health,
	                   const enumerations::Direction& direction,
					   const unsigned int& speed,
					   const std::chrono::milliseconds& reloadTimeInMillseconds) :
					   DynamicObject{ position, graficsPresent, health, direction, speed },
					   Tank{ reloadTimeInMillseconds }
{
}


PlayerTank::~PlayerTank()
{
}


void PlayerTank::processEvent(const enumerations::Event& currentEvent, World& world)
{
	using namespace enumerations;
	using namespace helpers;

	switch (currentEvent)
	{
		case Event::DOWN_ARROW_KEY_PRESSED :
			if(world.checkCollisionAtPoint(Point(position_.x, position_.y + 1)))
				move(Direction::DOWN);
			break;

		case Event::UP_ARROW_KEY_PRESSED :
			if (world.checkCollisionAtPoint(Point(position_.x, position_.y - 1)))
				move(Direction::UP);
			break;

		case Event::LEFT_ARROW_KEY_PRESSED :
			if (world.checkCollisionAtPoint(Point(position_.x - 1, position_.y)))
				move(Direction::LEFT);
			break;

		case Event::RIGHT_ARROW_KEY_PRESSED :
			if (world.checkCollisionAtPoint(Point(position_.x + 1, position_.y)))
				move(Direction::RIGHT);
			break;

		case Event::SPACE_KEY_PRESSED :
			fire(world);
			break;

		default:
			break;
	}
}


void PlayerTank::move(const enumerations::Direction direction)
{
	defaultMove(direction);
}


void PlayerTank::fire(World& world)
{
	using namespace helpers;

	Point firstBulletPosition = position_;

	switch (direction_)
	{
		case enumerations::Direction::UP:
			--firstBulletPosition.y;
			break;

		case enumerations::Direction::DOWN:
			++firstBulletPosition.y;
			break;

		case enumerations::Direction::LEFT:
			--firstBulletPosition.x;
			break;

		case enumerations::Direction::RIGHT:
			++firstBulletPosition.x;
			break;

		default:
			break;
	}

	if ((isReadyToFire() == true) && (world.checkCollisionAtPoint(firstBulletPosition) == true)){
		const auto bullet = std::make_shared<Bullet>(firstBulletPosition, '*', 1, direction_, 1);
		world.storeEntity(bullet);	
		reloading();
	}
}
