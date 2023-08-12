#include "screen.h"

Screen::Screen(int height, int width, int yStart, int xStart) {

  this->screen_ptr = newwin(height, width, yStart, xStart);
  box(screen_ptr, 0, 0);


  wrefresh(screen_ptr);
};

