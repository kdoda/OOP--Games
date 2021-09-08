#include "particles.h"

/*************************************
* Adcance particle on the screen
**************************************/
void Particle::advance()
{
	velocity.add(acceleration);
	position.add(velocity);
	acceleration.mult(0);
}

/*************************************
* Adcance particle on the screen
**************************************/
void Particle::draw()
{
	Point pos(position.getX(), position.getY());
	drawFullCircle(pos, RADIUS, rgb.red, rgb.green, rgb.blue, lifeSpan);
}

/*************************************
* Did this particle explode?
* If so kill it.
**************************************/
bool Particle::explode()
{
	if (velocity.getY() < 0)//going down now
	{
		kill();
		return true;
	}

	return false;
}

/*******************************************
* Add force to the acceleration
********************************************/
void Particle::applyForce(const PVector& force) 
{ 
	acceleration.add(force); 
}

/******************************************
* Advance this fire particle on the screen
*******************************************/
void FireParticle::advance()
{
	Particle::advance();
	
	if (lifeSpan > 0)
	    lifeSpan -= 0.01;
	
	if (radius > 0)
		radius -= 0.05;

	velocity.mult(0.93);
}

/******************************************
* Draw fireparticle on the screen
*******************************************/
void FireParticle::draw()
{
	Point pos(position.getX(), position.getY());
	drawFullCircle(pos, radius, rgb.red, rgb.green, rgb.blue, lifeSpan);
}