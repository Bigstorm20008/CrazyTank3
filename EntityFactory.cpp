#include "EntityFactory.h"

namespace factories
{

	EntityFactory::EntityFactory()
	{
	}


	EntityFactory::~EntityFactory()
	{
	}


	std::shared_ptr<entities::GameEntity>
	EntityFactory::createEntity(const enumerations::EntityId& entityId,
		                        const helpers::Point& position)
	{
		using namespace enumerations;

		std::shared_ptr<entities::GameEntity> gameEntity{};
		switch (entityId)
		{
			case EntityId::PLAYER_TANK:
				gameEntity.reset(new entities::PlayerTank(position, 'T', 3, Direction::UP));
				break;

			case EntityId::ENEMY_TANK:
				break;

			default:
				break;
		}

		return std::move(gameEntity);
	}

}//namespace factories
