#pragma once
#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include "point.h"
#include "velocity.h"
#include <string>
/*********************************************
* FlyingObject
*********************************************/
class FlyingObject
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	FlyingObject() : alive(true) {} //check those
	FlyingObject(const Point&point)
		: point(point), alive(true) {}
	FlyingObject(const Point&point, const Velocity&velocity)
		: point(point), velocity(velocity), alive(true) {}
	virtual ~FlyingObject() { } //since we are using polyorphism

								//getters
	Point getPoint()const;
	Velocity getVelocity()const;
	bool isAlive() const;

	//setters
	void setPoint(const Point&);
	void setVelocity(const Velocity&);

	void kill();
	virtual void advance();
	virtual void draw() = 0; //pure virtual
	virtual std::string getName()const = 0; //pure virtual 
protected:
	Point point; //position on the screen 
	Velocity velocity;
private:
	bool alive;
};

#endif