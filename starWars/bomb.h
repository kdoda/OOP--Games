#ifndef BOMB_H
#define BOMB_H

#include "bullet.h"

#define BOMB_SPEED 3
#define BOMB_LIFE 60
#define BOMB_RADIUS 7
/**********************************************
* Bomb
***********************************************/
class Bomb : public Bullet
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	Bomb() : Bullet() {};
	Bomb(const Point& br, const Point& tl) : Bullet(br, tl) {};
	Bomb(const Point&point, const Point& br, const Point& tl) : Bullet(point, br, tl) {};
	Bomb(const Point&point, const Velocity&velocity, const Point& br, const Point& tl)
		: Bullet(point, velocity, br, tl) {};

	virtual ~Bomb() {} //since we are using polymorphism

	//take it as a copy or move it, because it is passed a rvalue
	// that you can not have a reference to
	virtual void fire(Point point, Velocity velocity, float angle);
	virtual void draw();
	virtual void advance(); //override

};
#endif
