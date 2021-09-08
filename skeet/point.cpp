/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/

#include "point.h"
#include <cassert>

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y
 * Initialize the point to the passed position
 *****************************************/
Point::Point(float x, float y) : x(0.0), y(0.0)
{
   setX(x);
   setY(y);
}

/*******************************************
 * POINT : SET X
 * Set the x position if the value is within range
 *******************************************/
void Point::setX(float x)
{
   this->x = x;
}

/*******************************************
 * POINT : SET Y
 * Set the y position if the value is within range
 *******************************************/
void Point::setY(float y)
{
   this->y = y;
} 

/*******************************************
* ADD two point operator
******************************************/
Point  Point::operator + (const Point & rhs) const
{
	return Point(x + rhs.x, y + rhs.y);
}

/*******************************************
* SUBTRACT two point operator
******************************************/
Point  Point::operator - (const Point & rhs) const
{
	return Point(x - rhs.x, y - rhs.y);
}

/*******************************************
* MULTIPLY two point operator
******************************************/
Point  Point::operator * (const Point & rhs) const
{
	return Point((x*rhs.x - y*rhs.y), (x*rhs.y + y*rhs.x));
}

/*******************************************
* ASSIGN operator
******************************************/
Point& Point::operator = (const Point & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;

	return *this;
}


/******************************************
 * POINT insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream & operator << (std::ostream & out, const Point & pt)
{
   out << "(" << pt.getX() << ", " << pt.getY() << ")";
   return out;
}

/*******************************************
 * POINT extraction
 *       Prompt for coordinates
 ******************************************/
std::istream & operator >> (std::istream & in, Point & pt)
{
   float x;
   float y;
   in >> x >> y;

   pt.setX(x);
   pt.setY(y);

   return in;
}
 
