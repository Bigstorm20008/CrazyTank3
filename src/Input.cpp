#include "Input.h"


Input::Input(EventQueue& eventQueue) : eventQueue_{ &eventQueue }
{
}


Input::~Input()
{
}

void Input::inputHandler(const enumerations::Key& key)const
{
	using namespace enumerations;

	switch (key)
	{
		case Key::SPACE:
		{
			eventQueue_->addEvent({ enumerations::Event::SPACE_KEY_PRESSED });
			break;
		}

		case Key::ARROW_UP:
		{
			eventQueue_->addEvent({ enumerations::Event::UP_ARROW_KEY_PRESSED });
			break;
		}

		case Key::ARROW_LEFT:
		{
			eventQueue_->addEvent({ enumerations::Event::LEFT_ARROW_KEY_PRESSED });
			break;
		}

		case Key::ARROW_RIGHT:
		{
			eventQueue_->addEvent({ enumerations::Event::RIGHT_ARROW_KEY_PRESSED });
			break;
		}

		case Key::ARROW_DOWN:
		{
			eventQueue_->addEvent({ enumerations::Event::DOWN_ARROW_KEY_PRESSED });
			break;
		}

		case Key::Q:
		case Key::q:
		{
			eventQueue_->addEvent({ enumerations::Event::QUIT_GAME });
			break;
		}

		case Key::S:
		case Key::s:
		{
			eventQueue_->addEvent({ enumerations::Event::START_GAME });
			break;
		}

		case Key::p:
		{
			eventQueue_->addEvent({ enumerations::Event::PAUSE_GAME });
			break;
		}

		default :
			break;
	}
}
