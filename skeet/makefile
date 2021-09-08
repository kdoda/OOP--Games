###############################################################
# Program:
#     Project 09, Skeet
#     Brother Comeau, CS165
# Author:
#     Klevin Doda
# Summary:
#     Put your summary code here... 
# Above and Beyond
#     Press up arrow to change between: sniper bullet, shotgun
#     bullet, or regular bullet. Shown on the screen what 
#     type of bird is passing and what bullet the user is using.
#     l - to turn on and off laser.
#     s - to draw or not the forest.
#     v - to drop the leaves from the trees.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o bird.o toughBird.o sacredBird.o bullet.o shotgunBullet.o sniperBullet.o flyingObject.o laser.o leaf.o branch.o tree.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o bird.o toughBird.o sacredBird.o bullet.o shotgunBullet.o sniperBullet.o flyingObject.o laser.o leaf.o branch.o tree.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h velocity.h rifle.h bullet.h bird.h toughBird.h sacredBird.h shotgunBullet.h sniperBullet.h flyingObject.h laser.h leaf.h branch.h tree.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
velocity.o: velocity.h velocity.cpp
	g++ -c velocity.cpp
 
flyingObject.o: flyingObject.h flyingObject.cpp point.h velocity.h
	g++ -c flyingObject.cpp
 
bird.o: bird.h bird.cpp point.h velocity.h flyingObject.h uiDraw.h
	g++ -c bird.cpp
 
sacredBird.o: sacredBird.h sacredBird.cpp bird.h point.h velocity.h flyingObject.h uiDraw.h
	g++ -c sacredBird.cpp

toughBird.o: toughBird.h toughBird.cpp bird.h point.h velocity.h flyingObject.h uiDraw.h
	g++ -c toughBird.cpp
 
bullet.o: bullet.h bullet.cpp point.h velocity.h flyingObject.h uiDraw.h
	g++ -c bullet.cpp
 
sniperBullet.o: sniperBullet.h sniperBullet.cpp bullet.h point.h velocity.h flyingObject.h uiDraw.h
	g++ -c sniperBullet.cpp
 
shotgunBullet.o: shotgunBullet.h shotgunBullet.cpp bullet.h point.h velocity.h flyingObject.h uiDraw.h
	g++ -c shotgunBullet.cpp

laser.o: laser.h laser.cpp point.h uiDraw.h
	g++ -c laser.cpp

leaf.o: leaf.h leaf.cpp point.h uiDraw.h
	g++ -c leaf.cpp

branch.o: branch.h branch.cpp point.h uiDraw.h
	g++ -c branch.cpp

tree.o: tree.h tree.cpp point.h uiDraw.h leaf.h branch.h
	g++ -c tree.cpp
 
###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
