#define ZGL_SHARED
#include "zgl.h"
#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include "Ball.h"
#include "Plate.h"
#pragma warning(disable: 4996) 

using namespace std;

const int v_x = 8, v_y = -8, v_pl = 30;
Point loc_p(300, 500), loc_b(400, 500 - 10);

Point Size(800, 600);
Ball b(loc_b, Point(v_x, v_y), 10);
Plate p(loc_p, Point(200, 20));

void Draw();
void Keypress(unsigned int);
void Timer();


int main()
{
	zgl_CreateWindow(900, 700, "Arcanoid");
	zgl_SetWindowColor(ZGL_GRAY);
	zgl_SetFontColor(ZGL_BLACK);
	zgl_SetDrawColor(ZGL_LIGHTRED);

	zgl_SetTimer(20, Timer);

	zgl_SetUserDrawFunction(Draw);
	zgl_SetUserKeyboardFunction(Keypress);

	return zgl_Main();
}

void Keypress(unsigned int Button) {
	Button &= 0xFF;
	if (Button == ZK_LEFT) {
		if (0 <= p.loc().X - v_pl) {
			p.Move(-v_pl);
		}
	}
	if (Button == ZK_RIGHT) {
		if (p.loc().X + p.size().X + v_pl <= Size.X){
			p.Move(v_pl);
		}
	}
	if (Button == ZK_SPACE) {
		b.SetPlay(true, loc_b, v_x, v_y);
		p.SetStart(loc_p);
	}
}

void Draw(void)
{
	zgl_DrawRect(0, 0, Size.X, Size.Y);
	b.Draw();
	p.Draw();
	if (!b.GetPlay())
	{
		zgl_LoadFont("1251");
		zgl_DrawString(280, 300, "Game over. Press SPACE to restart");
	}
}

void Timer() {
	if (b.loc().X + b.GetSpeed().X <= b.r() || b.loc().X + b.GetSpeed().X >= Size.X - b.r())
	{
		b.BumpX();
	}
	if (b.loc().Y + b.GetSpeed().Y <= b.r())
	{
		b.BumpY();
	}
	if (p.isIn(b.loc() + Point(0, b.r() )))
	{
		float alpha = acos((b.loc().X - p.loc().X - 0.5 * p.size().X) / (0.5 * p.size().X) );
		b.SetSpeed(Point( b.GetAbs() * cos(alpha), -b.GetAbs() * sin(alpha)));
	}
	else if (p.IsCircle(b.loc().X, b.loc().Y, b.r())) {
		b.BumpX();
		b.BumpY();
	}
	if (Size.Y <= b.loc().Y + b.r() + b.GetSpeed().Y)
	{
		b.SetPlay(false);
	}
	b.Move();
}