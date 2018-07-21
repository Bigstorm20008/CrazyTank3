#ifndef POINT_H
#define POINT_H


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
	};

} //namespace helpers

#endif // !POINT_H




