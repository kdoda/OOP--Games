#pragma once
#ifndef SACREDBIRD_H
#define SACREDBIRD_H
#include "bird.h"

/*********************************************
* StandartBird
*********************************************/
class SacredBird : public Bird
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	SacredBird() : Bird() { }
	SacredBird(const Point&point) :Bird(point){ } 
	SacredBird(const Point&point, const Velocity&velocity)
		: Bird(point,velocity) { }
	virtual ~SacredBird() {}

	virtual string getName()const { return "Sacred Bird"; }
	virtual void draw();
	virtual int hit();
	virtual void randomVelocity(bool);
};

#endif 