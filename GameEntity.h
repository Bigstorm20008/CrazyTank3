#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

class World;

class GameEntity
{
public:
	GameEntity();
	virtual ~GameEntity();

	virtual void update(const World& world) = 0;
};

#endif // !GAME_ENTITY_H



