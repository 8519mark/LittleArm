#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>

class Screen {
  private:
    WINDOW *screen_ptr;
    int ScreenWidth;
    int ScreenHeight;
  public:
    Screen();
    Screen(int height, int width, int yStart, int xStart);

    void clear();
    void refresh();
    void addChar(char c, int x, int y);
    char getChar() const;
};

#endif