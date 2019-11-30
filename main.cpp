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
#include <FEHRandom.h>
#include <FEHBuzzer.h>


// INITS
#define SLEEP 30        // Sleep timing (ms)
#define GRAVITY 1       // Gravity acceleration constant

// Positions
#define PLANEY 200      // Platform height, (PLANEY - 1) = stuff sitting on platform
#define DINOX 20        // Dino position, 40 x 40 pixel grid
#define OBSTX 290		// Obstacle position, obstacle  width is 24 pixels
#define DINORAD 30      // Dino collision radius from central point

// Velocities
#define JUMP_VELY -5    // Dino initial jump velocity
#define OBST_VEL -3     // Obstacle velocity
#define MAXJUMP 80		// Max dino jump height 

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
		- example: input (5, PLANEY) into collision function to calculate collision circle centerpoint
*/

class dino {
    private:
        int theme, frame, x, y, velocity;
        bool onGround;
        bool jumping;
    public:
        dino(int _theme = 0, int _frame = 0, int _x = 0, int _y = 0, int _velocity = 0, bool _onGround = true, bool _jumping = false);
        void jump(int x, int y);
        void hit();
};

class obstacle {
    private:
        int theme, frame, x, y, velx;
    public:
        obstacle(int _theme = 0, int _frame = 0, int _x = 0, int _y  = PLANEY, int _xx = 0, int _yy = 0, int _velx = OBST_VEL);
};

int main(void) {
	/*
	PASS IN values in terms of DINOX, OBSTX, and PLANEY into the draw functions
	dino and obstacle function inputs are bottom left corner of Excel image	
	*/
    bool gameLoop = true;       // main flag
    bool collision = false;     // dino collision with obstacle
    dino Dino;
    obstacle Obstacle;
    ButtonBoard Button(FEHIO::Bank2); // Board must be connected to Bank 2 on PROTEUS
    int timeInit = TimeNow();   // (ms)
    // Main Loop
    while (gameLoop) {
        
        // (Possible Solution)
        // while(TimeNow() - timeInit < SLEEP && !Button.MiddlePressed());
        // (Possible Solution)

        // check if dino is on ground, if so begin jump (set vely to JUMP_CONST)
		// true if buttonboard is pressed, return true if collide
        if (Button.MiddlePressed() && ((Dino.y + 1) == PLANEY) && !Dino.jumping) {
            Dino.velocity = JUMP_VELY;
            Dino.jumping == true;
        }

        if (TimeNow() - timeInit > SLEEP) {
            // reinitialize timeInit for next pass
            timeInit = TimeNow();   // (ms)

            // check obstacle collision
			if (collision(Dino.x, Dino.y, Obstacle.frame, Obstacle.x, Obstacle.y, DINORAD)) {
				
				// Collided, dino with large eye
				Dino.frame = 3;
				Buzzer.Buzz(100);		
				dinodraw(Dino.theme, Dino.frame, Dino.x, Dino.y);
				obstacledraw(Obstacle.theme, Obstacle.frame, Obstacle.x, Obstacle.y);

			} else {

				// Check if dino is below, above, or at the platform
				if ((Dino.y + 1) < PLANEY) { Dino.jumping == true; } 
				else if ((Dino.y + 1) == PLANEY) { Dino.jumping == false; }
				else { Dino.y == PLANEY - 1; }  

				// recalculate positions of objects + Redraw
				// Same dino frame while jumping
				if (Dino.jumping) {
					Dino.y = Dino.y + Dino.velocity;
					Obstacle.x = Obstacle.x + Obstacle.velx;
				}
				else {
					if (Dino.frame < 2) { Dino.frame++; }
					else { Dino.frame = 0; }
				}

				// redraw
				LCD.clear();
				platformdraw();
				dinodraw(Dino.theme, Dino.frame, Dino.x, Dino.y);
				obstacledraw(Obstacle.theme, randomframe(), Obstacle.x, Obstacle.y);

			} // End of check collision Else statement
        } // End of check time statement
    } // End of while gameloop statement
}

// Dino Constructor
dino::dino(int _theme, int _frame, int _x, int _y, int _velocity, bool _onGround, bool _jumping) {
	theme		= _theme;
	frame       = _frame;
    x           = _x;
    y           = _y;
    velocity    = _velocity;
    onGround    = _onGround;
    jumping     = _jumping;
}

// Obstacle Constructor
obstacle::obstacle (int _theme, int _frame, int _x, int _y, int _velx, bool _onGround, bool _jumping) {
	theme		= _theme;
	frame		= _frame; 
	x			= _x;
	y			= _y;
	velx		= _velx;
}


