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
#define SLEEP 33        // Sleep timing (ms)
#define GRAVITY 2       // Gravity acceleration constant

// Positions
#define PLANEY 200      // Platform height, (PLANEY - 1) = stuff sitting on platform
#define DINOX 20        // Dino position, 40 x 40 pixel grid
#define OBSTX 290		// Obstacle position, obstacle  width is 24 pixels
#define DINORAD 30      // Dino collision radius from central point

// Velocities
#define JUMP_VELY -18   // Dino initial jump velocity
#define OBST_VEL -3     // Obstacle velocity
#define MAXJUMP 80		// Max dino jump height 

// Dino + Menu			GHOSTWHITE		
// Cactus				SPRINGGREEN		
// Platform				GOLDENROD		


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
    public:
		int theme, frame, x, y, velocity, highscore;
		bool jumping;
		dino(int _theme = 0, int _frame = 0, int _x = 0, int _y = 0, int _velocity = 0, int _highscore = 0, bool _jumping = false);
};

class obstacle {
    public:
		int theme, frame, x, y, velx;
        obstacle(int _theme = 0, int _frame = 0, int _x = OBSTX, int _y  = PLANEY, int _xx = 0, int _yy = 0, int _velx = OBST_VEL);
};

int main(void) {
    bool gameLoop = true;					// main flag
    dino Dino;
    obstacle Cacti;
	obstacle Cacdi;
	obstacle Cactri;
	int frontCactus = 0;					// Swich case value to determine the front cactus

    ButtonBoard Button(FEHIO::Bank2);		// Board must be connected to Bank 2 on PROTEUS
    int timeInit = TimeNow();				// (ms)
	float u, v;								// touch positions x, y
	LCD.Touch(&u, &v);
	bool pressReplay;				// while loop condition to check replay

	// Icon at the center of the PROTEUS
	FEHIcon::Icon replay;				// declare icon for the replay option
	replay.SetProperties("REPLAY", 159, 102, 24, 40, GOLDENROD, GOLDENROD);			

    // Main Loop
    while (gameLoop) {
        
        // check if dino is on ground, if so begin jump (set vely to JUMP_CONST)
		// true if buttonboard is pressed, return true if collide
        if (Button.MiddlePressed() && ((Dino.y + 1) == PLANEY) && !Dino.jumping) {
            Dino.velocity = JUMP_VELY;
            Dino.jumping == true;
        }

        if (TimeNow() - timeInit > SLEEP) {
            // reinitialize timeInit for next pass
            timeInit = TimeNow();   // (ms)

			// Determine the front cactus
			if (Cacti.x == OBSTX && Cacdi.x == OBSTX && Cactri.x == OBSTX) { frontCactus = 0; }
			else if (Cacti.x < Cacdi.x && Cacti.x < Cactri.x) { frontCactus = 0; }
			else if (Cacdi.x < Cactri.x && Cacdi.x < Cacti.x) { frontCactus = 1; }
			else if (Cactri.x < Cacti.x && Cactri.x < Cacdi.x) { frontCactus = 2; }
			
			// Check if the dino collided
			switch (frontCactus) {
			case 0: // check Cacti collision
				if (collision(Dino.x, Dino.y, Cacti.frame, Cacti.x, Cacti.y, DINORAD)) {

					// Collided, dino with large eye
					Dino.frame = 3;
					Buzzer.Buzz(100);
					dinodraw(Dino.theme, Dino.frame, Dino.x, Dino.y);
					obstacledraw(Cacti.theme, Cacti.frame, Cacti.x, Cacti.y);
					gameoverdraw();
					replay.Draw();

					// Check if the player wants to replay
					pressReplay = true;
					while (pressReplay) {
						if (replay.Pressed(u, v, 0)) {
							pressReplay = true;
							break;
						}
						else { pressReplay = false; }
					}
				}
			case 1: // check Cacdi collision
				if (collision(Dino.x, Dino.y, Cacdi.frame, Cacdi.x, Cacdi.y, DINORAD)) {

					// Collided, dino with large eye
					Dino.frame = 3;
					Buzzer.Buzz(100);
					dinodraw(Dino.theme, Dino.frame, Dino.x, Dino.y);
					obstacledraw(Cacdi.theme, Cacdi.frame, Cacdi.x, Cacdi.y);
					gameoverdraw();
					replay.Draw();

					// Check if the player wants to replay
					pressReplay = true;
					while (pressReplay) {
						if (replay.Pressed(u, v, 0)) {
							pressReplay = true;
							break;
						}
						else { pressReplay = false; }
					}
				}
			case 2: // check Cactri collision
				if (collision(Dino.x, Dino.y, Cactri.frame, Cactri.x, Cactri.y, DINORAD)) {

					// Collided, dino with large eye
					Dino.frame = 3;
					Buzzer.Buzz(100);
					dinodraw(Dino.theme, Dino.frame, Dino.x, Dino.y);
					obstacledraw(Cactri.theme, Cactri.frame, Cactri.x, Cactri.y);
					LCD.SetFontColor(GHOSTWHITE);
					gameoverdraw();
					replay.Draw();

					// Check if the player wants to replay
					pressReplay = true;
					while (pressReplay) {
						if (replay.Pressed(u, v, 0)) {
							pressReplay = true;
							break;
						}
						else { pressReplay = false; }
					}
				}
			} // End of Switch case for front cactus

			// Check if dino is below, above, or at the platform
			if ((Dino.y + 1) < PLANEY) { Dino.jumping == true; }
			else if ((Dino.y + 1) == PLANEY) { Dino.jumping == false; }
			else { Dino.y == PLANEY - 1; }

			// recalculate positions of objects + Redraw
			// Same dino frame while jumping
			if (Dino.jumping) {
				Dino.y = Dino.y + Dino.velocity;
				
				Cacti.x = Cacti.x + Cacti.velx;
				Cacdi.x = Cacdi.x + Cacdi.velx;
				Cactri.x = Cactri.x + Cactri.velx;
			}
			else {
				// Increment the dino frame
				if (Dino.x == DINOX) { Dino.frame = 0; }
				else if (Dino.frame == 0 && Dino.x != DINOX) { Dino.frame = 1; }
				else if (Dino.frame == 1) { Dino.frame = 2; }
			}

			// Send the cactus back to origin (right side) if x value becomes negative
			if (Cacti.x < 0) { Cacti.x = OBSTX; }
			if (Cacdi.x < 0) { Cacdi.x = OBSTX; }
			if (Cactri.x < 0) { Cactri.x = OBSTX; }

			// Ensure the cactus keeps its frame throughout 
			if (Cacti.x == OBSTX) { Cacti.frame = randomframe(); }
			if (Cacdi.x == OBSTX) { Cacdi.frame = randomframe(); }
			if (Cactri.x == OBSTX) { Cactri.frame = randomframe(); }

			// redraw
			LCD.Clear();
			platformdraw();
			dinodraw(Dino.theme, Dino.frame, Dino.x, Dino.y);
			obstacledraw(Cacti.theme, Cacti.frame, Cacti.x, Cacti.y);
			obstacledraw(Cacdi.theme, Cacdi.frame, Cacdi.x, Cacdi.y);
			obstacledraw(Cactri.theme, Cactri.frame, Cactri.x, Cactri.y);
			
        } // End of check time statement
    } // End of while gameloop statement
} //End of main loop

// Dino Constructor
dino::dino(int _theme, int _frame, int _x, int _y, int _velocity, int _highscore, bool _jumping) {
	theme		= _theme;
	frame       = _frame;
    x           = _x;
    y           = _y;
    velocity    = _velocity;
	highscore	= _highscore;
    jumping     = _jumping;
}

// Cactus Constructor
obstacle::obstacle (int _theme, int _frame, int _x, int _y, int _velx, bool _jumping) {
	theme		= _theme;
	frame		= _frame; 
	x			= _x;
	y			= _y;
	velx		= _velx;
}


