#include "EntityStore.h"


EntityStore::EntityStore()
{
}


EntityStore::~EntityStore()
{
	mapOfEntities_.clear();
}



const bool EntityStore::storeEntity(const std::shared_ptr<entities::GameEntity>& gameEntity)
{
	std::pair<helpers::Point, std::shared_ptr<entities::GameEntity>> entityToStore;
	entityToStore.second = gameEntity;
	entityToStore.first = gameEntity->getPosition();

	const auto result = mapOfEntities_.insert(std::move(entityToStore));
	if (result.second == true)
	{
		vectorOfEntities_.push_back(std::move(gameEntity));
	}
	

	return result.second;
}

std::weak_ptr<entities::GameEntity> EntityStore::findEntityAtPoint(const helpers::Point& point) const
{
	return mapOfEntities_.find(point)->second;
}


const bool EntityStore::checkEntityAtPoint(const helpers::Point& point) const
{
	auto founded = mapOfEntities_.find(point);

	return { founded != mapOfEntities_.cend() };
}

void EntityStore::updateEntities()
{
	auto& iter = vectorOfEntities_.begin();
	auto& lastIter = vectorOfEntities_.end();

	while (iter != lastIter)
	{
		if (iter->expired() == false)
		{
			iter->lock().get()->update();
			++iter;
		}
		else{
			iter = vectorOfEntities_.erase(iter);
		}
	}
}