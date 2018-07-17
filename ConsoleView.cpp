#include "ConsoleView.h"


ConsoleView::ConsoleView() : backBuffer_{}, frontBuffer_{}
{
	
}


ConsoleView::~ConsoleView()
{
}


void ConsoleView::initialize(const unsigned int& width, const unsigned int& height)
{
	backBuffer_.intialize( width, height );
	frontBuffer_ = backBuffer_;

	HANDLE consoleOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(consoleOuput, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(consoleOuput, &structCursorInfo);
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
