#include "laser.h"
#include <cmath>
#define PI 3.14

/******************************************
* Draw Laser on the screen
*******************************************/
void Laser::draw()
{
	drawLine(start, end, 1, 0, 0);
}

/******************************************
* Advance Laser on the screen
*******************************************/
void Laser::advance(const Point &start, float angle)
{
	this->start = end = start;

	end.addX(LENGTH * (-cos(PI / 180.0 * angle)));
	end.addY(LENGTH * ( sin(PI / 180.0 * angle)));
}
