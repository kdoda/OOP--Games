#pragma once
#include "flyingObject.h"

class OrientedObject : public FlyingObject
{
public:
	OrientedObject() : FlyingObject() {}
	OrientedObject(const Point&point, const Point& br, const Point& tl) : FlyingObject(point,br,tl) {}
	OrientedObject(const Point&point, const Velocity&velocity, float angle, const Point& br, const Point& tl)
		: FlyingObject(point, velocity,br,tl)
	{
		setAngle(angle);
	}

	virtual ~OrientedObject() { }

	float getAngle()const { return this->angle; }
	void setAngle(float angle);
	void addAngle(float angle);

	virtual void draw() = 0; //pure virtual

private:
	
	/**********************************************************
	*  angle - The angle of the flyingojbects in degrees.
	*  Assumes that straight right is 0 degrees and up is 90.
	*  Should be from 0-360.
	**********************************************************/
	float angle;
};

