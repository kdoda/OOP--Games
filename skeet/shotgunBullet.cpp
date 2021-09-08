#include "shotgunBullet.h"
#include <cmath>
#define PI 3.14

/********************************************
* Draw shotgun bullet
********************************************/
void ShotgunBullet::draw()
{
	drawToughBird(point, bulletRadius, 0);
	bulletRadius += 0.3;
}

/********************************************
* Fire shotgun bullet
********************************************/
void ShotgunBullet::fire(const Point&point, float angle)
{
	//set the velocity 
	velocity.setDx(SHOTGUNBULLET_SPEED * (-cos(PI / 180.0 * angle)));
	velocity.setDy(SHOTGUNBULLET_SPEED * (sin(PI / 180.0 * angle)));

	//set poisition
	setPoint(point);
}
