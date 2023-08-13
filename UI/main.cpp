#include <ncurses.h>

#include "controller.h"

const int SCREEN_Start_X = 10;
const int SCREEN_Start_Y = 4;
const double SCREEN_RATIO = 5;
const int SCREEN_HEIGHT = 20;
const int SCREEN_WIDTH = SCREEN_HEIGHT * SCREEN_RATIO;

int main() {

  initscr();
  noecho();
  refresh();

  Controller controller(SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_Start_Y, SCREEN_Start_X);

  endwin();
  

  return 0;
}