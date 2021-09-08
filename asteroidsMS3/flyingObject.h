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
	FlyingObject(const Point& br, const Point& tl) : bottomRight(br), topLeft(tl), alive(true) {}
	FlyingObject(const Point&point,const Point& br, const Point& tl)
		: point(point),bottomRight(br),topLeft(tl), alive(true),velocity(0, 0) {}
	FlyingObject(const Point&point, const Velocity&velocity, const Point& br, const Point& tl)
		: point(point), velocity(velocity), bottomRight(br), topLeft(tl), alive(true) {}
	virtual ~FlyingObject() { } //since we are using polyorphism
	
    //getters
	Point getPoint()const              { return this->point;    }
	Velocity getVelocity()const        { return this->velocity; }
	bool isAlive() const               { return this->alive;    }

	//setters	
	void setPoint(const Point&point)   { this->point = point;   }
	void setVelocity(const Velocity&v) { this->velocity = v;    }
	void kill() { this->alive = false; }
	
	virtual void advance();
	virtual void draw() = 0; //pure virtual
	

protected:
	bool inHorizontalBorders();
	bool inVerticalBorders();
	void keepOnScreen();

	Point bottomRight;
	Point topLeft;
	Point point; //position on the screen 
	Velocity velocity;
	bool alive;
};


#endif /* flyingObject_h */
