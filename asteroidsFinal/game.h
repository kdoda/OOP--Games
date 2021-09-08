/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#define OFF_SCREEN_BORDER_AMOUNT 5
#define BIG_ROCKS 5
#define STARS 200
#include <vector>

#include "point.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "star.h"
#include "flyingObject.h"
#include "bullet.h"
#include "rocks.h"
#include "ship.h"
#include "firework.h"
#include "bomb.h"
#include "laser.h"

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
		: topLeft(tl), bottomRight(br), showStars(false), wonGame(false), ship(Point(0, 0), bottomRight, topLeft)
	{
		createStars();
		createRocks();
		laser.kill();
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
	Laser laser;

	bool showStars; //press 'r' to showStars on the screen
	bool wonGame;   //did the player killed all the rocks

	std::vector<Firework*> fireworks;
	std::vector<Star*> stars;
	std::vector<Rock*> rocks;
	std::vector<Bullet*> bullets;
	std::vector<Bomb*> bombs;
	/*************************************************
	* Private methods to help with the game logic.
	*************************************************/
	//TODO - check which should be const
	void advanceRocks();
	void advanceBullets();
	void advanceStars();
	void advanceShip();
	void advanceFireworks();
	void advanceBombs();
	void advanceLaser();
	
	void drawBullets();
	void drawRocks();
	void drawStars();
	void drawShip();
	void drawFireworks();
	void drawBombs();
	void drawLaser();
	
	void handleCollisionsBulletsRocks();
	void handleCollisionsShipRocks();
	void handleCollisionsLaserRocks();
	void handleCollisions();

	void killRock(Rock* rock);
	void cleanUpZombies();
	void createRocks();
	void createStars();
	float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
	bool laserHitRock(Rock *rock);
	bool between(float a, float b, float c);
};


#endif /* GAME_H */
