#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "orientedObject.h"
#include "uiDraw.h"
/*********************************************
* SHIP
* Everything ship needs to survive in the space
*********************************************/
class Ship : public OrientedObject
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	Ship() : OrientedObject() { } //call the default constructor of flying object
	Ship(const Point&point, const Point& br, const Point& tl) : OrientedObject(point,br,tl) { }
	Ship(const Point&point, const Velocity&velocity, float angle, const Point& br, const Point& tl)
		: OrientedObject(point, velocity, angle,br,tl) { }

	virtual void draw();
	int getSize();
	void rotateRight();
	void rotateLeft();
	void move();
};


#endif /* ship_h */
