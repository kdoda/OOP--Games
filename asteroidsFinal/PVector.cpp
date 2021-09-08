#include "PVector.h"

/***************************************
* ADD the rhs to this PVector
****************************************/
void PVector::add(const PVector& rhs)
{
	addX(rhs.getX());
	addY(rhs.getY());
}

/***************************************
* Function Call operator
****************************************/
void PVector::operator () (float x, float y)
{
	this->x = x;
	this->y = y;
}

/***************************************
* Multiply x and y by n
****************************************/
void PVector::mult(float n)
{
	multX(n);
	multY(n);
}

/***************************************
* Create a random velocity
****************************************/
void PVector::randomVelocity(float min, float max)
{
	randomAngle();

	multX(random(min, max));
	multY(random(min, max));
}

/***************************************
* Create a random Angle
****************************************/
void PVector::randomAngle(float min, float max)
{
	assert(min >= 0.0 && max <= 360.0);

	double angle = random(min, max);
	x = -cos(PI / 180.0 * angle);
	y =  sin(PI / 180.0 * angle);
}