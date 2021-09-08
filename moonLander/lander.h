#pragma once
#pragma once
#ifndef LANDER_H
#define LANDER_H
#include "uiDraw.h"
#include "velocity.h"
class Lander
{
private:
	Point point; //position
	Velocity velocity;
	int fuel;
	bool alive;
	bool landed;
	bool crashed;
	int numLives;
public:
	Lander(const Point&);
	Lander(const Point&,const Velocity&,int,bool,bool,int);
	int getNumLives() const;
	void setNumLives(int);
	Point getPoint() const;
	void setPoint(const Point&);
	Velocity getVelocity() const;
	bool isCrashed() const;
	bool isAlive() const;
	bool isLanded() const;
	int getFuel() const;
	bool canThrust() const;
	void setCrashed(bool);
	void setLanded(bool);
	void setAlive(bool);
	void setFuel(int);
	void applyGravity(float);
	void applyThrustLeft(); 
	void applyThrustRight();
	void applyThrustBottom();
	void applyThrustUp();
	void advance();
	void draw();
	void reset(const Point&);
	void subtractNumLives(int);
	void addFuel(int);
	
};
#endif /* GAME_H */