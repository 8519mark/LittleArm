#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>

class Screen {
  private:
    WINDOW *screen_ptr;
  public:
    Screen(int height, int width, int yStart, int xStart);
};

#endif