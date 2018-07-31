#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Point.h"

class GameObject
{
public:
	GameObject(const helpers::Point& position, const wchar_t& graficsPresent, const unsigned int& health);

	virtual~GameObject() = 0;

	inline const helpers::Point& getPosition() const;
	inline const wchar_t& getGraficsPresent()const;
	inline const unsigned int& getHealth()const;

protected:
	helpers::Point position_;
	wchar_t graficsPresent_;
	unsigned int health_;

};

#include "GameObject.inl"

#endif // !GAME_OBJECT_H



