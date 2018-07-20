#include "ConsoleView.h"


ConsoleView::ConsoleView() : backBuffer_{}, frontBuffer_{}
{
	
}


ConsoleView::~ConsoleView()
{
}


void ConsoleView::render()
{
	HANDLE consoleOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD scrn;

	auto& backBufferSymbols = backBuffer_.graficsBuffer_;
	auto& frontBufferSymbols = frontBuffer_.graficsBuffer_;

	for (int i = 0; i != backBufferSymbols.size(); ++i)
	{
		for (int j = 0; j != backBufferSymbols[i].size(); ++j)
		{
			if (backBufferSymbols[i][j] != frontBufferSymbols[i][j])
			{
				scrn.X = j;
				scrn.Y = i;
				SetConsoleCursorPosition(consoleOuput, scrn);
				std::wcout << backBufferSymbols[i][j];
				frontBufferSymbols[i][j] = backBufferSymbols[i][j];
			}
		}
	}
}


GraficsBuffer& ConsoleView::getBackBuffer()
{
	return backBuffer_;
}


void ConsoleView::initialize(const unsigned int& width, const unsigned int& height)
{
	prepeareBuffers(width, height);

	setWindowSizesInSymbols(width, height);

	moveWindowToScreenCenter();
	
	hideConsoleCursor();
}





void ConsoleView::prepeareBuffers(const unsigned int& width, const unsigned int& height)
{
	backBuffer_.intialize(width, height);
	frontBuffer_ = backBuffer_;
}


void ConsoleView::setWindowSizesInSymbols(const unsigned int& width, const unsigned int& height)
{
	std::string systemCommand;
	systemCommand.assign({ "mode con cols=" });
	systemCommand.append(std::to_string(width));
	systemCommand.append({ " lines=" });
	systemCommand.append(std::to_string(height));
	system(systemCommand.c_str());
}


void ConsoleView::moveWindowToScreenCenter()
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
}


void ConsoleView::hideConsoleCursor()
{
	HANDLE consoleOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(consoleOuput, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(consoleOuput, &structCursorInfo);
}





