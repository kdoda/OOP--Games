/*************************************************************
* File: game.cpp
* Author: Br. Burton
*
* Description: Contains the implementations of the
*  method bodies for the game class.
*
* Please DO NOT share this code with other students from
*  other sections or other semesters. They may not receive
*  the same code that you are receiving.
*************************************************************/
#include <cassert>
#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"


/******************************************
* GAME :: DRAW ALTITUDE
* Draws the current altitude.
******************************************/
void Game::drawAltitude() const
{
	drawText(Point(topLeft.getX() + 160, topLeft.getY() - 15), "ALTITUDE");
	drawNumber(Point(bottomRight.getX() - 100, topLeft.getY() - 5),
		lander.getPoint().getY() - bottomRight.getY());
}

/******************************************
* GAME :: DRAW ALTITUDE
* Draws the current lives.
******************************************/
void Game::drawLives() const
{
	drawText(Point(topLeft.getX() + 5, topLeft.getY() - 30), "LIVES");
	drawToughBird(Point(topLeft.getX() + 55, topLeft.getY() - 27), 7, lander.getNumLives());
}

/******************************************
* GAME :: DRAW HORIZONTAL SPEED
* Draws the current horizontal spped 
* and its deriction.
******************************************/
void Game::drawHorizontalSpeed() const
{
	drawText(Point(topLeft.getX() + 160, topLeft.getY() - 30), "HORIZONTAL SPEED");
	drawNumber(Point(bottomRight.getX() - 100, topLeft.getY() - 20),
		std::abs(lander.getVelocity().getDx()) * 10);// * 10 to see it since it adds 0.1, it take a lot of time to change the number
	int rotateH = (lander.getVelocity().getDx() > 0 ? 90 : -90);
	drawShip(Point(bottomRight.getX() - 60, topLeft.getY() - 25), rotateH); //think of it as an arrow
}

/******************************************
* GAME :: DRAW VERTICAL SPEED
* Draws the current vertical spped 
* and its deriction.
******************************************/
void Game::drawVerticalSpeed() const
{
	drawText(Point(topLeft.getX() + 160, topLeft.getY() - 45), "VERTICAL SPEED");
	drawNumber(Point(bottomRight.getX() - 100, topLeft.getY() - 35),
		std::abs(lander.getVelocity().getDy()) * 10);
	int rotateV = (lander.getVelocity().getDy() > 0 ? 180 : 0);
	drawShip(Point(bottomRight.getX() - 60, topLeft.getY() - 40), rotateV); //think of it as an arrow
}

/******************************************
* GAME :: JUST LANDED
* Did we land successfully?
******************************************/
bool Game::justLanded() const
{
	bool landed = false;

	Point platformCenter = ground.getPlatformPosition();
	int width = ground.getPlatformWidth();

	float xDiff = lander.getPoint().getX() - platformCenter.getX(); //center of lander - center of platform
	float yDiff = lander.getPoint().getY() - platformCenter.getY();  //lander y ise the lowest point of lander, platform y is 
																	 //the height of the vertical line of the platform

	float margin = width / 2.0;

	if (fabs(xDiff) < margin)
	{
		// between edges

		if (yDiff < 4 && yDiff >= 0) //rules of the game 4 pixels above is landed
		{
			// right above it

			if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3) //check the speed
			{
				// we're there!
				landed = true;
			}
		}
	}

	return landed;
}

/******************************************
* GAME :: RESET GAME
* Reset game for the new life.
******************************************/
void Game::resetGame()
{
	ground.generateGround();
	lander.reset(Point(bottomRight.getX(), topLeft.getY()));
}

/***************************************
* GAME :: ADVANCE
* advance the game one unit of time
***************************************/
void Game::advance()
{
	if (lander.isAlive())
	{
		if (this->skipFrames != 0)
		{
			this->skipFrames--;
			if (this->skipFrames == 0)
				resetGame();
		}
		else if (!lander.isLanded())
		{
			// advance the lander
			lander.applyGravity(GRAVITY_AMOUNT);
			lander.advance();

			// check for crash (inside the left and right bound not up, and above ground)
			if (!ground.isAboveGround(lander.getPoint()))
			{
				lander.setCrashed(true);
				lander.subtractNumLives(1);
				this->skipFrames = 60; //skip for 60 frames, give the idea like it is paused for 2 sek

				if (lander.getNumLives() == 0)
				{
					lander.setAlive(false);
				}
			}

			// check for just landed
			if (justLanded())
			{
				lander.setLanded(true);
			}
		}
	}
	
}

/***************************************
* GAME :: HANDLE INPUT
* accept input from the user
***************************************/
void Game::handleInput(const Interface & ui)
{
	if (lander.isAlive() && !lander.isLanded())
	{

		if (ui.isDown())
		{
			lander.applyThrustBottom();
		}

		if (ui.isLeft())
		{
			lander.applyThrustLeft();
		}

		if (ui.isRight())
		{
			lander.applyThrustRight();
		}
		if (ui.isUp())
		{
			lander.applyThrustUp();
		}
		
	}
}

/*********************************************
* GAME :: DRAW
* Draw everything on the screen
*********************************************/
void Game::draw(const Interface & ui)
{
	lander.draw();

	if (lander.isLanded())
	{
		drawText(Point(), "You have successfully landed!");
	}
	
	if (lander.isCrashed())
	{
		if (!lander.isAlive())
		{
			drawText(Point(), "Game over! You spent all lives!");
		}
		else
		{
			drawText(Point(),  "You have crashed!");
		}
		
	}
	

	if (lander.canThrust())
	{
		drawLanderFlames(lander.getPoint(), ui.isDown(), ui.isLeft(), ui.isRight());
	}

	if (ui.isUp())
	{
		drawText(Point(topLeft.getX() + 160, topLeft.getY() - 60), "INCREASING GRAVITY");
	}

	Point fuelLocation;
	fuelLocation.setX(topLeft.getX() + 5);
	fuelLocation.setY(topLeft.getY() - 5);
	//draw Fuel
	drawNumber(Point(topLeft.getX() + 5, topLeft.getY() - 5), lander.getFuel());
	
	//draw Lives
	drawLives();

	//draw Altitude
	drawAltitude();

	//draw Horizontal speed
	drawHorizontalSpeed();
	
    //draw Vertical speed
	drawVerticalSpeed();
   
	//draw Ground
	ground.draw();
}

