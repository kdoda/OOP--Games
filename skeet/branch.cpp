#include "branch.h"


/*********************************************
* REturn a new branch with the angle  in radian
*********************************************/
void Branch::draw()
{
	drawLine(begin, end);
}

/*********************************************
* Return a new branch with the angle  in radian
*********************************************/
Branch* Branch::newBranch(float angle)
{

	Point newEnd = rotate(end, begin, angle);
	newEnd.addY(40);

 	return new Branch(end, newEnd);
}

/*********************************************
* Rotate Q around P with theta angle
*********************************************/
Point Branch::rotate(Point P, Point Q, double theta)
{
	return  (P - Q) * polar(1.0, theta) + Q;
}

/*********************************************
* Create a point from the magnitude and angle
*********************************************/
Point Branch::polar(float magnitude, float theta)
{
	return Point(magnitude * cos(theta), magnitude * sin(theta));
}


