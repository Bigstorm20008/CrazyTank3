#include "World.h"


World::World(const helpers::Rect& worldRect) 
	: worldRect_{ worldRect }, vectorOfEntities_{}, actor_{}
{
	vectorOfEntities_.reserve(1000);
}


World::~World()
{
	actor_.reset();
	vectorOfEntities_.clear();
}



void World::addEntity(const std::shared_ptr<objects::GameObject>& gameEntity)
{
	vectorOfEntities_.push_back(gameEntity);
}

objects::GameObject* const World::findEntityAtPoint(const helpers::Point& point) const
{
	objects::GameObject* foundedObject = nullptr;
	if (actor_.get() != nullptr){
		if (actor_->getPosition() == point){
			foundedObject = actor_.get();
		}
		else{
			auto founded = std::find_if(vectorOfEntities_.cbegin(),
				                        vectorOfEntities_.cend(),
										[&](const std::shared_ptr<objects::GameObject> gameObject){
				                        return gameObject->getPosition() == point; });
			if (founded != vectorOfEntities_.cend())
				foundedObject = founded->get();
		}
	}
	
	return foundedObject;
}


const bool World::checkEntityAtPoint(const helpers::Point& point) const
{
	const auto founded = findEntityAtPoint(point);

	return { founded != nullptr };
}

void World::updateEntities()
{
	if (actor_->getHealth() == 0){
		notify(*actor_);
	}

	auto iter = vectorOfEntities_.begin();
	
	while (iter != vectorOfEntities_.cend())
	{
		auto entity = iter->get();
		if (entity->getHealth() > 0){
			dynamic_cast<GameEntity*>(entity)->update(*this);
			++iter;
		}
		else{	
			notify(*entity);
  			iter = vectorOfEntities_.erase(iter);
		}			
	}
}


void World::drawEntities(GraficsBuffer& graficsBuffer)
{
	graficsBuffer.drawSymbol(actor_->getPosition().x,
		                     actor_->getPosition().y,
		                     actor_->getGraficsPresent());

	for (const auto& entity : vectorOfEntities_)
	{
		const auto& enttyPresent = entity.get()->getGraficsPresent();
		const auto& entityPosition = entity.get()->getPosition();
		graficsBuffer.drawSymbol(entityPosition.x, entityPosition.y, enttyPresent);
	}
}


const bool World::checkCollisionAtPoint(const helpers::Point& point)const
{
	return{ isInWorld(point) && (checkEntityAtPoint(point) == false) };
}


const bool World::isInWorld(const helpers::Point& point)const
{
	const bool isInWorld = point.x >= worldRect_.left &&
		                   point.x <= worldRect_.right &&
		                   point.y >= worldRect_.top &&
		                   point.y <= worldRect_.bottom;

	return isInWorld;
}


void World::addActor(const std::shared_ptr<objects::GameObject> actor)
{
	actor_ = actor;
}


void World::processEvent(const enumerations::Event& currentEvent)
{
	dynamic_cast<Actor*>(actor_.get())->processEvent(currentEvent, *this);
}

objects::GameObject* findFirstObjectOnWay(const World& world,
	                                      const enumerations::Direction& searchDirection,
	                                      const helpers::Point& startSearchPoint)
{
	using namespace enumerations;
	using namespace helpers;

	objects::GameObject* foundedObject = nullptr;

	Point pointToCheck = getNextPoint(startSearchPoint, searchDirection, 1);

	while ((world.isInWorld(pointToCheck) == true) && (foundedObject == nullptr))
	{
		foundedObject = world.findEntityAtPoint(pointToCheck);
		pointToCheck = getNextPoint(pointToCheck, searchDirection, 1);
	}
	
	return foundedObject;
}

const helpers::Point World::getRandomFreePointInWorld()const
{
	helpers::RandomEngine* engineInstance = nullptr;
	const auto randomEngine = engineInstance->getInstance();

	unsigned int x = randomEngine->getRandomInteger(worldRect_.left, worldRect_.right);
	unsigned int y = randomEngine->getRandomInteger(worldRect_.top, worldRect_.bottom);

	while (checkCollisionAtPoint(helpers::Point( x, y )) == false)
	{
		x = randomEngine->getRandomInteger(worldRect_.left, worldRect_.right);
		y = randomEngine->getRandomInteger(worldRect_.top, worldRect_.bottom);
	}

	return std::move(helpers::Point( x, y ));
}


const objects::GameObject* const
World::findObjectInRectbyId(const objects::ObjectId& objectId,
                            const helpers::Rect rect) const
{
	helpers::Rect refinedRect = rect;

	if (refinedRect.left < worldRect_.left)
		refinedRect.left = worldRect_.left;

	if (refinedRect.right > worldRect_.right)
		refinedRect.right = worldRect_.right; 

	if (refinedRect.top < worldRect_.top)
		refinedRect.top = worldRect_.top;

	if (refinedRect.bottom > worldRect_.bottom)
		refinedRect.bottom = worldRect_.bottom;

	const objects::GameObject* foundedObject = nullptr;

	for (int y = refinedRect.top; y <= refinedRect.bottom; ++y){
		for (int x = refinedRect.left; x <= refinedRect.right; ++x){
			const objects::GameObject* const objectInPoint = findEntityAtPoint(helpers::Point(x, y));
			if (objectInPoint != nullptr){
				if (objectInPoint->getId() == objectId){
					foundedObject = objectInPoint;
					break;
				}
			}
		}
	}

	return foundedObject;
}