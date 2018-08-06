#ifndef WALL_BLOCK_H
#define WALL_BLOCK_H

#include <string>

#include "GameObject.h"
#include "GameEntity.h"

namespace objects
{

	class WallBlock :
		public GameObject, public GameEntity
	{
	public:
		WallBlock(const helpers::Point& position,
			      const wchar_t& graficsPresent,
			      const unsigned int& health,
			      const ObjectId& objectId,
				  const std::chrono::milliseconds& logicPeriodInMilliseconds,
				  const std::wstring& allWallblockPresents);

		virtual ~WallBlock();

		void doLogic(World& world) override;

	private:
		std::wstring allWallblockPresents_;
	};

}//namespace objects

#endif // !WALL_BLOCK_H



