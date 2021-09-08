#ifndef LANDER_H
#define LANDER_H
#include "uiDraw.h"
#include "velocity.h"
/*************************************************
 * LANDER. 
 * This class has all the functionality of Lander
 * such as drawm getters and setters etc. 
 ************************************************/
class Lander
{
private:
	Point point; //position
	Velocity velocity;
	int fuel;
	bool alive;
	bool landed;
public:
  Lander();
	Lander(const Point&);
	Lander(const Point&,const Velocity&,int,bool,bool);
	Point getPoint() const;
	void setPoint(const Point&);
	Velocity getVelocity() const;
	bool isAlive() const;
	bool isLanded() const;
	int getFuel() const;
	bool canThrust() const;
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
	void addFuel(int);
	
};
#endif /* GAME_H */