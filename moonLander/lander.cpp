#include "lander.h"


/********************************************
* LANDER :: CONSTRUCTOR
********************************************/
Lander::Lander(const Point &point, const Velocity &vel, int fuel, bool alive, bool landed, int lives)
	:point(point),velocity(vel),fuel(fuel),alive(alive),landed(landed)
{
	setNumLives(lives);
}

/********************************************
* LANDER :: CONSTRUCTOR
********************************************/
Lander::Lander(const Point&point)
	: point(point)
{
	velocity.reset();
	setFuel(500);
	setAlive(true);
	setLanded(false);
	setNumLives(3);
}

/********************************************
* GET :: number of lives left
********************************************/
int Lander::getNumLives() const
{
	return this->numLives;
}

/********************************************
* SET :: number of lives
********************************************/
void Lander::setNumLives(int numLives)
{
	this->numLives = (numLives < 0 ? 0 : numLives);
}

/********************************************
* SET :: number of lives
********************************************/
void Lander::subtractNumLives(int amount)
{
	this->numLives -= amount;
}

/********************************************
* GET :: crashed
********************************************/
bool Lander::isCrashed() const
{
	return this->crashed;
}

/********************************************
* SET :: crashed
********************************************/
void Lander::setCrashed(bool crashed)
{
	this->crashed = crashed;
}

/********************************************
* GET :: point (position)
********************************************/
Point Lander::getPoint() const
{
	return this->point;
}

/********************************************
* SET :: point (position)
********************************************/
void Lander::setPoint(const Point &point)
{
	this->point = point;
}

/********************************************
* GET :: velocity
********************************************/
Velocity Lander::getVelocity() const
{
	return this->velocity;
}

/********************************************
* GET :: alive
********************************************/
bool Lander::isAlive() const
{
	return this->alive;
}

/********************************************
* GET :: landed
********************************************/
bool Lander::isLanded() const
{
	return this->landed;
}

/********************************************
* GET :: fuel
********************************************/
int Lander::getFuel() const
{
	return this->fuel;
}

/********************************************
* return true if can thrust otherwise false
********************************************/
bool Lander::canThrust() const
{
	return (this->fuel>0);
}

/********************************************
* SET :: landed
********************************************/
void Lander::setLanded(bool landed)
{
	this->landed = landed;
}

/********************************************
* SET :: alive
********************************************/
void Lander::setAlive(bool alive)
{
	this->alive = alive;
}

/********************************************
* SET :: fuel, if negative set 0
********************************************/
void Lander::setFuel(int fuel)
{
	this->fuel = (fuel > 0 ? fuel : 0);
}

/********************************************
* apply gravity to the velocity of the lander
********************************************/
void Lander::applyGravity(float gravity)
{
	this->velocity.addDx(gravity);
	this->velocity.addDy(gravity);
}

/********************************************
* apply thrust left to the horizontal 
* (go right) velocity if there is still fuel left
* subtract from fuel
********************************************/
void Lander::applyThrustLeft() 
{
	addFuel(-1); //subtract 1 from fuel

	if (getFuel() > 0)
	{
		this->velocity.addDx(-0.1);
	}
		
}

/********************************************
* apply thrust right to the horizontal
* (go left) velocity if there is still fuel left
* subtract from fuel
********************************************/
void Lander::applyThrustRight()
{
	addFuel(-1); //subtract 1 from fuel

	if (getFuel() > 0)
	{
		this->velocity.addDx(+0.1);
	}
	
}

/********************************************
* apply thrust bottom to the vertical velocity
* (go up) if there is still fuel left
* subtract from fuel
********************************************/
void Lander::applyThrustBottom()
{

	addFuel(-3); //subtract 3 from fuel

	if (getFuel() > 0)
	{
		this->velocity.addDy(-0.3);
	}

}

/********************************************
* apply thrust up to the vertical velocity
* (go down) if there is still fuel left
* subtract from fuel
********************************************/
void Lander::applyThrustUp()
{
	this->velocity.addDy(0.05);
}

/********************************************
* advance lander by subtracting from its
* position the velocity
********************************************/
void Lander::advance()
{
	this->point.addX( - velocity.getDx()); //subtract the velocity dx
	this->point.addY( - velocity.getDy()); //subtract the velocity dy
}

/********************************************
* draw lander at its poistion
********************************************/
void Lander::draw()
{
	drawLander(point);
}

/********************************************
* Resets the lander attributes
********************************************/
void Lander::reset(const Point&point)
{
	velocity.reset();
	setPoint(point);
	setFuel(500);
	setCrashed(false);
	setLanded(false);
	setAlive(true);
}

/********************************************
* Add the amount to fuel
********************************************/
void Lander::addFuel(int amount)
{
	this->fuel += amount;
}