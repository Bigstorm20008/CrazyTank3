#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "Point.h"

namespace entities
{

	class GameEntity
	{
	public:
		GameEntity(const helpers::Point& position, const wchar_t& graficsPresent);
		virtual ~GameEntity();

		virtual void update() = 0;

		inline const helpers::Point& getPosition() const;
		inline const wchar_t& getGraficsPresent()const;
	private:
		helpers::Point position_;
		wchar_t graficsPresent_;
	};



	inline const helpers::Point& GameEntity::getPosition() const
	{
		return position_;
	}


	inline const wchar_t& GameEntity::getGraficsPresent()const
	{
		return graficsPresent_;
	}


}//namespace entities

#endif // !GAME_ENTITY_H


