#include "controller.h"

// Cursor
Cursor::Cursor(int boundLeft, int boundRight, int boundUP, int boundDown)
  : boundLeft(boundLeft), boundRight(boundRight), boundUP(boundUP), boundDown(boundDown),
  x(boundLeft), y(boundUP) {};

bool Cursor::move(const int& dx, const int &dy) {
  if (this->x + dx >=  this->boundLeft && this->x + dx < this->boundRight 
  && this->y + dy >= this->boundUP && this->y + dy < this->boundDown) {
    this->x += dx;
    this->y += dy;
    return true;
  }
  return false;
};
int Cursor::getX() const {
  return this->x;
};
int Cursor::getY() const {
  return this->y;
};

Controller::Controller(int height, int width, int yStart, int xStart) {
  this->screen = new Screen(height, width, yStart, xStart);
  this->leftCursor = new Cursor(1, this->screen->getRightStart() - 1, 1, height - 1);
  this->rightCursor = new Cursor(this->screen->getRightStart() + 1, width - 1, 1, height - 1);

  this->screen->addChar(ACS_DIAMOND, this->leftCursor->getX(), this->leftCursor->getY());
  this->screen->addChar(ACS_RARROW, this->rightCursor->getX(), this->rightCursor->getY());
  this->screen->refresh();

  this->state = std::make_unique<InitState>(this);
  this->state->stateMessage();
  this->start();
};
void Controller::start() {
  while (running) {
    handleInput();
    this->state->stateMessage();
  }
};

Controller::~Controller() {
  delete screen;
  delete leftCursor;
  delete rightCursor;
}



// state change
void Controller::ChangeState(std::unique_ptr<State> state) {
  this->state = std::move(state);
};

// input from state
void Controller::handleInput() {
  const char inputChar = this->screen->getChar();
  //printUserInput(inputChar);
  this->state->handleInput(inputChar);
};

void Controller::printUserInput(const char &inputChar) const {
  mvaddch(1, 0, inputChar);
  refresh();
};
