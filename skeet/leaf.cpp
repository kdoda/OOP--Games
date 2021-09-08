#include "leaf.h"

/*********************************************
* ADVANCE leaf on the screen
*********************************************/
void Leaf::advance()
{
    lifespan -= 0.01;
	if(lifespan < 0)
		lifespan = 0;

	point.addY(random(-2.0, 0.0));
	point.addX(random(-1.0, 1.0));
}

/*********************************************
* DRAW leaf on the screen
*********************************************/
void Leaf::draw()
{
	drawFullCircle(point, RADIUS, 1.0, 0, 0.2, lifespan);
}