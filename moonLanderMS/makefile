###############################################################
# Program:
#     Milestone 06, Moon Lander
#     Brother Comeau, CS165
# Author:
#     Klevin Doda
# Summary:
#     Displays lander on the screen and allows user to 
#     interact with the game by moving lander on the screen
# Above and Beyond
#     For above and beyond:
#     User has 3 lives which are displayed on the screen
#     which live is he currently using. When crashes and its not
#     its last life, You have crashed is displayed on the screen
#     when crashes for the last life, game over is displayed.
#     Added thrust up, to increase vertical speed down.
#     During the game is displayed the lander's altitutude
#     horizontal velocity and the direction, vertical velocity
#     and the direction.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o 
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o  $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h lander.h velocity.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp
 
lander.o: lander.cpp lander.h
	g++ -c lander.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
