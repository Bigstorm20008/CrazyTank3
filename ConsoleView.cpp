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

	for (int i = 0; i != backBuffer_.graficsBuffer_.size(); ++i)
	{
		for (int j = 0; j != backBuffer_.graficsBuffer_[i].size(); ++j)
		{
			if (backBuffer_.graficsBuffer_[i][j] != frontBuffer_.graficsBuffer_[i][j])
			{
				scrn.X = j;
				scrn.Y = i;
				SetConsoleCursorPosition(consoleOuput, scrn);
				std::wcout << backBuffer_.graficsBuffer_[i][j];
				frontBuffer_.graficsBuffer_[i][j] = backBuffer_.graficsBuffer_[i][j];
			}
		}
	}
}


GraficsBuffer& ConsoleView::getBackBuffer()
{
	return backBuffer_;
}
