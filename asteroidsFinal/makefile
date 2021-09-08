###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Comeau, CS165
# Author:
#     Klevin Doda
# Summary:
#     Put your summary code here... 
# Above and Beyond
#     Press for:
#     b - bomb
#     l - laser
#     r - starfield
#     win game to display fireworks ( its easy to win use bomb 
#     and laser)
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o orientedObject.o flyingObject.o ship.o bullet.o rocks.o firework.o particles.o PVector.o star.o laser.o bomb.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o orientedObject.o flyingObject.o ship.o bullet.o rocks.o firework.o particles.o PVector.o star.o laser.o bomb.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h orientedObject.h flyingObject.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp ship.h orientedObject.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

bomb.o: bomb.cpp bomb.h bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bomb.cpp

rocks.o: rocks.cpp rocks.h orientedObject.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp

star.o: star.cpp star.h point.h uiDraw.h
	g++ -c star.cpp

PVector.o: PVector.cpp PVector.h uiDraw.h
	g++ -c PVector.cpp
 
particles.o: particles.cpp particles.h PVector.h uiDraw.h RGB.h
	g++ -c particles.cpp

firework.o: firework.cpp firework.h particles.h PVector.h uiDraw.h RGB.h
	g++ -c firework.cpp

laser.o: laser.cpp laser.h point.h uiDraw.h
	g++ -c laser.cpp

orientedObject.o: orientedObject.cpp orientedObject.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c orientedObject.cpp
###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
