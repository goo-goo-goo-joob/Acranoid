#pragma once
#include <math.h>
struct Point
{
public:
	int  X, Y;
	Point(int x = 0, int y = 0) : X(x), Y(y) {}
	void operator+=(const Point & rhs)
	{
		X += rhs.X;
		Y += rhs.Y;
	}
	Point operator+(const Point & rhs) const
	{
		Point n(X, Y);
		n += rhs;
		return n;
	}
	bool operator>(const Point & rhs) const
	{
		return X > rhs.X && Y > rhs.Y;
	}
	bool operator<(const Point & rhs) const
	{
		return X < rhs.X && Y < rhs.Y;
	}
};

