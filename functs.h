#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "functs.h"
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <LCDColors.h>

void dinodraw() {
	LCD.SetFontColor(GHOSTWHITE);
}

void obstacledraw() {
	LCD.SetFontColor(SPRINGGREEN);
}

void platformdraw() {
	LCD.SetFontColor(SPRINGGREEN);
}

void menudraw() {
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