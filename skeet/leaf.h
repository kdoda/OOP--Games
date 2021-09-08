#pragma once
#ifndef LEAF_H
#define LEAF_H

#define RADIUS 5
#include "point.h"
#include "uiDraw.h"


/*********************************************
* LEAF of a tree
*********************************************/
class Leaf
{
public:
	Leaf() :lifespan(1.0) {}
	Leaf(const Point &point) : point(point), lifespan(1.0) {}

	void setPoint(const Point & point) { this->point = point;      }
	Point getPoint() const             { return point;             }
	bool isAlive()                     { return (lifespan > 0.0);  }

	void advance();
	void draw();
	
private:
	Point point;
	float lifespan;
};

#endif /* LEAF_H */