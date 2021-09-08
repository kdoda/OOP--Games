#include "sacredBird.h"

/***************************************
* SacredBird :: draw on screen
***************************************/
void SacredBird::draw()
{
	drawSacredBird(point, 15);
}

/***************************************
* SacredBird :: kill the bird and return
* the point penallty
***************************************/
int SacredBird::hit()
{
	kill();
	return -10;
}

/***************************************
* SacredBird :: create a random velocity
* for the bird according to game rules
***************************************/
void SacredBird::randomVelocity(bool up)
{
	float horizontalV = random(3.0, 6.0); //3to6
	float verticalV = (up ? 1 : -1) * random(0.0, 4.0); //dont want to be 0

	velocity.setDx(horizontalV); //or pass them here immediatly but would be messy
	velocity.setDy(verticalV);
}