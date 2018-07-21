#ifndef EVENT_H
#define EVENT_H

#include "Events.h"

namespace events
{   

	class GameEvent
	{

	public:
		GameEvent(const enumarations::Event& eventId);
		virtual ~GameEvent();
		
		const enumarations::Event& getId()const;
	private:
		const enumarations::Event id_;
	};


}//namespace events



#endif // !EVENT_H



