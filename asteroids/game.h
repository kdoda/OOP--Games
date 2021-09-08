/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#define OFF_SCREEN_BORDER_AMOUNT 5
#define BIG_ROCKS_NUM 5
#include <vector>

#include "point.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "ship.h"
#include "rocks.h"
#include "bullet.h"
 /*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
	/*********************************************
	* Constructor
	* Initializes the game
	*********************************************/
	Game(Point tl, Point br)
		: topLeft(tl), bottomRight(br)
	{
		createRocks();
	}
	~Game();

	/*********************************************
	* Function: handleInput
	* Description: Takes actions according to whatever
	*  keys the user has pressed.
	*********************************************/
	void handleInput(const Interface & ui);

	/*********************************************
	* Function: advance
	* Description: Move everything forward one
	*  step in time.
	*********************************************/
	void advance();

	/*********************************************
	* Function: draw
	* Description: draws everything for the game.
	*********************************************/
	void draw(const Interface & ui);
	

private:
	Point topLeft;
	Point bottomRight;

	Ship ship;

	std::vector<Rock*> rocks;
	std::vector<Bullet*> bullets;
	/*************************************************
	* Private methods to help with the game logic.
	*************************************************/
	//TODO - check which should be const
	void advanceRocks();
	void advanceBullets();
	void advanceShip();

	void drawBullets();
	void drawRocks();
	void drawShip();

	void handleCollisionsBulletsRocks();
	void handleCollisionsShipRocks();
	void handleCollisions();

	void cleanUpZombies();
	bool inHorizontalBorders(const Point & point);
	bool inVerticalBorders(const Point & point);
	void keepOnScreen(FlyingObject* flyingObject);
	void createRocks();
	float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
};


#endif /* GAME_H */
