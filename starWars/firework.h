#pragma once
#ifndef FIREWORK_H
#define FIREWORK_H
#include <vector>
#include "particles.h"
#include "RGB.h"
#define FIRE_PARTICLES 150


class Firework
{

public:
	//TODO default const
	Firework()
	{
		color.createRandom();
	}
	Firework(float x, float y)
	{
		color.createRandom();
		mainParticle = Particle(x, y, color); //TODO make it a calling function operator
	}

	bool isAlive() { return (mainParticle.isAlive() || !fireParticles.empty()); }
	void advance();  
	void draw();    

private:
	std::vector<FireParticle> fireParticles;
	Particle mainParticle; //the single particle that bursts later
	RGB color;
	static PVector gravity;

};


#endif // POINT_H
