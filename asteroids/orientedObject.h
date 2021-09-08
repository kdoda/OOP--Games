#pragma once
#include "flyingObject.h"

class OrientedObject : public FlyingObject
{
public:
	OrientedObject() : FlyingObject() {}
	OrientedObject(const Point&point) : FlyingObject(point) {}
	OrientedObject(const Point&point, const Velocity&velocity, float angle)
		: FlyingObject(point, velocity)
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

