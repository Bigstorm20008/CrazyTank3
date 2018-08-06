#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Point.h"

namespace objects
{

	enum class ObjectId;

	class GameObject
	{
	public:
		GameObject(const helpers::Point& position,
			       const wchar_t& graficsPresent,
			       const unsigned int& health,
			       const ObjectId& objectId);

		virtual~GameObject() = 0;

		inline const helpers::Point& getPosition() const;
		inline const wchar_t& getGraficsPresent()const;
		inline const unsigned int& getHealth()const;
		inline const ObjectId& getId()const;

		inline void decreaseHealth();

	protected:
		helpers::Point position_;
		wchar_t graficsPresent_;
		unsigned int health_;
		ObjectId objectId_;

	};

	enum class ObjectId{
		PLAYER_TANK,
		ENEMY_TANK,
		PLAYER_BULLET,
		ENEMY_BULLET,
		WALL_BLOCK,
		STRONGHOLD_BLOCK
	};


}//namespace objects

#include "GameObject.inl"

#endif // !GAME_OBJECT_H



