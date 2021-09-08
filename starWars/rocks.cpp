#include "rocks.h"

/***************************************
* BigRock :: draw on screen
***************************************/
void BigRock::draw()
{
	drawLargeAsteroid(point, getAngle());
}

/***************************************
* BigRock :: advance (move and rotate)
***************************************/
void BigRock::advance()
{
	addAngle(BIG_ROCK_SPIN);
	Rock::advance(); //call the rock advance, which is the flying object advance
}

/***************************************
* BigRock ::initialize
* Initialize a random angle and set
* the velocity
***************************************/
void BigRock::initialize()
{
	//set a random angle 
	setAngle(random(0.0, 360.0));
	//set the velocity 
	velocity.setDx(-cos(PI / 180.0 * getAngle())); // *1 , but im not writting it since is the same thing
	velocity.setDy(sin(PI / 180.0 * getAngle())); // because the instructions say the speed should be 1 pf
}


/***************************************
* MediumRock :: draw on screen
***************************************/
void MediumRock::draw()
{
	drawMediumAsteroid(point, getAngle());
}

/***************************************
* MediumRock :: advance (move and rotate)
***************************************/
void MediumRock::advance()
{
	addAngle(MEDIUM_ROCK_SPIN);
	Rock::advance(); //call the rock advance, which is the flying object advance
}

/***************************************
* SmallRock :: draw on screen
***************************************/
void SmallRock::draw()
{
	drawSmallAsteroid(point, getAngle());
}

/***************************************
* SmallRock :: advance (move and rotate)
***************************************/
void SmallRock::advance()
{
	addAngle(SMALL_ROCK_SPIN);
	Rock::advance(); //call the rock advance, which is the flying object advance
}

///***************************************
//* BigRock :: kill
//* Kills the big rock and populates
//* the vector with two medium and one small
//* rock accoriding to the instructions
//***************************************/
//void BigRock::kill(std::vector<Rock*> &rocks)
//{
//	//since we kill the BigRock we can change the velocity
//	velocity.addDy(1);
//	rocks.push_back(new MediumRock(getPoint(), getVelocity(), getAngle())); //medium 1
//
//																			//ose should be 1 up the other 1 down
//	velocity.addDy(-2); //since we added 1 up we subtract 2 down now
//	rocks.push_back(new MediumRock(getPoint(), getVelocity(), getAngle())); //medium 2
//
//	velocity.addDy(1); //undo changes
//	velocity.addDx(2); //2 to the right
//	rocks.push_back(new SmallRock(getPoint(), getVelocity(), getAngle())); //small
//
//	FlyingObject::kill(); //kill this bird
//}
//
//
///***************************************
//* SmallRock :: kill
//* Kills the small rock
//***************************************/
//void MediumRock::kill(std::vector<Rock*> &rocks)
//{
//	//since we kill the MediumRock we can change the velocity
//	velocity.addDx(3);
//	rocks.push_back(new SmallRock(getPoint(), getVelocity(), getAngle())); //small 1
//
//																			
//	velocity.addDx(-6); //since we added 3 right we subtract -6 now, to go 3 left
//	rocks.push_back(new SmallRock(getPoint(), getVelocity(), getAngle())); //small 2
//
//	FlyingObject::kill(); //kill this bird
//}
//
///***************************************
//* SmallRock :: kill
//* Kills the small rock
//***************************************/
//void SmallRock::kill(std::vector<Rock*> &rocks)
//{
//	//not populating the vector but we need to 
//	//implement it because it is a pure virtual method
//	//of the base rock class, and we need it virtual to use polymorphism
//	FlyingObject::kill();
//}