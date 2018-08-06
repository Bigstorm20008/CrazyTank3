#ifndef WORLD_H
#define WORLD_H

#include <map>
#include <vector>
#include <memory>
#include <algorithm>

#include "ObservableWorld.h"
#include "GraficsBuffer.h"
#include "Rect.h"
#include "GameObject.h"
#include "GameEntity.h"
#include "Actor.h"
#include "RandomEngine.h"



class World : public ObservableWorld
{
public:
	World(const helpers::Rect& worldRect);
	~World();

	void addActor(const std::shared_ptr<objects::GameObject> actor);
	void addEntity(const std::shared_ptr<objects::GameObject>& gameObject);
	objects::GameObject* const findEntityAtPoint(const helpers::Point& point) const;
	
	const bool checkCollisionAtPoint(const helpers::Point& point)const;

	void updateEntities();
	void drawEntities(GraficsBuffer& graficsBuffer);

	const bool isInWorld(const helpers::Point& point)const;

	void processEvent(const enumerations::Event& currentEvent);

	const helpers::Point getRandomFreePointInWorld() const;

	const objects::GameObject* const
	findObjectInRectbyId(const objects::ObjectId& objectId,
		                 const helpers::Rect rect) const;
private:
	helpers::Rect worldRect_;
	std::shared_ptr<objects::GameObject> actor_;
	//std::map<helpers::Point, std::shared_ptr<GameObject>> mapOfEntities_;
	std::vector<std::shared_ptr<objects::GameObject>> vectorOfEntities_;
	
	const bool checkEntityAtPoint(const helpers::Point& point) const;

	 
	

};

objects::GameObject* findFirstObjectOnWay(const World& world,
	                                      const enumerations::Direction& searchDirection,
								          const helpers::Point& startSearchPoint);



#endif // !WORLD_H



