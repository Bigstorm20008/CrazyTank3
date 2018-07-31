#ifndef TANK_H
#define TANK_H

class World;

class Tank
{
public:
	Tank();
	virtual ~Tank();

	virtual void fire(World& world) = 0;
};

#endif // !TANK_H



