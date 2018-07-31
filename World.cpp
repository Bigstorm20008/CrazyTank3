#include "World.h"


World::World(const helpers::Rect& worldRect) 
	: worldRect_{ worldRect }, vectorOfEntities_{}
{
}


World::~World()
{
	
	vectorOfEntities_.clear();
}



const bool World::storeEntity(const std::shared_ptr<GameObject>& gameEntity)
{
	std::pair<helpers::Point, std::shared_ptr<GameObject>> entityToStore;
	entityToStore.second = gameEntity;
	entityToStore.first = gameEntity->getPosition();

	//const auto result = mapOfEntities_.insert(std::move(entityToStore));

	
	
	vectorOfEntities_.push_back(gameEntity);
	
	

	return true;
}

GameObject* World::findEntityAtPoint(const helpers::Point& point) const
{
	auto founded = std::find_if(vectorOfEntities_.cbegin(), vectorOfEntities_.cend(), [&](const std::shared_ptr<GameObject> gameObject){return gameObject->getPosition() == point; });

	if (founded != vectorOfEntities_.cend())
		return founded->get();
	else
		return nullptr;
}


const bool World::checkEntityAtPoint(const helpers::Point& point) const
{
	const auto founded = findEntityAtPoint(point);

	return { founded != nullptr };
}

void World::updateEntities()
{
	auto iter = vectorOfEntities_.begin();
	
	while (iter != vectorOfEntities_.end())
	{
		auto entity = iter->get();
		if (entity->getHealth() != 0){
			dynamic_cast<GameEntity*>(entity)->update(*this);
			++iter;
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
		const auto& enttyPresent = entity.get()->getGraficsPresent();
		const auto& entityPosition = entity.get()->getPosition();
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