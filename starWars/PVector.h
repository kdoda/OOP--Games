#pragma once
#ifndef PVECTOR_H
#define PVECTOR_H

#include "uiDraw.h"
#include <cmath>
#define PI 3.14
#include <cassert>

/*******************************************************
* PVECTOR 
* A class to consider Point, Velocity, Acceleration
* all as vector in a 2D plan, since they all have
* an x and y, why have three classes, instead of 1.
******************************************************/
class PVector 
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	PVector()
		:x(0),y(0){}
	PVector(float x, float y)
		:x(x),y(y){}

	// getters
	float getX()       const { return x;          }
	float getY()       const { return y;          }

	// setters
	void setX(float x)       { this->x = x;       }
	void setY(float y)       { this->y = y;       }

	void addX(float dx)      { setX(getX() + dx); }
	void addY(float dy)      { setY(getY() + dy); }

	
	void multX(float n)      { x *= n;            }
	void multY(float n)      { y *= n;            }
	void mult(float n);
	void add(const PVector&); 

	void randomVelocity(float min = 1.0, float max = 10.0);
	void randomAngle(float min = 0.0, float max = 360.0);

	void operator () (float x, float y);
	
private:
	float x;
	float y;
};



#endif /* bullet_h */
