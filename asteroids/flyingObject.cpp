#include "flyingObject.h"
#include <cassert>





/********************************************
* Advance the FlyingObject
********************************************/
void FlyingObject::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}

/******************************************************
* BRING BACK HORIZONTALLY
* if it passed the right side bring it back on the left
* if it passed the left side bring it back on the right
*******************************************************/
void FlyingObject::bringBackHorizontally()
{
	//since it is a square window just change the sign
	//if it wasn't we would need it's dimensions
	point.changeYSign();
}

/******************************************************
* BRING BACK VERTICALLY
* if it passed the upper border  bring it back from down
* if it passed the down border  bring it back from up
*******************************************************/
void FlyingObject::bringBackVertically()
{
	//since it is a square window just change the sign
	point.changeXSign();
}