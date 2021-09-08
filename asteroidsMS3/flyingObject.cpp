#include "flyingObject.h"
#include <cassert>


/********************************************
* Advance the FlyingObject
********************************************/
void FlyingObject::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());

	keepOnScreen();
}

/**************************************************************************
* FlyingObject :: IN HORIZONTAL BORDERS
* Determines if a given point is inside the horizontal borders of the screen
**************************************************************************/
bool FlyingObject::inHorizontalBorders()
{
	return (point.getY() >= bottomRight.getY()
		&& point.getY() <= topLeft.getY());
}

/**************************************************************************
* FlyingObject :: IN VERTICAL BORDERS
* Determines if a given point is inside the vertical borders of the screen
**************************************************************************/
bool FlyingObject::inVerticalBorders()
{
	return (point.getX() >= topLeft.getX()
		&& point.getX() <= bottomRight.getX());
}

/**************************************************************************
* FlyingObject :: KEEP ON SCREEN
* Checks if the flying object left the screen. If it did it brings it back.
**************************************************************************/
void FlyingObject::keepOnScreen()
{
	//if it left the vertical borders
	if (!inVerticalBorders())
	{   //since it is a square window just change the sign
		point.changeXSign();
	}//if it left the horizontal borders
	else if (!inHorizontalBorders())
	{
		point.changeYSign();
	}
}
