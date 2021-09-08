#pragma once
#ifndef SNIPERBULLET_H
#define SNIPERBULLET_H
#include "bullet.h"
#define SNIPERBULLET_SPEED 17.0
/*********************************************
* SniperBullet
*********************************************/
class SniperBullet : public Bullet
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	SniperBullet() : Bullet() { }
	SniperBullet(const Point&point) : Bullet(point) { }
	SniperBullet(const Point&point, const Velocity&velocity)
		: Bullet(point, velocity) { }
	virtual ~SniperBullet() {}

	virtual string getName()const { return "Sniper Bullet"; }
	virtual void draw();
	virtual void fire(const Point&, float);
private:
	float angle; //since I am drwaing a ship as a sniper bullet I need the angle
};

#endif 