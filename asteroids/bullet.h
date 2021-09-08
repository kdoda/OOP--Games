#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "flyingObject.h"
#include <iostream>
#include "uiDraw.h"

/*********************************************
* BULLET
*********************************************/
class Bullet : public FlyingObject
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	Bullet() : FlyingObject(), lifeSpan(0) {};
	Bullet(const Point&point) : FlyingObject(point), lifeSpan(0) {};
	Bullet(const Point&point, const Velocity&velocity)
		: FlyingObject(point, velocity), lifeSpan(0) {};

	virtual ~Bullet() {} //since we are using polymorphism

	//take it as a copy or move it, because it is passed a rvalue
	// that you can not have a reference to
	virtual void fire(Point point, Velocity velocity, float angle);
	virtual void draw();
	virtual void advance(); //override
private:
	/*********************************************
	* keeps track of how many times the advance 
	* method is called for the bullet in order to 
	* kill it when it reaches it frame lifes 
	*********************************************/
	int lifeSpan; 
};



#endif /* bullet_h */
