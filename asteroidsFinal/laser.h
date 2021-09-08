#pragma once
#ifndef LASER_H
#define LASER_H
#include "point.h"
#include "uiDraw.h"
#define LENGTH 200

/******************************************
* Laser class.
*******************************************/
class Laser
{
public:
	Laser() : alive(true) { }
	Laser(const Point &start,const Point &end) :start(start),end(end),alive(true) { }
	
	Point getStartPoint()const             { return start;        }
	void setStartPoint(const Point &start) { this->start = start; }
	Point getEndPoint()const               { return end;          }
	void setEndPoint(const Point &start)   { this->end = end;     }
	bool isAlive() const                   { return alive;        }
	void resurrect()                       { alive = true;        }
	void kill()                            { alive = false;       }
	
	void draw();
	void advance(const Point &start, float angle);

private:
	Point start;
	Point end;
	bool alive;
};

#endif