#include "bullet.h"
#include <cmath>
#define PI 3.14

/********************************************
* Draw bullet
********************************************/
void Bullet::draw()
{
	drawDot(point);
}

/********************************************
* Fire bullet
********************************************/
void Bullet::fire(const Point&point, float angle)
{
	//set the velocity 
	velocity.setDx(BULLET_SPEED * (-cos(PI / 180.0 * angle)));
	velocity.setDy(BULLET_SPEED * (sin(PI / 180.0 * angle)));

	//set poisition
	setPoint(point);
}
