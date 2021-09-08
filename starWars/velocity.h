#ifndef VELOCITY_H
#define VELOCITY_H

/********************************************
* Velocity class, that keeps track of
* horizontal and vertical velocity.
********************************************/
class Velocity
{
private:
	float dx;
	float dy;
public:
	Velocity() :dx(0.0), dy(0.0) {};
	Velocity(float dx, float dy)
	{
		setDx(dx);
		setDy(dy);
	};
	float getDx()const;
	float getDy()const;
	void setDx(float);
	void setDy(float);
	void addDx(float);
	void addDy(float);
	void reset();
};


#endif /* velocity_h */
