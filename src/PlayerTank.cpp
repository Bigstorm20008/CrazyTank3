#include "PlayerTank.h"

namespace objects
{
	PlayerTank::PlayerTank(const helpers::Point& position,
		                   const wchar_t& graficsPresent,
		                   const unsigned int& health,
		                   const ObjectId& objectId,
		                   const enumerations::Direction& direction,
		                   const unsigned int& speed,
		                   const std::chrono::milliseconds& reloadTimeInMillseconds) :
		                   DynamicObject{ position, graficsPresent, health, objectId, direction, speed },
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
		case Event::DOWN_ARROW_KEY_PRESSED:
			direction_ = Direction::DOWN;
			if (world.checkCollisionAtPoint(Point(position_.x, position_.y + 1)))
				move(Direction::DOWN);
			break;

		case Event::UP_ARROW_KEY_PRESSED:
			direction_ = Direction::UP;
			if (world.checkCollisionAtPoint(Point(position_.x, position_.y - 1)))
				move(Direction::UP);
			break;

		case Event::LEFT_ARROW_KEY_PRESSED:
			direction_ = Direction::LEFT;
			if (world.checkCollisionAtPoint(Point(position_.x - 1, position_.y)))
				move(Direction::LEFT);
			break;

		case Event::RIGHT_ARROW_KEY_PRESSED:
			direction_ = Direction::RIGHT;
			if (world.checkCollisionAtPoint(Point(position_.x + 1, position_.y)))
				move(Direction::RIGHT);
			break;

		case Event::SPACE_KEY_PRESSED:
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

		Point firstBulletPosition = getNextPoint(position_, direction_, 1);

		if ((isReadyToFire() == true) && (world.checkCollisionAtPoint(firstBulletPosition) == true)){
			std::chrono::milliseconds bulletLogicSpeed{ 15 };

			const auto bullet = std::make_shared<Bullet>(firstBulletPosition,
				                                        '*',
				                                         1,
				                                         ObjectId::PLAYER_BULLET,
				                                         direction_,
				                                         1,
				                                         bulletLogicSpeed);
			world.addEntity(bullet);
			reloading();
		}
	}

}