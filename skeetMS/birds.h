
#pragma once
#ifndef BIRDS_H
#define BIRDS_H
#include "flyingObject.h"
#include "uiDraw.h"

/*********************************************
* BIRD
*********************************************/
class Bird : public FlyingObject
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	Bird() : FlyingObject() { } //call the default constructor of flying object
	Bird(const Point&point) : FlyingObject(point) { }
	Bird(const Point&point, const Velocity&velocity)
		: FlyingObject(point, velocity) { }

	virtual ~Bird() {} //since we have no pointer they are deleted automatically
					   //virtual because we are using polymorphi and when we delete bird, 
					   //if that point to a derived class, we need to call the destructor of the derived class also 

	virtual string getName()const { return "Regular Bird"; }
	virtual void draw(); //pure virtual 
	virtual int hit();
	virtual void randomVelocity(bool);
};


/*********************************************
* SacredBird
*********************************************/
class SacredBird : public Bird
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	SacredBird() : Bird() { }
	SacredBird(const Point&point) :Bird(point) { }
	SacredBird(const Point&point, const Velocity&velocity)
		: Bird(point, velocity) { }
	virtual ~SacredBird() {}

	virtual string getName()const { return "Sacred Bird"; }
	virtual void draw();
	virtual int hit();
	virtual void randomVelocity(bool);
};


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
		: Bird(point, velocity), numHits(0) { }
	virtual ~ToughBird() {}

	virtual string getName()const { return "Tough Bird"; }
	virtual void draw();
	virtual int hit();
	virtual void randomVelocity(bool);
private:
	int numHits; //how mant hits has the bird 
};

#endif // BIRDS_H
