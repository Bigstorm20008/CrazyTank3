#include "Input.h"


Input::Input(EventQueue& eventQueue) : eventQueue_(&eventQueue)
{
}


Input::~Input()
{
}

void Input::inputHandler(const Key& key)const
{
	typedef events::GameEvent eGameEvent;

	switch (key)
	{
		case Key::SPACE :
		{
			events::GameEvent currentEvent(Event::SPACE_KEY_PRESSED);
			eventQueue_->addEvent(std::move(currentEvent));
			break;
		}

		case Key::ARROW_UP:
		{
			events::GameEvent currentEvent(Event::UP_ARROW_KEY_PRESSED);
			eventQueue_->addEvent(std::move(currentEvent));
			break;
		}

		case Key::ARROW_LEFT :
			break;

		case Key::ARROW_RIGHT :
			break;

		default :
			break;
	}
}
