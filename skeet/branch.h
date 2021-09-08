#pragma once
#ifndef BRANCH_H
#define BRANCH_H

#include "point.h"
#include "uiDraw.h"

/*********************************************
* BRANCH a branch of a fractal tree
*********************************************/
class Branch
{
public:
	Branch() {}
	Branch(const Point& b, const Point & e) : begin(b),end(e){}
	void draw();
	Branch* newBranch(float angle);

	Point getEnd() { return end; }
private:
	Point begin;
	Point end;
	Point rotate(Point P, Point Q, double theta);
	Point polar(float magnitude, float theta);
	
};

#endif /* BRANCH_H */