#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <ncurses.h>
#include <memory>

#include "screen.h"
#include "state.h"

class State; // Forward declaration

class Controller {
  private:
    void start();
    void handleInput();
    std::unique_ptr<State> state; // state pattern
  public:
    Screen screen;
    bool running = true;
    Controller(int height, int width, int yStart, int xStart);
    void ChangeState(std::unique_ptr<State> state);
};

#endif