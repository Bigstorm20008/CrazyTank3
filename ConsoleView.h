#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include <string>

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

	void prepeareBuffers(const unsigned int& width, const unsigned int& height);
	void setWindowSizesInSymbols(const unsigned int& width, const unsigned int& height);
	void moveWindowToScreenCenter();
	void hideConsoleCursor();
	

};

#endif // !CONSOLE_VIEW_H



