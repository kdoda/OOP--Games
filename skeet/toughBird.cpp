#include "toughBird.h"

/***************************************
* ToughBird :: draw on screen
***************************************/
void ToughBird::draw()
{
	drawToughBird(point, 15, numHits);
}

/***************************************
* ToughBird :: kill the bird if hit 3 times
* and return the points earned
***************************************/
int ToughBird::hit()
{
	int points = 0;

	if (numHits == 2) //this hit is the third one
	{
		kill();
		points +=2; //1 for hit 2 for hitting the third time
	}
	else
	{
		numHits++;
	}

	return points + 1;
		
}

/***************************************
* Bird :: create a random velocity
* for the bird according to game rules
***************************************/
void ToughBird::randomVelocity(bool up)
{
	float horizontalV = random(2.0, 4.0); //3to6
	float verticalV = (up ? 1 : -1) * random(0.0, 3.0); //dont want to be 0
	
	velocity.setDx(horizontalV); //or pass them here immediatly but would be messy
	velocity.setDy(verticalV);
}