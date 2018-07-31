#include "Point.h"

namespace helpers
{

	Point::Point(const int& xPos, const int& yPos) : x{ xPos }, y{ yPos }
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


	Point getNextPoint(const Point& currentPoint, const enumerations::Direction& direction, const int& offset)
	{
		using namespace enumerations;

		Point nextPoint = currentPoint;
		
		switch (direction)
		{
			case Direction::UP:
			    nextPoint.y -= offset;
				break;

			case Direction::DOWN:
				nextPoint.y += offset;
				break;

			case Direction::LEFT:
				nextPoint.x -= offset;
				break;

			case Direction::RIGHT:
				nextPoint.x += offset;
				break;

			default:
				break;
		}

		return std::move(nextPoint);
	}

}//namespace helpers