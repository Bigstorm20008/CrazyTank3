#include "WallBlock.h"

namespace objects
{

	WallBlock::WallBlock(const helpers::Point& position,
		                 const wchar_t& graficsPresent,
		                 const unsigned int& health,
		                 const ObjectId& objectId,
						 const std::chrono::milliseconds& logicPeriodInMilliseconds,
						 const std::wstring& allWallblockPresents) :
						 GameObject{ position, graficsPresent, health, objectId },
						 GameEntity{ logicPeriodInMilliseconds },
						 allWallblockPresents_( allWallblockPresents )
	{
	}


	WallBlock::~WallBlock()
	{
	}


	void WallBlock::doLogic(World& world)
	{
		size_t len = allWallblockPresents_.length();

		size_t presentsIndex = len - health_;

		if (graficsPresent_ != allWallblockPresents_[presentsIndex]){
			graficsPresent_ = allWallblockPresents_[presentsIndex];
		}
	}

}//namespace objects
