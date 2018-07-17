#include "Point.h"


Point::Point(const int& xPos, const int& yPos) : x{ xPos },  y{ yPos }
{
	
}

Point::Point()
{
	x = 0;
	y = 0;
}


Point::~Point()
{
}

const bool Point::operator==(const Point& point) const
{
	return ((this->x == point.x) && (this->y == point.y));
}

const bool Point::operator!=(const Point& point) const
{
	return (*this == point);
}
