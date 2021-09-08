#include "velocity.h"

/********************************************
* GET :: horizontal velocity
********************************************/
float Velocity::getDx()const
{
	return this->dx;
}

/********************************************
* GET :: vertical velocity
********************************************/
float Velocity::getDy()const
{
	return this->dy;
}

/********************************************
* SET :: horizontal velocity
********************************************/
void Velocity::setDx(float dx)
{
	this->dx = dx;
	//I want this to go negative
	//when I apply thrust left, because If velocity goes negative
	//when I subtract it at Lander::advance() from pos - - turns +
	// and lander moves on the right
}

/********************************************
* SET :: vertical velocity
********************************************/
void Velocity::setDy(float dy)
{
	this->dy = dy; //same reason
}

/********************************************
* RESET velocity.
********************************************/
void Velocity::reset()
{
	this->dx = 0;
	this->dy = 0;
}

/********************************************
* Add to dX the amount
********************************************/
void Velocity::addDx(float amount)
{
	this->dx += amount;
}

/********************************************
* Add to dY the amount
********************************************/
void Velocity::addDy(float amount)
{
	this->dy += amount;
}

