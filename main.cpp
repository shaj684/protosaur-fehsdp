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
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <LCDColors.h>


// INITS
#define SLEEP 30        // sleep timing (ms)
#define GRAVITY 1       // gravity acceleration constant
// Positions
#define PLANEY 200      // platform height
#define DINOX 52        // dino position
#define DINORAD 30      // dino collision radius from central point

// Velocities
#define JUMP_VELY -5    // Dino initial jump velocity
#define OBST_VEL -3     // Obstacle velocity

// colors(subject to change)
#define GHOSTWHITE		// Dino + Menu
#define SPRINGGREEN		// Cactus
#define	GOLDENROD		// Platform 

class dino {
    private:
        int frame, x, y, velocity;
        bool onGround;
        bool jumping;
    public:
        dino(int _frame = 0, int _x = 0, int _y = 0, int _velocity = 0, bool _onGround = true, bool _jumping = false);
        void jump(int x, int y);
        void hit();
};

class obstacle {
    private:
        int frame, theme, x, y, velx;
    public:
        obstacle(int _theme = 0, int _frame = 0, int _x = 0, int _y  = PLANEY, int _velx = OBST_VEL);
};

int main(void) {
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
        if (Button.MiddlePressed() && collision(Dino.x,Dino.y,Dino.x,PLANEY,DINORAD)){
            Dino.velocity = JUMP_VELY;
        }

        if (TimeNow() - timeInit > SLEEP){

            //check collisions
            collision(Dino.x,Dino.y,Obstacle.x,Obstacle.y,DINORAD);

            // recalculate positions of objects

            // redraw
        }
    }
}

// Dino Constructor
dino::dino(int _frame, int _x, int _y, int _velocity, bool _onGround, bool _jumping) {
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

// Check distance
bool collision(int x1, int y1, int x2,int y2, int rad){
    d = abs(  sqrt(  pow(x2-y2,2)+pow(x1-y1,2)  )  );
    if (d < rad){
        //collision occurred
        return true;
    } else {return false;}
}
