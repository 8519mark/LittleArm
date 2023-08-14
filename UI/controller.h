#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <ncurses.h>
#include <memory>

#include "Visual/screen.h"
#include "StateManagement/state.h"

class State; // Forward declaration
class Cursor; // Forward declaration

class Controller {
  private:
    void start();
    void handleInput();
    std::unique_ptr<State> state; // state pattern
    void printUserInput(const char &c) const;
  public:
    Screen *screen;
    Cursor *leftCursor;
    Cursor *rightCursor;
    bool running = true;

    Controller(int height, int width, int yStart, int xStart);
    ~Controller();
    void ChangeState(std::unique_ptr<State> state);
};

class Cursor {
  private:
    int x = 1;
    int y = 1;

    int boundLeft = 1;
    int boundRight = 2;
    int boundUP = 1;
    int boundDown = 2;
  public:
    Cursor(int boundLeft, int boundRight, int boundUP, int boundDown);
    bool move(const int& dx, const int &dy);
    int getX() const;
    int getY() const;
};

#endif