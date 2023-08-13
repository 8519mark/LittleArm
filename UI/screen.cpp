#include "screen.h"

void Screen::clear() {
  wclear(this->screen_ptr);
  box(this->screen_ptr, 0, 0);
  wrefresh(this->screen_ptr);
}

void Screen::refresh() {
  wrefresh(this->screen_ptr);
}

void Screen::addChar(char c, int x, int y) {
  mvwaddch(this->screen_ptr, y, x, c);
}

char Screen::getChar() const {
  return wgetch(this->screen_ptr);
}

Screen::Screen(int height, int width, int yStart, int xStart) {
  this->ScreenWidth = width;
  this->ScreenHeight = height;
  this->screen_ptr = newwin(height, width, yStart, xStart);

  clear();
  refresh();
};

// no default constructor exists for class
Screen::Screen() {
  this->ScreenWidth = 0;
  this->ScreenHeight = 0;
  this->screen_ptr = newwin(1, 1, 0, 0);
};