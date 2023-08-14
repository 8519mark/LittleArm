#include "screen.h"

void Screen::clear() {
  wclear(this->screen_ptr);
  box(this->screen_ptr, 0, 0);
  this->addChar(ACS_TTEE, rightStart, 0);
  for (int i = 1; i < screenHeight - 1; i++) {
    this->addChar(ACS_VLINE, rightStart, i); // ascii for long '|' in ncurses, dont use 179
  };
  this->addChar(ACS_BTEE, rightStart, screenHeight - 1);
  wrefresh(this->screen_ptr);
}

void Screen::refresh() {
  wrefresh(this->screen_ptr);
}

void Screen::addChar(int charInInt, int x, int y) {
  mvwaddch(this->screen_ptr, y, x, charInInt);
}

char Screen::getChar() const {
  return wgetch(this->screen_ptr);
}

Screen::Screen(int height, int width, int yStart, int xStart) {
  this->screenWidth = width;
  this->screenHeight = height;
  this->screen_ptr = newwin(height, width, yStart, xStart);
  this->rightStart = width * 2 / 3;
  clear();
  refresh();
};

// no default constructor exists for class
Screen::Screen() {
  this->screenWidth = 0;
  this->screenHeight = 0;
  this->screen_ptr = newwin(3, 3, 1, 1);
};
Screen::~Screen() {
  delwin(screen_ptr);
}






int Screen::getScreenWidth() const {
  return this->screenWidth;
};
int Screen::getScreenHeight() const {
  return this->screenHeight;
};
int Screen::getRightStart() const {
  return this->rightStart;
};