#ifndef ENTITY_STORE_H
#define ENTITY_STORE_H

#include <map>
#include <vector>
#include <memory>

#include "GameEntity.h"

class EntityStore
{
public:
	EntityStore();
	~EntityStore();

	const bool storeEntity(const std::shared_ptr<entities::GameEntity>& gameEntity);
	std::weak_ptr<entities::GameEntity> findEntityAtPoint(const helpers::Point& point) const;
	const bool checkEntityAtPoint(const helpers::Point& point) const;

	void updateEntities();
private:
	std::map<helpers::Point, std::shared_ptr<entities::GameEntity>> mapOfEntities_;
	std::vector<std::weak_ptr<entities::GameEntity>> vectorOfEntities_;
};

#endif // !ENTITY_STORE_H



