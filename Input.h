#ifndef INPUT_H
#define INPUT_H


#include "Keys.h"
#include "EventQueue.h"
#include "Events.h"

class Input
{

public:
	explicit Input(EventQueue& eventQueue);
	~Input();

	void inputHandler(const Key& key)const;

private:
	EventQueue* eventQueue_;
};

#endif // !INPUT_H



