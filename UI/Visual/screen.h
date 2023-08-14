#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>

class Screen {
  private:
    WINDOW *screen_ptr;
    int screenWidth;
    int screenHeight;
    int rightStart;
  public:
    
    Screen();
    Screen(int height, int width, int yStart, int xStart);
    ~Screen();

    void clear();
    void refresh();
    void addChar(int charInInt, int x, int y);
    char getChar() const;

    int getScreenWidth() const;
    int getScreenHeight() const;
    int getRightStart() const;
};

#endif