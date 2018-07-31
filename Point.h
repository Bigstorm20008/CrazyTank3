#ifndef POINT_H
#define POINT_H

#include <utility>

#include "Direction.h"

namespace helpers
{

	class Point
	{
	public:
		explicit Point(const int& xPos, const int& yPos);
		explicit Point();
		~Point();

		int x;
		int y;

		const bool operator==(const Point& point)const;
		const bool operator!=(const Point& point)const;
		const bool operator<(const Point& rhs)const;
	};

	Point getNextPoint(const Point& currentPoint, const enumerations::Direction& direction, const int& offset);

} //namespace helpers

#endif // !POINT_H




