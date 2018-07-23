#include "Point.h"

namespace helpers
{

	Point::Point(const int& xPos, const int& yPos) : x( xPos ), y( yPos )
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


	const bool Point::operator<(const Point& rhs)const
	{
		bool isLess = false;

		if (this->y < rhs.y)
		{
			isLess = true;
		}
		if (this->y == rhs.y)
		{
			isLess = this->x < rhs.x;
		}

		return isLess;
	}

}//namespace helpers