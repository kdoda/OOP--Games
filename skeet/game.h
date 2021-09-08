/*************************************************************
 * File: game.h
 * Author: Br. Burton
 *
 * Description: The game of Skeet. This class holds each piece
 *  of the game (birds, bullets, rifle, score). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#ifndef GAME_H
#define GAME_H


#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "rifle.h"

#include "flyingObject.h"
#include "bullet.h"
#include "shotgunBullet.h"
#include "sniperBullet.h"
#include "bird.h"
#include "toughBird.h"
#include "sacredBird.h"
#include "laser.h"
#include "branch.h"
#include "leaf.h"
#include "tree.h"

#define CLOSE_ENOUGH 15
#define BULLET_TYPES 3
#define PI 3.14159265358 

#include <vector>
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
   Game(Point tl, Point br);
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
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   
   int score;
   
   bool dropLeaves;
   bool showForest;
   
   Laser laser;
   Rifle rifle;
   std::vector<Tree*> forest; 
   std::vector<Bullet*> bullets;
   int bulletType; //which bullet has the user chose  0<=bulletType<Bullet_types
   Bird * bird;

   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   bool isOnScreen(const Point & point);
   void advanceBird();
   void advanceBullets();
   void advanceLaser();
   void advanceForest();
   
   Bird* createBird();
   Bullet* createBullet();
  
   void createForest();

   void handleCollisions();
   void handleCollisionsLaserBird();
   bool laserHitBird();
   bool between(float a, float b, float c);
   void cleanUpZombies();

   void drawBirdName();
   void drawBulletName();
   void drawLaser();
   void drawForest();
};

#endif /* GAME_H */
