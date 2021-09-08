#include "orientedObject.h"

/********************************************
* SET :: angle
* Angle should always be in 0-360, so we take
* care of the input that the user gives
********************************************/
void OrientedObject::setAngle(float angle)
{
	int angleI = (int)angle; //angle in int cause I'm using % operator
	float angleP = angle - angleI; //the precission after the comma
	angleI %= 360; // we want the angle in the range 0-360
	angleI += (angleI < 0 ? 360 : 0); //if it is negative turn it to the positive equivalence
	this->angle = angleI + angleP; //add the value after comma 
}

/********************************************
* ADD :: angle
* Add to angle using the set method so
* we make sure that angle is in 0-360
********************************************/
void OrientedObject::addAngle(float angle)
{
	setAngle(this->angle + angle);
}
