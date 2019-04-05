#pragma once
#include "zgl.h"
#include "Point.h"
class Plate {
private:
	Point _location;
	Point _speed;
	Point _size;
public:
	Plate(Point location, Point size) : _location(location), _size(size), _speed(0, 0) {};
	Point loc() const { return _location; }
	Point size() const { return _size; }
	void Move(int x)
	{
		_location.X += x;
	}
	bool isIn(Point p) const
	{
		return _location < p && _location + _size > p;
	}
	bool IsCircle(int x, int y, int r)
	{
		return pow(x - (_location.X + _size.X), 2) + pow(y - (_location.Y + _size.Y/2), 2) <= pow(r, 2) ||
			pow(x - _location.X, 2) + pow(y - (_location.Y + _size.Y / 2), 2) <= pow(r, 2);
	}
	void Draw() const
	{
		zgl_FillRect(_location.X, _location.Y, _size.X, _size.Y);
	}
	void SetStart(Point loc_p)
	{
		_location = loc_p;
	}
};