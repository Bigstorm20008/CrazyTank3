#include "GraficsBuffer.h"


GraficsBuffer::GraficsBuffer() : width_{ }, height_{  }
{
	
}


GraficsBuffer::~GraficsBuffer()
{
	
}


void GraficsBuffer::intialize(const unsigned int& width, const unsigned int& height)
{
	width_ = width - 1;
	height_ = height - 1;

	graficsBuffer_.reserve( height );
	while (graficsBuffer_.size() < graficsBuffer_.capacity())
	{
		std::vector<wchar_t> row( width, { ' ' } );
		graficsBuffer_.push_back( row );
	}
}

void GraficsBuffer::print()const
{
	for (auto& row : graficsBuffer_)
	{
		for (auto& elem : row)
		{
			std::wcout << elem;
		}
		std::wcout << std::endl;
	}	
}



void GraficsBuffer::drawSymbol(const unsigned int& x, const unsigned int& y, const wchar_t& symbol)
{
	bool isValidPoint =  ((x <= width_) && (x >= 0) && (y >= 0) && (y <= height_));

	if (isValidPoint)
	{
		graficsBuffer_[y][x] = symbol;
	}
}

const unsigned int& GraficsBuffer::getWidth() const
{
	return width_;
}

const unsigned int& GraficsBuffer::getHeight() const
{
	return height_;
}

void GraficsBuffer::drawText(const Point& startPoint, const Direction& textDirection, const std::wstring& text)
{
	const unsigned int textLenght = text.length();
	Point currentPoint = startPoint;
	switch (textDirection){
		case Direction::UP :
		{
			unsigned int textIndex = 0;
			while (textIndex < textLenght)
			{
				drawSymbol(currentPoint.x, currentPoint.y, text[textIndex]);
				--currentPoint.y;
				++textIndex;
			}
			break;
		}

		case Direction::DOWN :
		{
			unsigned int textIndex = 0;
			while (textIndex < textLenght)
			{
				drawSymbol(currentPoint.x, currentPoint.y, text[textIndex]);
				++currentPoint.y;
				++textIndex;
			}
			break;
		}

		case Direction::LEFT :
		{
			unsigned int textIndex = 0;
			while (textIndex < textLenght)
			{
				drawSymbol(currentPoint.x, currentPoint.y, text[textIndex]);
				--currentPoint.x;
				++textIndex;
			}
			break;
		}

		case Direction::RIGHT :
		{
			unsigned int textIndex = 0;
			while (textIndex < textLenght)
			{
				drawSymbol(currentPoint.x, currentPoint.y, text[textIndex]);
				++currentPoint.x;
				++textIndex;
			}
			break;
		}

		default:
			break;
	}
}


void GraficsBuffer::clear()
{
	for (auto& row : graficsBuffer_)
	{
		for (auto& symbol : row)
		{
			symbol = { ' ' };
		}
	}
}

