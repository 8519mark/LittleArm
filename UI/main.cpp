#include <ncurses.h>
#include "screen.h"

const int SCREEN_Start_X = 10;
const int SCREEN_Start_Y = 4;
const double SCREEN_RATIO = 3;
const int SCREEN_HEIGHT = 16;
const int SCREEN_WIDTH = SCREEN_HEIGHT * SCREEN_RATIO;

int main() {

  initscr();
  refresh();

  printw(" <---- Robotic Arm - FK & IK ----> ");
  Screen screen(SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_Start_Y, SCREEN_Start_X);

  getch();
  endwin();
  

  return 0;
}