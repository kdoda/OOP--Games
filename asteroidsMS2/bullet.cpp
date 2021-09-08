#include "bullet.h"
#include <cmath>
#define PI 3.14

#include <iostream>
using namespace std;
/********************************************
* Draw bullet
********************************************/
void Bullet::draw()
{
	drawDot(point);
}

/********************************************
* Fire bullet
* Nees the velocity, angle and position
********************************************/
void Bullet::fire(Point point, Velocity v, float angle)
{   
	//IMPORTANT bullet should follow the ship it it fly fast up and rotates
	velocity.setDx(BULLET_SPEED * -cos(PI / 180.0 * angle) + v.getDx());
	velocity.setDy(BULLET_SPEED *  sin(PI / 180.0 * angle)  + v.getDy());

	//set poisition
	setPoint(point); 
}

/********************************************
* Advance bullet
* Move bullet and kill it after 40 frames
********************************************/
void Bullet::advance()
{
	if (lifeSpan == BULLET_LIFE)
	{
		this->kill();
	}
	else
	{
		++lifeSpan;// one more frame passed
		FlyingObject::advance(); //advance this bullet
	}
}