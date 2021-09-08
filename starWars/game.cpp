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
//aaaaaaaaaaa
/***************************************
* GAME :: DESTRUCTOR
* free the memory
***************************************/
Game::~Game()
{
	//delete fireworks
	for (int i = 0;i < fireworks.size();++i)
		delete fireworks[i];
	//delete stars
	for (int i = 0;i < stars.size();++i)
		delete stars[i];
	//delete rocks
	for (int i = 0;i < rocks.size();++i)
		delete rocks[i];
	//delete bullets
	for (int i = 0;i < bullets.size();++i)
		delete bullets[i];
	//delete bombs
	for (int i = 0;i < bombs.size();++i)
		delete bombs[i];
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
	advanceBombs();
	advanceLaser();

	if (showStars)
	{
		advanceStars();
	}
	
	if (wonGame)
	{
		advanceFireworks();
	}

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

	// shoot bombs
	if (ui.isB() && ship.isAlive())
	{
		bombs.push_back(new Bomb(bottomRight, topLeft));
		bombs.back()->fire(ship.getPoint(), ship.getVelocity(), ship.getAngle());
	}

	//showStars or turn them of
	if (ui.isR())
	{
		showStars = !showStars;
	}

	//shoot Laser
	if (ui.isL())
	{
		if (laser.isAlive())
			laser.kill();
		else
			laser.resurrect();	
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
	drawBombs();
	drawLaser();

	if (showStars)
	{
		drawStars();
	}
	
	if (wonGame)
	{
		Point textPosition(topLeft.getX() + 100, topLeft.getY() + bottomRight.getY());
		drawText(textPosition, "YOU WON! CONGRATULATIONS!");
		drawFireworks();
	}

	if (!ship.isAlive() && !wonGame)
	{
		Point textPosition(topLeft.getX() + 130, topLeft.getY() + bottomRight.getY());
		drawText(textPosition, "GAME OVER! LOSER!");
	}
}

/*********************************************
* GAME :: DRAWBULLETS
* Draw the bullets, if they are alive
*********************************************/
void Game::drawBullets()
{
	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i]->isAlive())
		{
			bullets[i]->draw();
		}
	}
}

/*********************************************
* GAME :: DRAWROCKS
* Draw the rocks, if they are alive
*********************************************/
void Game::drawRocks()
{
	for (int i = 0; i < rocks.size(); ++i)
	{
		if (rocks[i]->isAlive())
		{
			rocks[i]->draw();
		}
	}
}

/*********************************************
* GAME :: DRAWSTARS
*********************************************/
void Game::drawStars()
{
	for (int i = 0; i < stars.size(); ++i)
	{
		stars[i]->draw();
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

/*********************************************
* GAME :: DRAWFIREWORKS
* Draw the fireworks, if they are alive
*********************************************/
void Game::drawFireworks()
{
	for (int i = 0; i < fireworks.size(); ++i)
	{
		if (fireworks[i]->isAlive())
		{
			fireworks[i]->draw();
		}
	}
}

/*********************************************
* GAME :: DRAWBOBMS
* Draw the bombs, if they are alive
*********************************************/
void Game::drawBombs()
{
	for (int i = 0; i < bombs.size(); ++i)
	{
		if (bombs[i]->isAlive())
		{
			bombs[i]->draw();
		}
	}
}

/*********************************************
* GAME :: DRAWLASER
* Draw the laser, if it is alive
*********************************************/
void Game::drawLaser()
{
	if (laser.isAlive() && ship.isAlive())
	{
		laser.draw();
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
	for (int i = 0; i < rocks.size(); ++i)
	{
		if (rocks[i]->isAlive())
		{
			// this rocks is alive, tell it to move forward
			rocks[i]->advance();
		}
	}

	if (rocks.empty())
	   wonGame = true;
}

/***************************************
* GAME :: ADVANCE BULLETS
* Go through each bullet and advance it.
* If they leave the screen bring them back
***************************************/
void Game::advanceBullets()
{
	// Move each of the bullets forward if it is alive
	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i]->isAlive())
		{
			// this bullet is alive, tell it to move forward
			bullets[i]->advance();
		}
	}
}

/***************************************
* GAME :: ADVANCE STARS
* Go through each star and advance it.
* If they leave the screen bring them back
***************************************/
void Game::advanceStars()
{
	for (int i = 0; i < stars.size(); ++i)
	{
		stars[i]->advance();
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

/***************************************
* GAME :: ADVANCE Laser
* Advance laser if it is alive
***************************************/
void Game::advanceLaser()
{
	if (laser.isAlive() && ship.isAlive())
	{
		laser.advance(ship.getPoint(),ship.getAngle());
	}
}

/***************************************
* GAME :: ADVANCE Fireworks
* create fireworks with a probability
* and advance them.
***************************************/
void Game::advanceFireworks()
{
	//create a firework with a probability
	if (random(0.0, 1.0) < 0.02)
	{
		float x = random(topLeft.getX(), bottomRight.getX());
		float y = bottomRight.getY();
		fireworks.push_back(new Firework(x, y));
	}


	for (int i = 0; i < fireworks.size(); ++i)
	{
		if(fireworks[i]->isAlive())
		   fireworks[i]->advance();
	}
}

/***************************************
* GAME :: ADVANCE BOMBS
* Go through each bomb and advance it.
***************************************/
void Game::advanceBombs()
{
	for (int i = 0; i < bombs.size(); ++i)
	{
		if (bombs[i]->isAlive())
		{
			bombs[i]->advance();
		
			if (!bombs[i]->isAlive()) //if this bombs explade
			{
				for (int j = 0, angle = 0;j < 20; ++j, angle += 18) // create 20 bullets from that bomb
				{
					bullets.push_back(new Bullet(bottomRight,topLeft));
					bullets.back()->fire(bombs[i]->getPoint(), bombs[i]->getVelocity(), angle);
				}
			}
		}  
	}
}


/**************************************************************************
* GAME :: CREATE ROCKS
* Create BIG_ROCKS num rocks with a random postion on the screen 
**************************************************************************/
void Game::createRocks()
{
	for (int i = 0;i < BIG_ROCKS;++i)
	{
		float randomY = random(bottomRight.getY(), topLeft.getY());
		rocks.push_back(new BigRock(Point(topLeft.getY(), randomY),bottomRight, topLeft));
	}
}

/**************************************************************************
* GAME :: CREATE STARS
* Create STARS num START with a random postion on the screen
**************************************************************************/
void Game::createStars()
{
	for (int i = 0;i < STARS;++i)
	{
		stars.push_back(new Star(bottomRight, topLeft));
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
	handleCollisionsLaserRocks();
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
						killRock(rocks[j]);
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
	//TODO - beyond and above make it desplay game over when ship is dead

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
					killRock(rocks[i]);
				}

			} // if rock is alive

		} // for rocks
	}
}

/**************************************************************************
* GAME :: HANDLE COLLISIONS LASER ROCKS
* Check for a collision between the laser and rocks.
**************************************************************************/
void Game::handleCollisionsLaserRocks()
{
	if (laser.isAlive())
	{
		//becase when I kill the rocks the new ones ahve the same pos and they are killed automatically because they are in the same line
		// by saving the size I dont loop through the new created rocks
		int size = rocks.size(); //or start from the end 
		for (int i = 0; i < size; ++i)
		{
			if (rocks[i]->isAlive() && laserHitRock(rocks[i]))
			{
				killRock(rocks[i]); //the rock died
			}
		}
	}
}

bool Game::laserHitRock(Rock *rock)
{ 
	//(y-y1)/(y2-y1) == (x-x1)/(x2-x1)
	//y = kx + b
	
	float y  = rock->getPoint().getY();
	float x  = rock->getPoint().getX();
	float y1 = laser.getStartPoint().getY();
	float x1 = laser.getStartPoint().getX();
	float y2 = laser.getEndPoint().getY();
	float x2 = laser.getEndPoint().getX();
	
	float k = (y2 - y1) / (x2 - x1);
	float b = y1 - k*x1;
	float tolerance  = 15.0; //because the float precision fails

	if (abs(y - (k*x + b)) < tolerance) //if rock point is in the line
	{
		//since is in the line, check if it is inside the line
		if (between(x, x1, x2) && between(y, y1, y2)) //or return between 
		{
			return true;
		}
	}

	return false;
	//you could do all this in a single return but for clearity
}

/**************************************************************************
* GAME :: BETWEEN
* Check if a is between b and c
**************************************************************************/
bool Game::between(float a, float b, float c)
{
	return ((b <= a && a <= c) || (c <= a && a <= b));
}

/**************************************************************************
* GAME :: CLEAN UP ZOMBIES
* Remove any dead objects (take bullets and rock out of the list)
**************************************************************************/
void Game::cleanUpZombies()
{
	//TODO this is O(n), I can make it O(1), ask Comeau

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

	// Look for dead fireworks
	vector<Firework*>::iterator fireworkIt = fireworks.begin();
	while (fireworkIt != fireworks.end())
	{
		Firework* pFirework = *fireworkIt;

		if (!pFirework->isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...
			delete pFirework;

			// remove from list and advance
			fireworkIt = fireworks.erase(fireworkIt);
		}
		else
		{
			++fireworkIt; // advance
		}
	}

	// Look for dead bombs
	vector<Bomb*>::iterator bombIt = bombs.begin();
	while (bombIt != bombs.end())
	{
		Bomb* pBomb = *bombIt;

		if (!pBomb->isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...
			delete pBomb;

			// remove from list and advance
			bombIt = bombs.erase(bombIt);
		}
		else
		{
			++bombIt; // advance
		}
	}
}

/**************************************************************************
* GAME :: KILL ROCK
* Kill rock and add new rocks according to the instructions
**************************************************************************/
void Game::killRock(Rock* rock)
{
	string name = rock->getName();
	Velocity velocity = rock->getVelocity();

	if (name == "BigRock")
	{
		velocity.addDy(1);
		rocks.push_back(new MediumRock(rock->getPoint(), velocity, rock->getAngle(), bottomRight, topLeft)); //medium 1

		velocity.addDy(-2); //since we added 1 up we subtract 2 down now
		rocks.push_back(new MediumRock(rock->getPoint(), velocity, rock->getAngle(), bottomRight, topLeft)); //medum 2

		velocity.addDy(1); //undo changes
		velocity.addDx(2); //2 to the right
		rocks.push_back(new SmallRock(rock->getPoint(), velocity, rock->getAngle(), bottomRight, topLeft)); //small
	}
	else if (name == "MediumRock")
	{
		velocity.addDx(3);
		rocks.push_back(new SmallRock(rock->getPoint(), velocity, rock->getAngle(), bottomRight, topLeft)); //small 1


		velocity.addDx(-6); //since we added 3 right we subtract -6 now, to go 3 left
		rocks.push_back(new SmallRock(rock->getPoint(), velocity, rock->getAngle(), bottomRight, topLeft)); //small 2
	}

	//if small just kill
	rock->kill();
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

