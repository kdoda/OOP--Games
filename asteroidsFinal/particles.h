#pragma once
#ifndef PARTICLES_H
#define PARTICLES_H

#include "RGB.h"
#include "PVector.h"
#include "uiDraw.h"

#define RADIUS 5

class Particle
{
public:
	Particle()
	{
		lifeSpan = 1.0;
	}
	Particle(float x, float y, const RGB& rgb)
	{
		position(x, y);
		velocity(0, random(8.0, 12.0));
		acceleration(0, 0);
		this->rgb = rgb;
		lifeSpan = 1.0;
		
	}


	Particle(const PVector &pos, const RGB& rgb)
		:position(pos)
	{
		acceleration(0, 0);
		velocity.randomVelocity(1.0, 8.0);
		this->rgb = rgb;
		lifeSpan = 1.0;
	}
	
	void advance();
	void draw();
	bool explode();
    
	PVector getPosition()     { return position;         }
	PVector getAcceleration() { return acceleration;     }
	bool isAlive() const      { return (lifeSpan > 0.0); }
	void kill()               { lifeSpan = 0.0;          }

	void applyForce(const PVector& force);
	void randomAngle(float min = 0.0, float max = 180.0)
	{
		velocity.randomAngle(min,max);
	}

protected:
	PVector position;
	PVector velocity;
	PVector acceleration;
	float lifeSpan;    //here lifespan has two values 0 or 1,dead or alive
	RGB rgb;           //the color
	
};


class FireParticle : public Particle
{
public:
	//TODO default const
	FireParticle(float x, float y, const RGB& rgb)
		: Particle(x,y,rgb), radius(5.0)
	{	}

	FireParticle(const PVector &pos, const RGB& rgb)
		:Particle(pos,rgb),radius(5.0)
	{	}

	void advance();
	void draw();

private:
	float radius;
	//here lifespan is in the range 0.0-1.0 because I use it for the tranperancy
};


#endif // POINT_H
