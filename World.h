#ifndef WORLD_H
#define WORLD_H

#include <map>
#include <vector>
#include <memory>
#include <algorithm>


#include "GraficsBuffer.h"
#include "Rect.h"
#include "GameObject.h"
#include "GameEntity.h"


class World
{
public:
	World(const helpers::Rect& worldRect);
	~World();

	const bool storeEntity(const std::shared_ptr<GameObject>& gameObject);
	GameObject* findEntityAtPoint(const helpers::Point& point) const;
	
	const bool checkCollisionAtPoint(const helpers::Point& point)const;

	void updateEntities();
	void drawEntities(GraficsBuffer& graficsBuffer);

private:
	helpers::Rect worldRect_;
	//std::map<helpers::Point, std::shared_ptr<GameObject>> mapOfEntities_;
	std::vector<std::shared_ptr<GameObject>> vectorOfEntities_;

	const bool checkBordersAtPoint(const helpers::Point& point)const;
	const bool checkEntityAtPoint(const helpers::Point& point) const;

};

#endif // !WORLD_H



