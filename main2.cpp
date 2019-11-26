/*******************************
 * Gary Sung, Shawn Jacobsen   *
 * RJF 12:40 - SDP Project     *
 * *****************************/

// Preprocessor directives
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/*
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHLCD.h>
*/
#define SLEEP 30        // sleep timing (ms)
#define gravity 1       // gravity acceleration constant
//Positions
#define PLANEY 200      // platform height
#define DINOX 40        // dino position
// Velocities
#define JUMP_VELY -5    // Dino initial jump velocity
#define OBST_VEL -3     // Obstacle velocity

class dino {
    private:
        int frame, x, y, vely;
        bool onGround;
        bool jumping;
    public:
        dino(int _frame = 0, int _x = DINOX, int _y = PLANEY, int _vely = 0, bool _onGround = true, bool _jumping = true);
        void jump(int x, int y);
        void hit();
};

class obstacle {
    private:
        int x, y, velx;
    public:
        obstacle(int _x, int _y  = PLANEY, int _velx = OBST_VEL);
};

int main(void) {

    // initial game conditions
    bool gameLoop = true;
    bool collision = false;
    dino Dino;
    obstacle Obstacle;

    // Main Loop
    while(gameLoop){

        //check collisions, check input, redraw, repeat

    }

    /* Default code from QT Creator project init
    float x,y;

    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    while( true )
    {
        if( LCD.Touch(&x,&y) )
        {
            LCD.WriteLine( "Hello World!" );
            Sleep( 100 );
        }
    }
    return 0;
    */
}

// Dino Constructor
dino::dino(int _frame, int _x, int _y, int _vely, bool _onGround, bool _jumping){
    frame       = _frame;
    x           = _x;
    y           = _y;
    vely        = _vely;
    onGround    = _onGround;
    jumping     = _jumping;
}

// Obstacle Constuctor
obstacle::obstacle(int _x, int _y, int _velx){
    x       = _x;
    y       = _y;
    velx    = _velx;
    
// Jump function
void jump(int x, int y) {

}

// Dino collides with obstacle
void hit() {

}