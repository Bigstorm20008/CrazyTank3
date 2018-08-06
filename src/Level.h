#ifndef LEVEL_H
#define LEVEL_H
#include <Windows.h>

#include "EventQueue.h"
#include "WorldObserver.h"
#include "World.h"
#include "GameTimer.h"
#include "GameObjectFactory.h"
#include "WallCreator.h"

class Level : public WorldObserver
{
public:
	Level(EventQueue* const eventQueue_);
	virtual ~Level();

	void initialize(GraficsBuffer& graficsBuffer);
	void processEvent(const enumerations::Event& currentEvent);
	void pause();
	void resume();

	void update();
	void draw(GraficsBuffer& graficsBuffer);

	
protected:

	enum class LevelState{
		RUNNING,
		PLAYER_WIN,
		PLAYER_LOSE,
		UNKNOWN
	};

	EventQueue* const eventQueue_;
	std::shared_ptr<objects::GameObject> actor_;
	GameTimer* gameTimer_;
	World* world_;
	LevelState levelState_;

	unsigned int enemiesInWorld_;
	unsigned int wallsInWorld_;
	unsigned int playerShore_;
	std::wstring elapsedTime_;

	void processChangedObject(const objects::GameObject& gameObject) override;
	
};


#endif // !LEVEL_H


