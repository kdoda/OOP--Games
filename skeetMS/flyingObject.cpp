#include "flyingObject.h"

/********************************************
* GET :: position
********************************************/
Point FlyingObject::getPoint()const
{
	return this->point;
}

/********************************************
* GET :: velocity
********************************************/
Velocity FlyingObject::getVelocity()const
{
	return this->velocity;
}

/********************************************
* GET :: alive
********************************************/
bool FlyingObject::isAlive()const
{
	return this->alive;
}


/********************************************
* SET :: position
********************************************/
void FlyingObject::setPoint(const Point&point)
{
	this->point = point;
}

/********************************************
* SET :: velocity
********************************************/
void FlyingObject::setVelocity(const Velocity&velocity)
{
	this->velocity = velocity;
}

/********************************************
* Kill FlyingObject
********************************************/
void FlyingObject::kill()
{
	this->alive = false;
}

/********************************************
* Advance the FlyingObject
********************************************/
void FlyingObject::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}


