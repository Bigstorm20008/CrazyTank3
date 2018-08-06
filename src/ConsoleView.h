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

	inline GraficsBuffer& getBackBuffer();

private:
	GraficsBuffer backBuffer_;
	GraficsBuffer frontBuffer_;

	inline void prepeareBuffers(const unsigned int& width, const unsigned int& height);
	inline void setWindowSizesInSymbols(const unsigned int& width, const unsigned int& height);
	inline void moveWindowToScreenCenter();
	inline void hideConsoleCursor();
	

};



inline GraficsBuffer& ConsoleView::getBackBuffer()
{
	return backBuffer_;
}


inline void ConsoleView::prepeareBuffers(const unsigned int& width, const unsigned int& height)
{
	backBuffer_.intialize(width, height);
	frontBuffer_ = backBuffer_;
}


inline void ConsoleView::setWindowSizesInSymbols(const unsigned int& width, const unsigned int& height)
{
	std::string systemCommand;
	systemCommand.assign({ "mode con cols=" });
	systemCommand.append(std::to_string(width));
	systemCommand.append({ " lines=" });
	systemCommand.append(std::to_string(height));

	system(systemCommand.c_str());
}


inline void ConsoleView::moveWindowToScreenCenter()
{
	const int monitorWidth = GetSystemMetrics(SM_CXSCREEN);
	const int monitorHeight = GetSystemMetrics(SM_CYSCREEN);

	const HWND consoleHwnd = GetConsoleWindow();
	RECT consoleRect;
	GetWindowRect(consoleHwnd, &consoleRect);
	const unsigned int& consoleWidth = consoleRect.right - consoleRect.left;
	const unsigned int& consoleHeight = consoleRect.bottom - consoleRect.top;

	MoveWindow(consoleHwnd, (monitorWidth - consoleWidth) / 2,
		(monitorHeight - consoleHeight) / 2,
		consoleWidth, consoleHeight, true);

	long Style = GetWindowLong(consoleHwnd, GWL_STYLE);
	Style &= ~WS_SIZEBOX;
	Style &= ~WS_MINIMIZEBOX;
	Style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(consoleHwnd, GWL_STYLE, Style);

}


inline void ConsoleView::hideConsoleCursor()
{
	HANDLE consoleOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(consoleOuput, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(consoleOuput, &structCursorInfo);
}


#endif // !CONSOLE_VIEW_H



