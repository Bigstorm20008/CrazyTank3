#include "World.h"


World::World(const helpers::Rect& worldRect) : worldRect_{ worldRect }, mapOfEntities_{}, vectorOfEntities_{}
{
}


World::~World()
{
	mapOfEntities_.clear();
	vectorOfEntities_.clear();
}



const bool World::storeEntity(const std::shared_ptr<entities::GameEntity>& gameEntity)
{
	std::pair<helpers::Point, std::shared_ptr<entities::GameEntity>> entityToStore;
	entityToStore.second = gameEntity;
	entityToStore.first = gameEntity->getPosition();

	const auto result = mapOfEntities_.insert(std::move(entityToStore));

	if (result.second == true)
	{
		vectorOfEntities_.push_back(gameEntity);
	}
	

	return result.second;
}

std::weak_ptr<entities::GameEntity> World::findEntityAtPoint(const helpers::Point& point) const
{
	return mapOfEntities_.find(point)->second;
}


const bool World::checkEntityAtPoint(const helpers::Point& point) const
{
	const auto founded = mapOfEntities_.find(point);

	return { founded != mapOfEntities_.cend() };
}

void World::updateEntities()
{
	auto& iter = vectorOfEntities_.begin();
	const auto& lastIter = vectorOfEntities_.cend();

	while (iter != lastIter)
	{
		if (iter->expired() == false){

			auto entity = iter->lock().get();

			if (entity->getHealth() != 0){
				entity->update(*this);
				++iter;
			}
			else{
				mapOfEntities_.erase(entity->getPosition());
				iter = vectorOfEntities_.erase(iter);
			}			
		}
		else{
			iter = vectorOfEntities_.erase(iter);
		}
	}
}


void World::drawEntities(GraficsBuffer& graficsBuffer)
{
	for (const auto& entity : vectorOfEntities_)
	{
		const auto& enttyPresent = entity.lock().get()->getGraficsPresent();
		const auto& entityPosition = entity.lock().get()->getPosition();
		graficsBuffer.drawSymbol(entityPosition.x, entityPosition.y, enttyPresent);
	}
}


const bool World::checkCollisionAtPoint(const helpers::Point& point)const
{
	return { checkBordersAtPoint(point) && (checkEntityAtPoint(point) == false) };
}


const bool World::checkBordersAtPoint(const helpers::Point& point)const
{
	const bool isInWorld = point.x >= worldRect_.left &&
		                   point.x <= worldRect_.right &&
		                   point.y >= worldRect_.top &&
		                   point.y <= worldRect_.bottom;

	return isInWorld;
}