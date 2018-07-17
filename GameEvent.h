#ifndef EVENT_H
#define EVENT_H

#include "Events.h"

namespace events
{   

	class GameEvent
	{

	public:
		explicit GameEvent(const Event& eventId);
		virtual ~GameEvent();
		
		const Event& getId()const;
	private:
		const Event id_;
	};


}//namespace events



#endif // !EVENT_H



