#include "birds.h"
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
		points += 2; //1 for hit 2 for hitting the third time
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