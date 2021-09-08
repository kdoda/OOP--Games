/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

/***************************************
* GAME :: DESTRUCTOR
* free the memory
***************************************/
Game::~Game()
{
	//delete rocks
	for (int i = 0;i < rocks.size();++i)
		delete rocks[i];
	//delete bullets
	for (int i = 0;i < bullets.size();++i)
		delete bullets[i];	
}



/***************************************
* GAME :: ADVANCE
* advance the game one unit of time
***************************************/
void Game::advance()
{
	advanceRocks();
	advanceBullets();
	advanceShip();

	handleCollisions();
	cleanUpZombies();
}

/***************************************
* GAME :: HANDLE INPUT
* accept input from the user
***************************************/
void Game::handleInput(const Interface & ui)
{
	//handle the directions of the ship
	if (ui.isLeft())
	{
		ship.rotateLeft();
	}
	if (ui.isRight())
	{
		ship.rotateRight();
	}

	//move ship in the direction it is pointing 
	if (ui.isUp())
	{
		ship.move();
	}

	// shoot bullets
	if (ui.isSpace() && ship.isAlive())
	{
		bullets.push_back(new Bullet(bottomRight, topLeft));
		bullets.back()->fire(ship.getPoint(), ship.getVelocity(), ship.getAngle());
	}
}

/*********************************************
* GAME :: DRAW
* Draw everything on the screen
*********************************************/
void Game::draw(const Interface & ui)
{
	drawRocks();
	drawBullets();
	drawShip();
	
}

/*********************************************
* GAME :: DRAWBULLETS
* Draw the bullets, if they are alive
*********************************************/
void Game::drawBullets()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isAlive())
		{
			bullets[i]->draw();
		}
	}
}

/*********************************************
* GAME :: DRAWBULLETS
* Draw the rocks, if they are alive
*********************************************/
void Game::drawRocks()
{
	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks[i]->isAlive())
		{
			rocks[i]->draw();
		}
	}
}

/*********************************************
* GAME :: DRAWSHIP
* Draw the ship, if it is alive
*********************************************/
void Game::drawShip()
{
	if (ship.isAlive())
	{
		ship.draw();
	}
}


/***************************************
* GAME :: ADVANCE ROCKS
* Go through each rock and advance it.
* If they leave the screen bring them back
***************************************/
void Game::advanceRocks()
{
	// Move each of the bullets forward if it is alive
	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks[i]->isAlive())
		{
			// this rocks is alive, tell it to move forward
			rocks[i]->advance();
		}
	}
}

/***************************************
* GAME :: ADVANCE BULLETS
* Go through each bullet and advance it.
* If they leave the screen bring them back
***************************************/
void Game::advanceBullets()
{
	// Move each of the bullets forward if it is alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isAlive())
		{
			// this bullet is alive, tell it to move forward
			bullets[i]->advance();
		}
	}
}

/***************************************
* GAME :: ADVANCE Ship
* If it leaves the screen bring it back
***************************************/
void Game::advanceShip()
{
	if (ship.isAlive())
	{
		ship.advance();
	}
}


/**************************************************************************
* GAME :: CREATE ROCKS
* Create BIG_ROCKS_NUM rocks witha random postion on the screen 
**************************************************************************/
void Game::createRocks()
{
	for (int i = 0;i < BIG_ROCKS_NUM;++i)
	{
		float randomY = random(bottomRight.getY(), topLeft.getY());
		rocks.push_back(new BigRock(Point(topLeft.getY(), randomY),bottomRight,topLeft));
	}
}

/**************************************************************************
* GAME :: HANDLE COLLISIONS
* Check for a collision between a bird and a bullet.
**************************************************************************/
void Game::handleCollisions()
{
	handleCollisionsShipRocks();
	handleCollisionsBulletsRocks();
}

/**************************************************************************
* GAME :: HANDLE COLLISIONS BULLETS ROCKS
* Check for a collision between bullets and rocks.
**************************************************************************/
void Game::handleCollisionsBulletsRocks()
{
	// check for each bullet if it hits a rock
	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i]->isAlive())
		{
			// this bullet is alive, see if its too close

			// check each rocks is at this point (in case it was hit)
			for (int j = 0; j < rocks.size(); ++j)
			{
				if (rocks[j]->isAlive() && bullets[i]->isAlive())
				{
					// BTW, this logic could be more sophisiticated, but this will
					// get the job done for now...
					if (rocks[j]->getSize() >= getClosestDistance(*bullets[i], *rocks[j])) //if the distance between bullet and the rock is less than the radius
					{
						//we have a hit
						//kill the bullet
						bullets[i]->kill();
						// the rock is dead as well
						rocks[j]->kill(rocks);
					}
				} //if rock is alive

			} //for rocks

		} // if bullet is alive

	} // for bullets
}

/**************************************************************************
* GAME :: HANDLE COLLISIONS SHIP ROCKS
* Check for a collision between the ship and rocks.
**************************************************************************/
void Game::handleCollisionsShipRocks()
{
	//check only is ship is alive, because we still draw when the ship is dead
	if (ship.isAlive()) 
	{
		// now check for a hit (if it is close enough to any live rocks)
		for (int i = 0; i < rocks.size(); i++)
		{
			//need to check again if ship is alive because we add new rock to the array and in the next iteration ship is close to small rocks 
			//and crash them again even though the ship would be dead
			if (rocks[i]->isAlive() && ship.isAlive())
			{
				// this rock is alive, see if its too close

				// BTW, this logic could be more sophisiticated, but this will
				// get the job done for now...
				if (rocks[i]->getSize() + ship.getSize() >= getClosestDistance(ship, *rocks[i])) //if the distance is less thatn the sum of radiuses
				{
					//we have a hit
					//kill the ship
					ship.kill();
					// the rock is dead as well
					rocks[i]->kill(rocks);
				}

			} // if rock is alive

		} // for rocks
	}
}

/**************************************************************************
* GAME :: CLEAN UP ZOMBIES
* Remove any dead objects (take bullets and rock out of the list)
**************************************************************************/
void Game::cleanUpZombies()
{
	
	// Look for dead bullets
	vector<Bullet*>::iterator bulletIt = bullets.begin();
	while (bulletIt != bullets.end())
	{
		Bullet* pBullet = *bulletIt;
	
		if (!pBullet->isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...
			delete pBullet;

			// remove from list and advance
			bulletIt = bullets.erase(bulletIt);
		}
		else
		{
			++bulletIt; // advance
		}
	}

	// Look for dead rocks
	vector<Rock*>::iterator rockIt = rocks.begin();
	while (rockIt != rocks.end())
	{
		Rock* pRock = *rockIt;

		if (!pRock->isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...
			delete pRock;

			// remove from list and advance
			rockIt = rocks.erase(rockIt);
		}
		else
		{
			++rockIt; // advance
		}
	}
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}

