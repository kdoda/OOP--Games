#pragma once
#ifndef VELOCITY_H
#define VELOCITY_H
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
	void reset();
};

#endif /* GAME_H */