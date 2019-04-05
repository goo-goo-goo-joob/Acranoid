#pragma once
#include "Point.h"

class Ball {
private:
	Point _location;
	Point _speed;
	int _r;
	float _absSpeed;
	bool _play;
public:
	Point loc() const
	{
		return _location;
	}
	int r() const
	{
		return _r;
	}
	Ball(Point p, Point speed, float r) : _location(p), _r(r), _speed(speed), _play(true) 
	{
		_absSpeed = sqrt(pow(speed.X, 2) + pow(speed.Y, 2));
	}
	void Move() 
	{
		if (_play) 
		{
			_location += _speed;
		}
	}
	bool GetPlay()
	{
		return _play;
	}
	void SetPlay(bool play, Point loc_b, int v_x, int v_y)
	{
		_play = play;
		_location = loc_b;
		_speed = Point(v_x, v_y);
	}
	void SetPlay(bool play)
	{
		_play = play;
	}
	float GetAbs() const 
	{
		return _absSpeed;
	}
	void SetSpeed(const Point & s)
	{
		_speed = s;
	}
	void BumpX()
	{
		_speed.X *= -1.1;
	}
	void BumpY()
	{
		_speed.Y *= -1.1;
	}
	Point GetSpeed() const
	{
		return _speed;
	}
	void Draw() const
	{
		if (_play)
		{
			zgl_FillCircle(_location.X, _location.Y, _r);
		}
	}
	~Ball()
	{

	}
};