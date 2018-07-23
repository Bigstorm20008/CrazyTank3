#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "Point.h"

class EntityStore;

namespace entities
{

	class GameEntity
	{
	public:
		GameEntity(const helpers::Point& position, const wchar_t& graficsPresent,
			       const unsigned int& health);
		virtual ~GameEntity();

		virtual void update(EntityStore& entityStore) = 0;

		inline const helpers::Point& getPosition() const;
		inline const wchar_t& getGraficsPresent()const;
		inline const unsigned int& getHealth()const;
	private:
		helpers::Point position_;
		wchar_t graficsPresent_;
		unsigned int health_;
	};



	inline const helpers::Point& GameEntity::getPosition() const
	{
		return position_;
	}


	inline const wchar_t& GameEntity::getGraficsPresent()const
	{
		return graficsPresent_;
	}


	inline const unsigned int& GameEntity::getHealth()const
	{
		return health_;
	}


}//namespace entities

#endif // !GAME_ENTITY_H


