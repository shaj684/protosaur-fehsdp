#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <LCDColors.h>

// Calculate obstacle orange reference point 
void obstacleRP(int frame, int x, int y) {
	switch (frame) {
	case 0:

		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
}

// Calculate dino collision circle centerpoint
void dinoCCC(int frame, int x, int y) {


}

// Check distance
bool collision(int x1, int y1, int x2, int y2, int rad) {
	d = abs(sqrt(pow(x2 - y2, 2) + pow(x1 - y1, 2)));
	if (d < rad) {
		//collision occurred
		return true;
	}
	else { return false; }
}

void platformdraw() {
	LCD.SetFontColor(GOLDENROD);
	LCD.DrawHorizontalLine(PLANEY, 0, 319);
}

// Pass in the (x, y) in reference to lower left corner
void dinodraw(int theme, int frame, int x, int y) {
	LCD.SetFontColor(GHOSTWHITE);
	// Protosaur: Theme = 0
	// Input (x, y) is  collision circle centerpoint, (9, 9) in Excel
	// Adjust input to draw dino
	x = (x - 9);
	y = (y - 9) + (PLANEY - 1) - 39;

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

	switch frame {
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
	// Input (x, y) is obstacle orange reference point see Excel
	// Adjust inputs to draw obstacle

	switch (frame) {
	case 0:	
		x = x - 4;
		y = (y - 10) - 39;
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

		LCD.DrawVerticalLine(12 + x, 11 + y, 21 + y);		// Start Cactus 2
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

		LCD.DrawVerticalLine(6 + x, 1 + y, 39 + y);		// Mid 
		LCD.DrawVerticalLine(7 + x, 0 + y, 39 + y);
		LCD.DrawVerticalLine(8 + x, 0 + y, 39 + y);
		LCD.DrawVerticalLine(9 + x, 0 + y, 39 + y);
		LCD.DrawVerticalLine(10 + x, 0 + y, 39 + y);
		LCD.DrawVerticalLine(11 + x, 1 + y, 39 + y);

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

void gameoverdraw() {
	LCD.SetFontColor(GHOSTWHITE);
}

void checkbutton() {

}

// Jump function
void jump(int x, int y) {

}

// Dino collides with obstacle
void hit() {

}