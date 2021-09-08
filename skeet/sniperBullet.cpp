#include "sniperBullet.h"
#include <cmath>
#define PI 3.14

/********************************************
* Draw sniper bullet
********************************************/
void SniperBullet::draw()
{
	drawShip(point,angle);
}

/********************************************
* Fire sniper bullet
********************************************/
void SniperBullet::fire(const Point&point, float angle)
{
	//set the velocity 
	velocity.setDx(SNIPERBULLET_SPEED * (-cos(PI / 180.0 * angle)));
	velocity.setDy(SNIPERBULLET_SPEED * (sin(PI / 180.0 * angle)));

	//set poisition
	setPoint(point);
	this->angle = angle;
}
