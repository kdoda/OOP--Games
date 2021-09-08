#pragma once
#ifndef BULLET_H
#define BULLET_H
#include "flyingObject.h"
#include <iostream>
#include "uiDraw.h"
#define BULLET_SPEED 10.0
/*********************************************
* BUllET
*********************************************/
class Bullet : public FlyingObject
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	Bullet() : FlyingObject() {};
	Bullet(const Point&point) : FlyingObject(point) {};
	Bullet(const Point&point, const Velocity&velocity)
		: FlyingObject(point, velocity) {};

	virtual ~Bullet() {} //since we are using polymorphism

	virtual string getName()const { return "Regular Bullet"; }
	virtual void fire(const Point&, float);
	virtual void draw();

};

#endif 