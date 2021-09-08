#include "bird.h"
/***************************************
* Bird :: draw on screen
***************************************/
void Bird::draw()
{
	drawCircle(point, 15);
}

/***************************************
* Bird :: kill the bird and return
* the points earned
***************************************/
int Bird::hit()
{
	this->kill();
	return 1;
}

/***************************************
* Bird :: create a random velocity 
* for the bird according to game rules
***************************************/
void Bird::randomVelocity(bool up)
{
	float horizontalV = random(3.0, 6.0); //3to6
	float verticalV = (up ? 1 : -1) * random(0.0, 4.0); //dont want to be 0

	velocity.setDx(horizontalV); //or pass them here immediatly but would be messy
	velocity.setDy(verticalV);
}