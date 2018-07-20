#include "Input.h"


Input::Input(EventQueue& eventQueue) : eventQueue_{ &eventQueue }
{
}


Input::~Input()
{
}

void Input::inputHandler(const Key& key)const
{
	switch (key)
	{
		case Key::SPACE :
		{
			eventQueue_->addEvent({ Event::SPACE_KEY_PRESSED });
			break;
		}

		case Key::ARROW_UP :
		{
			eventQueue_->addEvent({ Event::UP_ARROW_KEY_PRESSED });
			break;
		}

		case Key::ARROW_LEFT :
		{
			eventQueue_->addEvent({ Event::LEFT_ARROW_KEY_PRESSED });
			break;
		}

		case Key::ARROW_RIGHT :
		{
			eventQueue_->addEvent({ Event::RIGHT_ARROW_KEY_PRESSED });
			break;
		}

		/*case Key::ARROW_DOWN:
		{
			eventQueue_->addEvent({ Event::DOWN_ARROW_KEY_PRESSED });
			break;
		}*/

		case Key::Q :
		case Key::q :
		{
			eventQueue_->addEvent({ Event::QUIT_GAME });
			break;
		}

		case Key::S :
		case Key::s :
		{
			eventQueue_->addEvent({ Event::START_GAME });
			break;
		}

		case Key::P:
		case Key::p:
		{
			eventQueue_->addEvent({ Event::PAUSE_GAME });
			break;
		}

		default :
			break;
	}
}
