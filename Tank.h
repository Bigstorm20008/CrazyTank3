#pragma once
#include "DynamicEntity.h"

namespace entities
{
	class Tank :
		public DynamicEntity
	{
	public:
		Tank(const helpers::Point& position, const wchar_t& graficsPresent, const enumerations::Direction& direction);
		virtual ~Tank();

		void update()override;
	};

}
