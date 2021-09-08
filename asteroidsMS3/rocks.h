#ifndef rocks_h
#define rocks_h
#include <cmath>
#define PI 3.14

//radius
#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock

#include "orientedObject.h"
#include "uiDraw.h"
#include "vector"
/*********************************************
* SHIP
* Everything ship needs to survive in the space
*********************************************/
class Rock : public OrientedObject
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	Rock() : OrientedObject() { } //call the default constructor of orientedObject
	Rock(const Point&point, const Point& br, const Point& tl) : OrientedObject(point,br,tl) { }
	Rock(const Point&point, const Velocity&velocity, float angle, const Point& br, const Point& tl)
		: OrientedObject(point, velocity, angle,br,tl) { }

	virtual void draw() = 0;
	virtual int  getSize() = 0;
	virtual string getName() = 0;
	//keeping the base class advance definition
};


class BigRock : public Rock
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	BigRock() : Rock() { initialize(); }
	BigRock(const Point&point, const Point& br, const Point& tl) : Rock(point,br,tl) { initialize(); }
	BigRock(const Point&point, const Velocity&velocity, float angle, const Point& br, const Point& tl)
		: Rock(point, velocity, angle,br,tl) { }

	virtual void draw();
	virtual int  getSize() { return BIG_ROCK_SIZE; }
	virtual string getName() { return "BigRock"; }
	virtual void advance(); //overriding
	
private:
	void initialize();
};

class MediumRock : public Rock
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	MediumRock()
	{

	}
	MediumRock(const Point&point, const Point& br, const Point& tl) : Rock(point,br,tl) { }
	MediumRock(const Point&point, const Velocity&velocity, float angle, const Point& br, const Point& tl)
		: Rock(point, velocity, angle,br,tl) { }

	virtual void draw();
	virtual int  getSize() { return MEDIUM_ROCK_SPIN; }
	virtual string getName() { return "MediumRock"; }
	virtual void advance(); //overriding 
};

class SmallRock : public Rock
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	SmallRock()
	{

	}
	SmallRock(const Point&point, const Point& br, const Point& tl) : Rock(point,br,tl) { }
	SmallRock(const Point&point, const Velocity&velocity, float angle, const Point& br, const Point& tl)
		: Rock(point, velocity, angle,br,tl) { }

	virtual void draw();
	virtual int  getSize() { return SMALL_ROCK_SIZE; }
	virtual string getName() { return "SmallRock"; }
	virtual void advance(); //overriding 
};

#endif /* rocks_h */
