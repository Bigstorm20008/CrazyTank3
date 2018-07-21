#include "Input.h"


Input::Input(EventQueue& eventQueue) : eventQueue_{ &eventQueue }
{
}


Input::~Input()
{
}

void Input::inputHandler(const enumarations::Key& key)const
{
	switch (key)
	{
		case enumarations::Key::SPACE:
		{
			eventQueue_->addEvent({ enumarations::Event::SPACE_KEY_PRESSED });
			break;
		}

		case enumarations::Key::ARROW_UP:
		{
			eventQueue_->addEvent({ enumarations::Event::UP_ARROW_KEY_PRESSED });
			break;
		}

		case enumarations::Key::ARROW_LEFT:
		{
			eventQueue_->addEvent({ enumarations::Event::LEFT_ARROW_KEY_PRESSED });
			break;
		}

		case enumarations::Key::ARROW_RIGHT:
		{
			eventQueue_->addEvent({ enumarations::Event::RIGHT_ARROW_KEY_PRESSED });
			break;
		}

		/*case Key::ARROW_DOWN:
		{
			eventQueue_->addEvent({ Event::DOWN_ARROW_KEY_PRESSED });
			break;
		}*/

		case enumarations::Key::Q:
		case enumarations::Key::q:
		{
			eventQueue_->addEvent({ enumarations::Event::QUIT_GAME });
			break;
		}

		case enumarations::Key::S:
		case enumarations::Key::s:
		{
			eventQueue_->addEvent({ enumarations::Event::START_GAME });
			break;
		}

		case enumarations::Key::P:
		case enumarations::Key::p:
		{
			eventQueue_->addEvent({ enumarations::Event::PAUSE_GAME });
			break;
		}

		default :
			break;
	}
}
