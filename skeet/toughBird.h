#pragma once
#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H
#include "bird.h"

/*********************************************
* ToughBird
*********************************************/
class ToughBird : public Bird
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	ToughBird() : Bird(), numHits(0) {}
	ToughBird(const Point&point) : Bird(point), numHits(0) { }
	ToughBird(const Point&point, const Velocity&velocity) 
		: Bird(point,velocity), numHits(0) { }
	virtual ~ToughBird() {}

	virtual string getName()const { return "Tough Bird"; }
	virtual void draw(); 
	virtual int hit();
	virtual void randomVelocity(bool);
private:
	int numHits; //how mant hits has the bird 
};

#endif // POINT_H