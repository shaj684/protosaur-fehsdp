#ifndef FUNCTS_H
#define FUNCTS_H

#endif // FUNCTS_H

// Preprocessor directives
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <cmath>

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
#define JUMP_VELY -18    // Dino initial jump velocity
#define OBST_VEL -3     // Obstacle velocity
#define MAXJUMP 80		// Max dino jump height 

using namespace std;

// Check distance
bool collision(int dinox, int dinoy, int obstFrame, int obstx, int obsty, int rad) {
	int dinoxx = 0; int dinoyy = 0;
	int obstxx = 0; int obstyy = 0;
	
	// Calculate obstacle orange reference point 
	switch (obstFrame) {
	case 0:
		obstxx = obstx + 4;
		obstyy = obsty - 29;
		break;
	case 1:
		obstxx = obstx + 4;
		obstyy = obsty - 33;
		break;
	case 2:
		obstxx = obstx + 5;
		obstyy = obsty - 39;
		break;
	default:
		break;
	}

	// Calculate dino collision circle centerpoint
	dinoxx = dinox + 9;
	dinoyy = dinoy - 30;

	// change in positions
	int changeX = dinoxx - obstxx;
	int changeY = dinoyy - obstyy;

	int d = abs(sqrt(pow(changeX, 2) + pow(changeY, 2)));
	if (d < rad) {

		//collision occurred
		return 1;
	}
	else { return 0; }
}

void platformdraw() {
	LCD.SetFontColor(GOLDENROD);
	LCD.DrawHorizontalLine(PLANEY, 0, 319);
}

void dinodraw(int theme, int frame, int x, int y) {
	LCD.SetFontColor(GHOSTWHITE);
	// Protosaur: Theme = 0
	// Input (x, y) is lower left corner of Excel sketch
	// Adjust input to draw dino
	x = x - 0;
	y = y - 39;

	LCD.DrawHorizontalLine(0 + y, 22 + x, 37 + x);		// Top Head
	LCD.DrawHorizontalLine(1 + y, 22 + x, 37 + x);
	LCD.DrawHorizontalLine(2 + y, 20 + x, 39 + x);

	LCD.DrawHorizontalLine(3 + y, 20 + x, 23 + x);		// Eye
	LCD.DrawHorizontalLine(3 + y, 26 + x, 39 + x);
	LCD.DrawHorizontalLine(4 + y, 20 + x, 23 + x);
	LCD.DrawHorizontalLine(4 + y, 26 + x, 39 + x);

	LCD.DrawHorizontalLine(5 + y, 20 + x, 39 + x);		// Mid Head
	LCD.DrawHorizontalLine(6 + y, 20 + x, 39 + x);
	LCD.DrawHorizontalLine(7 + y, 20 + x, 39 + x);
	LCD.DrawHorizontalLine(8 + y, 20 + x, 39 + x);
	LCD.DrawHorizontalLine(9 + y, 20 + x, 39 + x);
	LCD.DrawHorizontalLine(10 + y, 20 + x, 39 + x);

	LCD.DrawHorizontalLine(11 + y, 20 + x, 28 + x);		// Mouth
	LCD.DrawHorizontalLine(12 + y, 20 + x, 28 + x);
	LCD.DrawHorizontalLine(13 + y, 20 + x, 34 + x);

	LCD.DrawHorizontalLine(14 + y, 0 + x, 1 + x);
	LCD.DrawHorizontalLine(14 + y, 18 + x, 34 + x);
	LCD.DrawHorizontalLine(15 + y, 0 + x, 1 + x);
	LCD.DrawHorizontalLine(15 + y, 18 + x, 27 + x);

	LCD.DrawHorizontalLine(16 + y, 0 + x, 1 + x);		// Neck + Tail
	LCD.DrawHorizontalLine(16 + y, 15 + x, 27 + x);	
	LCD.DrawHorizontalLine(17 + y, 0 + x, 1 + x);
	LCD.DrawHorizontalLine(17 + y, 15 + x, 27 + x);
	LCD.DrawHorizontalLine(18 + y, 0 + x, 3 + x);
	LCD.DrawHorizontalLine(18 + y, 12 + x, 31 + x);
	LCD.DrawHorizontalLine(19 + y, 0 + x, 3 + x);
	LCD.DrawHorizontalLine(19 + y, 12 + x, 31 + x);

	LCD.DrawHorizontalLine(20 + y, 0 + x, 5 + x);		// Arm + Tail
	LCD.DrawHorizontalLine(20 + y, 10 + x, 26 + x);		
	LCD.DrawHorizontalLine(20 + y, 30 + x, 31 + x);
	LCD.DrawHorizontalLine(21 + y, 0 + x, 5 + x);
	LCD.DrawHorizontalLine(21 + y, 10 + x, 26 + x);
	LCD.DrawHorizontalLine(21 + y, 30 + x, 31 + x);

	LCD.DrawHorizontalLine(22 + y, 0 + x, 27 + x);		// Lower Body
	LCD.DrawHorizontalLine(23 + y, 0 + x, 27 + x);
	LCD.DrawHorizontalLine(24 + y, 0 + x, 27 + x);
	LCD.DrawHorizontalLine(25 + y, 2 + x, 25 + x);
	LCD.DrawHorizontalLine(26 + y, 2 + x, 25 + x);
	LCD.DrawHorizontalLine(27 + y, 4 + x, 25 + x);
	LCD.DrawHorizontalLine(28 + y, 4 + x, 23 + x);
	LCD.DrawHorizontalLine(29 + y, 6 + x, 23 + x);
	LCD.DrawHorizontalLine(30 + y, 6 + x, 21 + x);
	LCD.DrawHorizontalLine(31 + y, 8 + x, 21 + x);

	switch (frame) {
	case 0:
		LCD.DrawHorizontalLine(32 + y, 8 + x, 15 + x);	// Straight Legs
		LCD.DrawHorizontalLine(32 + y, 18 + x, 21 + x);
		LCD.DrawHorizontalLine(33 + y, 10 + x, 15 + x);
		LCD.DrawHorizontalLine(33 + y, 18 + x, 21 + x);

		LCD.DrawHorizontalLine(34 + y, 10 + x, 13 + x);	
		LCD.DrawHorizontalLine(34 + y, 20 + x, 21 + x);
		LCD.DrawHorizontalLine(35 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(35 + y, 20 + x, 21 + x);

		LCD.DrawHorizontalLine(36 + y, 10 + x, 11 + x);
		LCD.DrawHorizontalLine(36 + y, 20 + x, 21 + x);
		LCD.DrawHorizontalLine(37 + y, 10 + x, 11 + x);
		LCD.DrawHorizontalLine(37 + y, 20 + x, 21 + x);

		LCD.DrawHorizontalLine(38 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(38 + y, 20 + x, 23 + x);
		LCD.DrawHorizontalLine(39 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(39 + y, 20 + x, 23 + x);
		break;
	case 1:
		LCD.DrawHorizontalLine(32 + y, 8 + x, 15 + x);	// Right Leg Up
		LCD.DrawHorizontalLine(32 + y, 19 + x, 25 + x);
		LCD.DrawHorizontalLine(33 + y, 10 + x, 15 + x);
		LCD.DrawHorizontalLine(33 + y, 19 + x, 25 + x);

		LCD.DrawHorizontalLine(34 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(35 + y, 10 + x, 13 + x);

		LCD.DrawHorizontalLine(36 + y, 10 + x, 11 + x);
		LCD.DrawHorizontalLine(37 + y, 10 + x, 11 + x);

		LCD.DrawHorizontalLine(38 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(39 + y, 10 + x, 13 + x);
		break;
	case 2:
		LCD.DrawHorizontalLine(32 + y, 8 + x, 11 + x);	// Left Leg Up
		LCD.DrawHorizontalLine(32 + y, 18 + x, 21 + x);
		LCD.DrawHorizontalLine(33 + y, 10 + x, 11 + x);
		LCD.DrawHorizontalLine(33 + y, 18 + x, 21 + x);

		LCD.DrawHorizontalLine(34 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(34 + y, 20 + x, 21 + x);
		LCD.DrawHorizontalLine(35 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(35 + y, 20 + x, 21 + x);

		LCD.DrawHorizontalLine(36 + y, 20 + x, 21 + x);
		LCD.DrawHorizontalLine(37 + y, 20 + x, 21 + x);

		LCD.DrawHorizontalLine(38 + y, 20 + x, 23 + x);
		LCD.DrawHorizontalLine(39 + y, 20 + x, 23 + x);
		break;
	case 3:
		LCD.DrawHorizontalLine(2 + y, 20 + x, 23 + x);	// Eye
		LCD.DrawHorizontalLine(2 + y, 28 + x, 39 + x);

		LCD.DrawHorizontalLine(3 + y, 20 + x, 23 + x);
		LCD.DrawHorizontalLine(3 + y, 25 + x, 26 + x);		
		LCD.DrawHorizontalLine(3 + y, 28 + x, 39 + x);

		LCD.DrawHorizontalLine(4 + y, 20 + x, 23 + x);
		LCD.DrawHorizontalLine(4 + y, 25 + x, 26 + x);
		LCD.DrawHorizontalLine(4 + y, 28 + x, 39 + x);

		LCD.DrawHorizontalLine(5 + y, 20 + x, 23 + x);		
		LCD.DrawHorizontalLine(5 + y, 28 + x, 39 + x);

		LCD.DrawHorizontalLine(11 + y, 20 + x, 34 + x);	// Mouth
		LCD.DrawHorizontalLine(12 + y, 20 + x, 34 + x);

		LCD.DrawHorizontalLine(13 + y, 20 + x, 27 + x);
		LCD.DrawHorizontalLine(14 + y, 0 + x, 1 + x);
		LCD.DrawHorizontalLine(14 + y, 18 + x, 27 + x);

		LCD.DrawHorizontalLine(32 + y, 8 + x, 15 + x);	// Legs
		LCD.DrawHorizontalLine(32 + y, 18 + x, 21 + x);
		LCD.DrawHorizontalLine(33 + y, 10 + x, 15 + x);
		LCD.DrawHorizontalLine(33 + y, 18 + x, 21 + x);

		LCD.DrawHorizontalLine(34 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(34 + y, 20 + x, 21 + x);
		LCD.DrawHorizontalLine(35 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(35 + y, 20 + x, 21 + x);

		LCD.DrawHorizontalLine(36 + y, 10 + x, 11 + x);
		LCD.DrawHorizontalLine(36 + y, 20 + x, 21 + x);
		LCD.DrawHorizontalLine(37 + y, 10 + x, 11 + x);
		LCD.DrawHorizontalLine(37 + y, 20 + x, 21 + x);

		LCD.DrawHorizontalLine(38 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(38 + y, 20 + x, 23 + x);
		LCD.DrawHorizontalLine(39 + y, 10 + x, 13 + x);
		LCD.DrawHorizontalLine(39 + y, 20 + x, 23 + x);
		break;
	default:
		break;
	}
}

void obstacledraw(int theme, int frame, int x, int y) {
	LCD.SetFontColor(SPRINGGREEN);
	// Cactus: Theme = 0
	// Input (x, y) is lower left corner of Excel sketch
	// Adjust inputs to draw obstacle

	switch (frame) {
		x = x - 0;
		y = y + 160;
	case 0:
		LCD.DrawVerticalLine(0 + x, 18 + y, 22 + y);	// Single Mid-size Cactus
		LCD.DrawVerticalLine(1 + x, 17 + y, 23 + y);
		LCD.DrawVerticalLine(2 + x, 18 + y, 24 + y);
		LCD.DrawVerticalLine(3 + x, 22 + y, 24 + y);
		LCD.DrawVerticalLine(4 + x, 22 + y, 24 + y);

		LCD.DrawVerticalLine(5 + x, 13 + y, 39 + y);	// Mid 
		LCD.DrawVerticalLine(6 + x, 12 + y, 39 + y);
		LCD.DrawVerticalLine(7 + x, 12 + y, 39 + y);
		LCD.DrawVerticalLine(8 + x, 12 + y, 39 + y);
		LCD.DrawVerticalLine(9 + x, 13 + y, 39 + y);

		LCD.DrawVerticalLine(10 + x, 26 + y, 28 + y);	// Right
		LCD.DrawVerticalLine(11 + x, 26 + y, 28 + y);
		LCD.DrawVerticalLine(12 + x, 18 + y, 28 + y);
		LCD.DrawVerticalLine(13 + x, 17 + y, 27 + y);
		LCD.DrawVerticalLine(14 + x, 18 + y, 26 + y);
		break;
	case 1:
		LCD.DrawVerticalLine(0 + x, 15 + y, 28 + y);	// Double Mid-size Cactus
		LCD.DrawVerticalLine(1 + x, 14 + y, 29 + y);	// Cactus 1
		LCD.DrawVerticalLine(2 + x, 15 + y, 30 + y);
		LCD.DrawVerticalLine(3 + x, 28 + y, 30 + y);
		LCD.DrawVerticalLine(4 + x, 28 + y, 30 + y);

		LCD.DrawVerticalLine(5 + x, 9 + y, 39 + y);		// Mid 
		LCD.DrawVerticalLine(6 + x, 8 + y, 39 + y);
		LCD.DrawVerticalLine(7 + x, 8 + y, 39 + y);
		LCD.DrawVerticalLine(8 + x, 8 + y, 39 + y);
		LCD.DrawVerticalLine(9 + x, 9 + y, 39 + y);
		LCD.DrawVerticalLine(10 + x, 19 + y, 21 + y);	
		LCD.DrawVerticalLine(11 + x, 19 + y, 21 + y);

		LCD.DrawVerticalLine(12 + x, 11 + y, 21 + y);	// Start Cactus 2
		LCD.DrawVerticalLine(12 + x, 26 + y, 29 + y);
		LCD.DrawVerticalLine(13 + x, 10 + y, 20 + y);
		LCD.DrawVerticalLine(13 + x, 25 + y, 30 + y);
		LCD.DrawVerticalLine(14 + x, 11 + y, 19 + y);
		LCD.DrawVerticalLine(14 + x, 26 + y, 31 + y);

		LCD.DrawVerticalLine(15 + x, 30 + y, 31 + y);
		LCD.DrawVerticalLine(16 + x, 30 + y, 31 + y);
		LCD.DrawVerticalLine(17 + x, 17 + y, 39 + y);
		LCD.DrawVerticalLine(18 + x, 16 + y, 39 + y);
		LCD.DrawVerticalLine(19 + x, 17 + y, 39 + y);

		LCD.DrawVerticalLine(20 + x, 30 + y, 31 + y);
		LCD.DrawVerticalLine(21 + x, 30 + y, 31 + y);
		LCD.DrawVerticalLine(22 + x, 26 + y, 31 + y);
		LCD.DrawVerticalLine(23 + x, 25 + y, 30 + y);
		LCD.DrawVerticalLine(24 + x, 26 + y, 29 + y);
		break;
	case 2:
		LCD.DrawVerticalLine(0 + x, 15 + y, 25 + y);	// Single Lg-size Cactus
		LCD.DrawVerticalLine(1 + x, 14 + y, 26 + y);
		LCD.DrawVerticalLine(2 + x, 14 + y, 26 + y);
		LCD.DrawVerticalLine(3 + x, 15 + y, 27 + y);
		LCD.DrawVerticalLine(4 + x, 24 + y, 27 + y);
		LCD.DrawVerticalLine(5 + x, 24 + y, 27 + y);

		LCD.DrawVerticalLine(6 + x, 3 + y, 39 + y);		// Mid 
		LCD.DrawVerticalLine(7 + x, 2 + y, 39 + y);
		LCD.DrawVerticalLine(8 + x, 2 + y, 39 + y);
		LCD.DrawVerticalLine(9 + x, 2 + y, 39 + y);
		LCD.DrawVerticalLine(10 + x, 2 + y, 39 + y);
		LCD.DrawVerticalLine(11 + x, 3 + y, 39 + y);

		LCD.DrawVerticalLine(12 + x, 21 + y, 24 + y);	// Right
		LCD.DrawVerticalLine(13 + x, 21 + y, 24 + y);
		LCD.DrawVerticalLine(14 + x, 8 + y, 24 + y);
		LCD.DrawVerticalLine(15 + x, 7 + y, 23 + y);
		LCD.DrawVerticalLine(16 + x, 7 + y, 22 + y);
		LCD.DrawVerticalLine(17 + x, 8 + y, 21 + y);
		break;
	default:
		break;
	}
}

int randomframe() {
	int num;
	int frame;
	num = Random.RandInt();

	while (num > 29999) { num = Random.RandInt(); }
	if (num >= 0 && num < 9999) { frame = 0; }
	else if (num >= 9999 && num < 19999) { frame = 1; }
	else if (num >= 19999 && num < 29999) { frame = 2; }

	return frame;
}

void gameoverdraw() {
	LCD.SetFontColor(GHOSTWHITE);

	// No inputs, direct draw on PROTEUS
	// DrawVerticalLine(x, y, y)
	// DrawHorizontalLine(y, x, x)

	LCD.DrawVerticalLine(57, 55, 59);		// Letter G
	LCD.DrawVerticalLine(58, 55, 59);
	LCD.DrawVerticalLine(59, 53, 62);
	LCD.DrawVerticalLine(60, 53, 62);
	LCD.DrawVerticalLine(61, 50, 53);
	LCD.DrawVerticalLine(61, 61, 64);
	LCD.DrawVerticalLine(62, 50, 53);
	LCD.DrawVerticalLine(62, 61, 64);

	LCD.DrawHorizontalLine(50, 63, 70);
	LCD.DrawHorizontalLine(51, 63, 70);
	LCD.DrawHorizontalLine(56, 65, 70);
	LCD.DrawHorizontalLine(57, 65, 70);
	LCD.DrawHorizontalLine(58, 68, 70);
	LCD.DrawHorizontalLine(59, 68, 70);
	LCD.DrawHorizontalLine(60, 68, 70);
	LCD.DrawHorizontalLine(61, 68, 70);
	LCD.DrawHorizontalLine(62, 68, 70);
	LCD.DrawHorizontalLine(63, 63, 70);
	LCD.DrawHorizontalLine(64, 63, 70);
	
	LCD.DrawVerticalLine(81, 55, 64);		// Letter A
	LCD.DrawVerticalLine(82, 55, 64);
	LCD.DrawVerticalLine(83, 53, 64);
	LCD.DrawVerticalLine(84, 53, 64);
	LCD.DrawVerticalLine(85, 52, 54);
	LCD.DrawVerticalLine(86, 52, 54);
	LCD.DrawVerticalLine(89, 52, 54);
	LCD.DrawVerticalLine(90, 52, 54);
	LCD.DrawVerticalLine(91, 53, 64);
	LCD.DrawVerticalLine(92, 53, 64);
	LCD.DrawVerticalLine(93, 55, 64);
	LCD.DrawVerticalLine(94, 55, 64);

	LCD.DrawHorizontalLine(50, 85, 90);
	LCD.DrawHorizontalLine(51, 85, 90);
	LCD.DrawHorizontalLine(59, 85, 90);
	LCD.DrawHorizontalLine(60, 85, 90);

	LCD.DrawVerticalLine(105, 50, 64);		// Letter M
	LCD.DrawVerticalLine(106, 50, 64);
	LCD.DrawVerticalLine(107, 50, 64);
	LCD.DrawVerticalLine(108, 50, 64);
	LCD.DrawVerticalLine(109, 52, 57);
	LCD.DrawVerticalLine(110, 52, 57);
	LCD.DrawVerticalLine(111, 56, 59);
	LCD.DrawVerticalLine(112, 56, 59);
	LCD.DrawVerticalLine(113, 52, 57);
	LCD.DrawVerticalLine(114, 52, 57);
	LCD.DrawVerticalLine(115, 50, 64);
	LCD.DrawVerticalLine(116, 50, 64);
	LCD.DrawVerticalLine(117, 50, 64);
	LCD.DrawVerticalLine(118, 50, 64);

	LCD.DrawVerticalLine(129, 50, 64);		// Letter E
	LCD.DrawVerticalLine(130, 50, 64);
	LCD.DrawVerticalLine(131, 50, 64);
	LCD.DrawVerticalLine(132, 50, 64);

	LCD.DrawHorizontalLine(50, 133, 142);
	LCD.DrawHorizontalLine(51, 133, 142);
	LCD.DrawHorizontalLine(56, 133, 140);
	LCD.DrawHorizontalLine(57, 133, 140);
	LCD.DrawHorizontalLine(63, 133, 142);
	LCD.DrawHorizontalLine(64, 133, 142);

	LCD.DrawVerticalLine(177, 52, 62);		// Letter O
	LCD.DrawVerticalLine(178, 52, 62);
	LCD.DrawVerticalLine(179, 50, 64);
	LCD.DrawVerticalLine(180, 50, 64);

	LCD.DrawHorizontalLine(50, 181, 186);
	LCD.DrawHorizontalLine(51, 181, 186);
	LCD.DrawHorizontalLine(63, 181, 186);
	LCD.DrawHorizontalLine(64, 181, 186);

	LCD.DrawVerticalLine(187, 50, 64);
	LCD.DrawVerticalLine(188, 50, 64);
	LCD.DrawVerticalLine(189, 52, 62);
	LCD.DrawVerticalLine(190, 52, 62);

	LCD.DrawVerticalLine(201, 50, 58);		// Letter V
	LCD.DrawVerticalLine(202, 50, 58);
	LCD.DrawVerticalLine(203, 50, 60);
	LCD.DrawVerticalLine(204, 50, 60);
	LCD.DrawVerticalLine(205, 57, 62);
	LCD.DrawVerticalLine(206, 57, 62);
	LCD.DrawVerticalLine(207, 59, 64);
	LCD.DrawVerticalLine(208, 59, 64);
	LCD.DrawVerticalLine(209, 57, 62);
	LCD.DrawVerticalLine(210, 57, 62);
	LCD.DrawVerticalLine(211, 50, 60);
	LCD.DrawVerticalLine(212, 50, 60);
	LCD.DrawVerticalLine(213, 50, 58);
	LCD.DrawVerticalLine(214, 50, 58);

	LCD.DrawVerticalLine(225, 50, 64);		// Letter E
	LCD.DrawVerticalLine(226, 50, 64);
	LCD.DrawVerticalLine(227, 50, 64);
	LCD.DrawVerticalLine(228, 50, 64);

	LCD.DrawHorizontalLine(50, 229, 238);
	LCD.DrawHorizontalLine(51, 229, 238);
	LCD.DrawHorizontalLine(56, 229, 236);
	LCD.DrawHorizontalLine(57, 229, 236);
	LCD.DrawHorizontalLine(63, 229, 238);
	LCD.DrawHorizontalLine(64, 229, 238);

	LCD.DrawVerticalLine(249, 50, 64);		// Letter R
	LCD.DrawVerticalLine(250, 50, 64);
	LCD.DrawVerticalLine(251, 50, 64);
	LCD.DrawVerticalLine(252, 50, 64);

	LCD.DrawHorizontalLine(50, 253, 260);
	LCD.DrawHorizontalLine(51, 253, 260);
	LCD.DrawHorizontalLine(52, 259, 262);
	LCD.DrawHorizontalLine(53, 259, 262);
	LCD.DrawHorizontalLine(54, 259, 262);
	LCD.DrawHorizontalLine(55, 259, 262);
	LCD.DrawHorizontalLine(56, 259, 262);
	LCD.DrawHorizontalLine(57, 257, 262);
	LCD.DrawHorizontalLine(58, 257, 262);

	LCD.DrawHorizontalLine(59, 253, 258);
	LCD.DrawHorizontalLine(60, 253, 258);
	LCD.DrawHorizontalLine(61, 255, 260);
	LCD.DrawHorizontalLine(62, 255, 260);
	LCD.DrawHorizontalLine(63, 257, 262);
	LCD.DrawHorizontalLine(64, 257, 262);
}
