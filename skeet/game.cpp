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

#include "game.h"
#include <cassert>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br), rifle(br), dropLeaves(false), showForest(false)
{
   // Set up the initial conditions of the game
   score = 0;

   // TODO: Set your bird pointer to a good initial value (e.g., NULL)
   bird = NULL;
   bulletType = 0;
   laser.kill();
   
   createForest();
   
}

/****************************************
* GAME :: CREATE FOREST
****************************************/
void Game::createForest()
{
	forest.push_back(new Tree(topLeft, bottomRight, 15, 50, 100, PI / 9, -PI / 9));
	forest.push_back(new Tree(topLeft, bottomRight, 23, 200, 80, PI / 9, -PI / 9));
	forest.push_back(new Tree(topLeft, bottomRight, 30, 350, 120, PI / 12, -PI / 12));
}


/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
	if (bird != NULL)
		delete bird;

	for (int i = 0;i < forest.size();++i)
		delete forest[i];
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceBird();
   advanceLaser();

   if (dropLeaves)
   {
	   advanceForest();
   }

   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i]->isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i]->advance();
         
         if (!isOnScreen(bullets[i]->getPoint()))
         {
            // the bullet has left the screen
            bullets[i]->kill();
         }
         
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceBird()
{
   if (bird == NULL)
   {
      // there is no bird right now, possibly create one
      
	  //this is a delay up to 1 sec with a prob since 30 frames pass a sec
      // "resurrect" it will some random chance
      if (random(0, 30) == 0) //with some probability because we do not want 
      {                       //every time we kill a bird the next one to generate immediately
		                      //we want to time to look random.
         // create a new bird
         bird = createBird();
      }
   }
   else
   {
      // we have a bird, make sure it's alive
      if (bird->isAlive())
      {
         // move it forward
         bird->advance();
         
         // check if the bird has gone off the screen
         if (!isOnScreen(bird->getPoint()))
         {
            // We have missed the bird
            bird->kill();
         }
      }
   }
   
}

/***************************************
* GAME :: ADVANCE Laser
* Advance laser if it is alive
***************************************/
void Game::advanceLaser()
{
	if (laser.isAlive())
	{
		laser.advance(rifle.getPoint() , rifle.getAngle());
	}
}

/***************************************
* GAME :: ADVANCE Leaves
* Advance leaves if it alive
***************************************/
void Game::advanceForest()
{
	for (int i = 0;i < forest.size();++i)
		forest[i]->advance();
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
Bird* Game :: createBird()
{
	Bird* newBird = NULL;

	// TODO: Fill this in
	int randomBird = random(0, 3);
	assert(0 <= randomBird && randomBird <= 2);

	switch (randomBird)
	{
	case 0:
		newBird = new Bird();
		break;
	case 1:
		newBird = new ToughBird();
		break;
	case 2:
		newBird = new SacredBird();
		break;
	}

	float randomAltitude = random(bottomRight.getY(), topLeft.getY() + 1);
	newBird->setPoint(Point(topLeft.getX(), randomAltitude)); //startpos
	int middle = (topLeft.getY() + bottomRight.getY()) / 2;
	bool up = (randomAltitude <= middle); //up: if should go up

	newBird->randomVelocity(up);

	return newBird;
}

/**************************************************************************
* GAME :: CREATE Bullet
* Create a bulllet based on users current choice 
**************************************************************************/
Bullet* Game::createBullet()
{
	assert(0 <= bulletType && bulletType < BULLET_TYPES);
	Bullet* newBullet = NULL;


	switch (bulletType)
	{
	case 0:
		newBullet = new Bullet();
		break;
	case 1:
		newBullet = new ShotgunBullet();
		break;
	case 2:
		newBullet = new SniperBullet();
		break;
	}

	return newBullet;
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i]->isAlive())
      {
         // this bullet is alive, see if its too close

         // check if the bird is at this point (in case it was hit)
         if (bird != NULL && bird->isAlive())
         {
            // BTW, this logic could be more sophisiticated, but this will
            // get the job done for now...
            if (fabs(bullets[i]->getPoint().getX() - bird->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i]->getPoint().getY() - bird->getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!
               
               // hit the bird
               int points = bird->hit();
               score += points;
               
               // the bullet is dead as well
               bullets[i]->kill();
            }
         }
      } // if bullet is alive
      
   } // for bullets

   handleCollisionsLaserBird();
}

/**************************************************************************
* GAME :: HANDLE COLLISIONS
* Check for a collision between a bird and the laser.
**************************************************************************/
void Game::handleCollisionsLaserBird()
{
	if (laser.isAlive())
	{
		if (bird != NULL && bird->isAlive() && laserHitBird())
		{
			// hit the bird
			int points = bird->hit();
			score += points;
		}
	}
}

bool Game::laserHitBird()
{
	//(y-y1)/(y2-y1) == (x-x1)/(x2-x1)
	//y = kx + b

	float y  = bird->getPoint().getY();
	float x  = bird->getPoint().getX();
	float y1 = laser.getStartPoint().getY();
	float x1 = laser.getStartPoint().getX();
	float y2 = laser.getEndPoint().getY();
	float x2 = laser.getEndPoint().getX();

	float k = (y2 - y1) / (x2 - x1);
	float b = y1 - k*x1;
	float tolerance = 15.0; //because the float precision fails

	//cout << abs(y - (k*x + b)) << "  Y:" << y << " X:" << x << " Y1:" << y1 << " X1:" << x1 << " Y2:" << y2 << " X2:" << x2 << endl;
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
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // check for dead bird
   if (bird != NULL && !bird->isAlive())
   {
      // the bird is dead, but the memory is not freed up yet   
      // TODO: Clean up the memory used by the bird
	   delete bird;
	   bird = NULL;
 
   }
   
   // Look for dead bullets
   vector<Bullet*>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet* pBullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
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
} 

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      rifle.moveLeft();
   }
   
   if (ui.isRight())
   {
      rifle.moveRight();
   }

   if (ui.isUp())
   {
	   bulletType = (bulletType + 1) % BULLET_TYPES;
   }
   
   // Check for Spacebar
   if (ui.isSpace())
   {
      Bullet* newBullet = createBullet(); //create new bullet here
      newBullet->fire(rifle.getPoint(), rifle.getAngle());
      
      bullets.push_back(newBullet);
   }

   //shoot Laser
   if (ui.isL())
   {
	   if (laser.isAlive())
		   laser.kill();
	   else
		   laser.resurrect();
   }

   //drop the leaves from the trees if it is V
   if (ui.isV() && showForest)
   {
	   dropLeaves = true;
   }

   //show or not the forest
   if (ui.isS())
   {
	   showForest = !showForest;
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
	if (bird != NULL && bird->isAlive())
		bird->draw();
  
   // draw the rifle
   rifle.draw();
   drawLaser();
   
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i]->isAlive())
      {
         bullets[i]->draw();
      }
   }
   
   if (showForest)
   {
	   drawForest(); 
   }
   

   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
   
   drawNumber(scoreLocation, score);
   drawBirdName();
   drawBulletName();
}

/*********************************************
* GAME :: Draw bird name on the screen
*********************************************/
void Game::drawBirdName()
{
	if(bird!=NULL)
	drawText(Point(bottomRight.getX() - 100, topLeft.getY() - 15), bird->getName().c_str());
}

/*********************************************
* GAME :: Draw bullet name on the screen
*********************************************/
void Game::drawBulletName()
{
	if(!bullets.empty())
	drawText(Point(bottomRight.getX() - 100, topLeft.getY() - 28), bullets.back()->getName().c_str());
}

/*********************************************
* GAME :: DRAWLASER
* Draw the laser, if it is alive
*********************************************/
void Game::drawLaser()
{
	if (laser.isAlive())
	{
		laser.draw();
	}
}

/*********************************************
* GAME :: DRAWFOREST
*********************************************/
void Game::drawForest()
{
	for (int i = 0;i < forest.size();++i)
		forest[i]->draw();
}
