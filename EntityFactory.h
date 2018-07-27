#ifndef ENTITY_FACTORY_H
#define ENTTY_FACTORY_H

#include <memory>

#include "EntitiesId.h"
#include "GameEntity.h"
#include "PlayerTank.h"

namespace factories
{

	class EntityFactory
	{
	public:
		EntityFactory();
		virtual ~EntityFactory();

		std::shared_ptr<entities::GameEntity> createEntity(const enumerations::EntityId& entityId,
			                                               const helpers::Point& position);
	};

}//namespace factories

#endif // !ENTITY_FACTORY_H



