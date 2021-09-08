#pragma once
#ifndef STAR_H
#define STAR_H
#define SPEED 5
#include "uiDraw.h"
#include "point.h"
//TODO ask comeu if I can kee the size in a seperate headeer so all 
// classes can have access to, hardcode width and height for now

/*********************************************
* STAR
*********************************************/
class Star 
{
public:
	/****************
	* CONSTRUCTORS
	*****************/
	Star();
	Star(const Point&point);
	Star(const Point& br, const Point& tl);
	Star(const Point&point, int width);
	
	
	void draw();
	void advance(); //override
private:
	Point bottomRight;
	Point topLeft;
	Point point; //position on the screen
	float z;     //used to give the illusion of 3D
	float lz;    //line Z I need it for the line, because it need to be short and updated after we update z

	
	float map(float value, float start1, float end1, float start2, float end2);

};



#endif /* bullet_h */
