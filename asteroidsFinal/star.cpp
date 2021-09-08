/*********************************************************************
* File: star.cpp
* Description: Contains the implementaiton of the star class
*  methods.
*********************************************************************/

#include "star.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

/**********************************
* CONSTRUCTOR default
* random position inside the screen
***********************************/
Star::Star()
{
	lz = z = 0; //to move with random speed
}

/**************************
* CONSTRUCTOR 
***************************/
Star::Star(const Point& point)
	:point(point)
{
	lz = z = 0;
}

Star::Star(const Point& br, const Point& tl) 
	: bottomRight(br), topLeft(tl)
{
	lz = z = random(1.0, br.getX());
}

/***************************************
* CONSTRUCTOR
* width should be the size from the center
* of the screen. If screen is -200,200
* width should be 200
****************************************/
Star::Star(const Point&point, int width)
	:point(point)
{
		lz = z = random(1, width);
}

/***************************************************
* MAP the the value from the first scale to the second
* one. For ex: value 0.2 in a scale 0-1 maps to value
* 1 in a scale 0-5
****************************************************/
float Star::map(float value, float start1, float end1, float start2, float end2)
{
	return (value - start1) / (end1 - start1) * (end2 - start2) + start2;
}

/***************************************
* DRAW star on the screen
****************************************/
void Star::draw()
{
	//mapping 0-1 to 0-200
	//200 for the width and height hardcoded
	float sX = map(point.getX() / z, 0, 1, 0, bottomRight.getX()); //star X
	float sY = map(point.getY() / z, 0, 1, 0, topLeft.getY()); //star Y

	float r = map(z, 0, bottomRight.getX(), 3.5, 0.5); //0.3 start very small
	drawFullCircle(Point(sX, sY), r);

	//lz is bigger than z at this point because z has been advanced
	float lX = map(point.getX() / lz, 0, 1, 0, bottomRight.getX()); //line starting pos X
	float lY = map(point.getY() / lz, 0, 1, 0, topLeft.getY()); //line starting pos y 

	drawLine(Point(lX, lY), Point(sX, sY));
}

/***************************************
* ADVANCE star on the screen
****************************************/
void Star::advance()
{
	//you can keep a counter and updated it once in 5 calls of advance for ex
	//if you want the line longer
	lz = z; //old z
	z -= SPEED;

	if(z<1) //star went out of the screen
	{
		lz = z = bottomRight.getX();
		point.setX(random(topLeft.getX(), bottomRight.getX()));
		point.setY(random(bottomRight.getY(), topLeft.getY()));
	}
}