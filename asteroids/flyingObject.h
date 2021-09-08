#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"
#include <string>
/*********************************************
* FlyingObject
* Everything a flying object needs
*********************************************/
class FlyingObject
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	FlyingObject() : point(0,0),velocity(0,0),alive(true) {}
	FlyingObject(const Point&point)
		: point(point), alive(true),velocity(1, 1) {}
	FlyingObject(const Point&point, const Velocity&velocity)
		: point(point), velocity(velocity), alive(true) {}
	virtual ~FlyingObject() { } //since we are using polyorphism

	
    //getters
	Point getPoint()const              { return this->point;    }
	Velocity getVelocity()const        { return this->velocity; }
	bool isAlive() const               { return this->alive;    }

	//setters	
	void setPoint(const Point&point)   { this->point = point;   }
	void setVelocity(const Velocity&v) { this->velocity = v;    }
	void kill() { this->alive = false; }

	void bringBackHorizontally();
	void bringBackVertically();
	
	virtual void advance();
	virtual void draw() = 0; //pure virtual
	 
protected:
	Point point; //position on the screen 
	Velocity velocity;
	bool alive;
};


#endif /* flyingObject_h */
