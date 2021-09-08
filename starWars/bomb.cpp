#include "bomb.h"
#include <cmath>
#define PI 3.14

void Bomb::fire(Point point, Velocity v, float angle)
{
	//set the velocity 
	//abs of velocity because it can be negative too 
	//it is set back to negative by the cos and sin 
	velocity.setDx((BOMB_SPEED + std::abs(v.getDx())) * (-cos(PI / 180.0 * angle)));
	velocity.setDy((BOMB_SPEED + std::abs(v.getDy())) * (sin(PI / 180.0 * angle)));

	//set poisition
	setPoint(point);
}

void Bomb::draw()
{
	drawSacredBird(point, BOMB_RADIUS);
}

void Bomb::advance()
{
	if (lifeSpan == BOMB_LIFE)
	{
		this->kill();
	}
	else
	{
		++lifeSpan;// one more frame passed
		FlyingObject::advance(); //advance this bomb
	}
}