#pragma once
#ifndef SHOTGUNBULLET_H
#define SHOTGUNBULLET_H
#include "bullet.h"
#define SHOTGUNBULLET_SPEED 13.0
/*********************************************
* ShotgunBullet
*********************************************/
class ShotgunBullet : public Bullet
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	ShotgunBullet() : Bullet(),bulletRadius(2.0) { }
	ShotgunBullet(const Point&point) :Bullet(point), bulletRadius(2.0) { }
	ShotgunBullet(const Point&point, const Velocity&velocity)
		: Bullet(point, velocity), bulletRadius(2.0) { }
	virtual ~ShotgunBullet() {}

	virtual string getName()const { return "Shotgun Bullet"; }
	virtual void draw();
	virtual void fire(const Point&, float);
private:
	float bulletRadius; //keep growing every time the draw func is called
};

#endif 