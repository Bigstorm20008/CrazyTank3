#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include <Windows.h>

#include "GraficsBuffer.h"

class ConsoleView
{
public:
	ConsoleView();
	~ConsoleView();

	void initialize(const unsigned int& width, const unsigned int& height);
	void render();

	GraficsBuffer& getBackBuffer();

private:
	GraficsBuffer backBuffer_;
	GraficsBuffer frontBuffer_;

};

#endif // !CONSOLE_VIEW_H



