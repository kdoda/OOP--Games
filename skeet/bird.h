#pragma once
#ifndef BIRD_H
#define BIRD_H
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
		: FlyingObject(point,velocity) { }
	
	virtual ~Bird() {} //since we have no pointer they are deleted automatically
	//virtual because we are using polymorphi and when we delete bird, 
	//if that point to a derived class, we need to call the destructor of the derived class also 
	
	virtual string getName()const { return "Regular Bird"; }
	virtual void draw(); //pure virtual 
	virtual int hit();
	virtual void randomVelocity(bool);
};

#endif // POINT_H
