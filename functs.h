#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "functs.h"
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <LCDColors.h>

void dinodraw(int x, int y) {
	LCD.SetFontColor(GHOSTWHITE);
}

void obstacledraw(int x, int y) {
	LCD.SetFontColor(SPRINGGREEN);
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