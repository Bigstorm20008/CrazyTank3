#ifndef GRAFICS_BUFFER_H
#define GRAFICS_BUFFER_H

#include <iostream>
#include <vector>

#include "Direction.h"
#include "Point.h"

class GraficsBuffer
{
public:
	friend class ConsoleView;

	GraficsBuffer();
	~GraficsBuffer();

	void intialize(const unsigned int& width, const unsigned int& height);

	void drawSymbol(const unsigned int& x, const unsigned int& y,
		            const wchar_t& symbol);

	void drawText(const helpers::Point& startPoint, const enumerations::Direction& textDirection,
		          const std::wstring& text);

	const unsigned int& getWidth()const;
	
	const unsigned int& getHeight()const;

	void clear();
	
private:
	unsigned int width_;
	unsigned int height_;

	std::vector<std::vector<wchar_t>> graficsBuffer_;

	void print()const;
	

};



#endif // !GRAFICS_BUFFER_H



