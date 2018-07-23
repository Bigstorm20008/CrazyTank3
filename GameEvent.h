#ifndef EVENT_H
#define EVENT_H

#include "Events.h"

namespace events
{   

	class GameEvent
	{

	public:
		GameEvent(const enumerations::Event& eventId);
		virtual ~GameEvent();
		
		const enumerations::Event& getId()const;
	private:
		const enumerations::Event id_;
	};


}//namespace events



#endif // !EVENT_H



