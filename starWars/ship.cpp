#include "ship.h"
#include <cmath>
#define PI 3.14
/***************************************
* Ship :: draw on screen
***************************************/
void Ship::draw()
{
	//angle
	//   90
	//0     180
	//  270
	drawShip(point,90 - getAngle());
}

/*****************************************
* Ship :: get the size of the ship(radius)
*****************************************/
int Ship::getSize()
{
	return SHIP_SIZE;
}

/***************************************
* Ship :: rotate the ship on the right
***************************************/
void Ship::rotateRight()
{
	addAngle(ROTATE_AMOUNT);
} 

/***************************************
* Ship :: rotate the ship on the left
***************************************/
void Ship::rotateLeft()
{
	addAngle(-ROTATE_AMOUNT);
}

/***************************************
* Ship :: move the ship on the direction
* it is pointing to.
***************************************/
void Ship::move()
{
	//TODO - add a max speed here
	velocity.addDx(THRUST_AMOUNT * (-cos(PI / 180.0 * getAngle())));
	velocity.addDy(THRUST_AMOUNT * ( sin(PI / 180.0 * getAngle())));
}