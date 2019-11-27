/*******************************
 * Gary Sung, Shawn Jacobsen   *
 * RJF 12:40 - SDP Project     *
 * *****************************/

// Preprocessor directives
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "functs.h"

// Proteus Directives
// Proteus is 320 x 240 pixels (min input is 0)
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <LCDColors.h>


// INITS
#define SLEEP 30        // Sleep timing (ms)
#define GRAVITY 1       // Gravity acceleration constant

// Positions
#define PLANEY 200      // Platform height, (PLANEY - 1) = stuff sitting on platform
#define DINOX 52        // Dino position, 40 x 40 pixel grid
#define OBSTX 290		// Obstacle position, obstacle  width is 24 pixels
#define DINORAD 30      // Dino collision radius from central point

// Velocities
#define JUMP_VELY -5    // Dino initial jump velocity
#define OBST_VEL -3     // Obstacle velocity

// Colors
#define GHOSTWHITE		// Dino + Menu
#define SPRINGGREEN		// Cactus
#define	GOLDENROD		// Platform 

/*
Frames Dino
	- 0, Straight Legs
	- 1, Right Leg Up
	- 2, Left Leg Up
	- 3, Eye (Collision)

Frames Cactus
	- 0, Single Mid-size Cactus
	- 1, Double Mid-size Cactus
	- 2, Single Lg-size Cactus

X and Y
	- (x, y) position of object in terms of lower left corner (0, 39) on Excel
		- example: input (5, PLANEY) means that object will sit on platform at x = 5 (6 pixels)
	- (xx, yy) position of the collision circle centerpoint or obstacle orange reference point
		- example: intput (5, PLANEY) into dinoCCC function to calculate collision circle centerpoint
*/

class dino {
    private:
        int theme, frame, x, y, xx, yy, velocity;
        bool onGround;
        bool jumping;
    public:
        dino(int _theme = 0, int _frame = 0, int _x = 0, int _y = 0, int _xx = 0, int _yy = 0, int _velocity = 0, bool _onGround = true, bool _jumping = false);
        void jump(int x, int y);
        void hit();
};

class obstacle {
    private:
        int theme, frame, x, y, xx, yy, velx;
    public:
        obstacle(int _theme = 0, int _frame = 0, int _x = 0, int _y  = PLANEY, int _xx = 0, int _yy = 0, int _velx = OBST_VEL);
};

int main(void) {
	/*
	PASS IN DINOX, OBSTX, and PLANEY into the draw functions
	dino and obstacle are bottom-left aligned (0, 39) in Excel	
	*/
    bool gameLoop = true;       // main flag
    bool collision = false;     // dino collision with obstacle
    dino Dino;
    obstacle Obstacle;
    ButtonBoard Button(FEHIO::FEHIOPort); // button

    // Main Loop
    while (gameLoop) {
        int timeInit = TimeNow();   // (ms)
        // (Possible Solution)
        // while(TimeNow() - timeInit < SLEEP && !Button.MiddlePressed());
        // (Possible Solution)

        // check if dino is on ground, if so begin jump (set vely to JUMP_CONST)
        if (Button.MiddlePressed() && collision (Dino.xx, Dino.yy, Dino.xx, PLANEY, DINORAD)) {
            Dino.velocity = JUMP_VELY;
        }

        if (TimeNow() - timeInit > SLEEP) {
			

            // check collisions
            collision(Dino.xx, Dino.yy, Obstacle.xx, Obstacle.yy, DINORAD);

            // recalculate positions of objects

            // redraw
        }
    }
}

// Dino Constructor
dino::dino(int _theme, int _frame, int _x, int _y, int _xx, int _yy, int _velocity, bool _onGround, bool _jumping) {
	theme		= _theme;
	frame       = _frame;
    x           = _x;
    y           = _y;
	xx			= _xx;
	yy			= _yy;
    velocity    = _velocity;
    onGround    = _onGround;
    jumping     = _jumping;
}

// Obstacle Constructor
obstacle::obstacle (int _theme, int _frame, int _x, int _y, int _xx, int _yy, int _velx, bool _onGround, bool _jumping) {
	theme		= _theme;
	frame		= _frame; 
	x			= _x;
	y			= _y;
	xx			= _xx;
	yy			= _yy;
	velx		= _velx;
	
}


