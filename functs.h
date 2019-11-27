#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <LCDColors.h>

void dinodraw(int frame, int x, int y) {
	LCD.SetFontColor(GHOSTWHITE);

	// Input (x, y) is centerpoint of collision circle
	// Adjust input to draw dino
	x = x - 9;
	y = y - 9;

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
	// Input (x, y) is (0, 0) in reference to Excel
	// Adjust input to draw obstacle
	x = x - 0;
	y = y - 0;

	switch (frame) {
	case 0:		
		LCD.DrawHorizontalLine(12 + y, 6 + x, 8 + x);	// Single Mid-size Cactus
		LCD.DrawHorizontalLine(13 + y, 5 + x, 9 + x);
		LCD.DrawHorizontalLine(14 + y, 5 + x, 9 + x);
		LCD.DrawHorizontalLine(15 + y, 5 + x, 9 + x);
		LCD.DrawHorizontalLine(16 + y, 5 + x, 9 + x);
		LCD.DrawPixel(1, 17); LCD.DrawPixel(13, 17);

		LCD.DrawHorizontalLine(18 + y, 0 + x, 2 + x);
		LCD.DrawHorizontalLine(18 + y, 12 + x, 14 + x);
		LCD.DrawHorizontalLine(18 + y, 5 + x, 9 + x);
		LCD.DrawHorizontalLine(19 + y, 0 + x, 2 + x);
		LCD.DrawHorizontalLine(19 + y, 12 + x, 14 + x);
		LCD.DrawHorizontalLine(19 + y, 5 + x, 9 + x);
		LCD.DrawHorizontalLine(20 + y, 0 + x, 2 + x);
		LCD.DrawHorizontalLine(20 + y, 12 + x, 14 + x);
		LCD.DrawHorizontalLine(20 + y, 5 + x, 9 + x);
		LCD.DrawHorizontalLine(21 + y, 0 + x, 2 + x);
		LCD.DrawHorizontalLine(21 + y, 12 + x, 14 + x);
		LCD.DrawHorizontalLine(21 + y, 5 + x, 9 + x);

		LCD.DrawHorizontalLine(22 + y, 0 + x, 9 + x);
		LCD.DrawHorizontalLine(22 + y, 12 + x, 14 + x);

		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;

	}
}

void platformdraw() {
	LCD.SetFontColor(GOLDENROD);
	LCD.DrawHorizontalLine(PLANEY, 0, 319);
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