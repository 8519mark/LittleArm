#include "controller.h"

Controller::Controller(int height, int width, int yStart, int xStart) {
  this->screen = Screen(height, width, yStart, xStart);

  this->state = std::make_unique<InitState>(this);
  this->state->stateMessage();
  this->start();
};
void Controller::start() {
  while (running) {
    handleInput();
    this->state->stateMessage();
  }
}


// state change
void Controller::ChangeState(std::unique_ptr<State> state) {
  this->state = std::move(state);
}

// input from state
void Controller::handleInput() {
  const char ch = this->screen.getChar();
  this->state->handleInput(ch);
};