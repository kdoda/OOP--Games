#include "firework.h"
#include <algorithm>
// acceleration in the y axis should be negative because it should go down
PVector Firework::gravity = PVector(0, -0.2);

/***********************************************************
* Advance Firework 
************************************************************/
void Firework::advance()
{
	if (mainParticle.isAlive())
	{
		mainParticle.applyForce(gravity);
		mainParticle.advance();		
	}

	if (mainParticle.isAlive() && mainParticle.explode())
	{
		for (int i = 0;i < FIRE_PARTICLES;++i)
		{		
			FireParticle fp(mainParticle.getPosition(), color);
			fireParticles.push_back(fp);
		}
	}

	
	for (int i = 0;i < fireParticles.size();)
	{
		fireParticles[i].applyForce(gravity);
		fireParticles[i].advance();

		if (!fireParticles[i].isAlive())
		{
			std::swap(fireParticles[i], fireParticles.back());//swap with the last
			fireParticles.pop_back(); //delete the last
		}
		else
		{
			++i; //advance
		}
	}
}

/***************************************************
* Draw firework
****************************************************/
void Firework::draw()
{
	if (mainParticle.isAlive())
		mainParticle.draw();

	for (int i = 0;i < fireParticles.size();++i)
	{
			fireParticles[i].draw();	
	}
}
