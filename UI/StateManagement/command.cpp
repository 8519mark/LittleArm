#include "command.h"

bool Command::MatchKey(char key) {
  refresh();
  return this->key == key;
};
void Command::testCommand(const char &repChar) const {
  this->controller->screen->addChar(repChar, 2, 2);
  this->controller->screen->refresh();
}

void InitCommand::execute() {
  this->controller->ChangeState(std::make_unique<InitState>(this->controller));
};
void InfoCommand::execute() {
  this->controller->ChangeState(std::make_unique<InfoState>(this->controller));
};
void QuitCommand::execute() {
  this->controller->ChangeState(std::make_unique<QuitState>(this->controller));
};
void OffCommand::execute() {
  this->controller->running = false;
};


void CursorCommand::move(bool isLeft, int dx, int dy) {
  Cursor *cursor;
  int symbol;
  if (isLeft) {
    cursor = this->controller->leftCursor;
    symbol = ACS_DIAMOND;
  } else {
    cursor = this->controller->rightCursor;
    symbol = ACS_RARROW;
  }
  int prevX = cursor->getX();
  int prevY = cursor->getY();
  if (cursor->move(dx, dy)) {
    this->controller->screen->addChar(' ', prevX, prevY); // temp
    this->controller->screen->addChar(symbol, cursor->getX(), cursor->getY());
    this->controller->screen->refresh();
  };
  // testCommand('<');
};
void LeftCursorLeft::execute() {
  move(true, -2, 0);
};
void LeftCursorRight::execute() {
  move(true, 2, 0);
};
void LeftCursorUp::execute() {
  move(true, 0, -1);
};
void LeftCursorDown::execute() {
  move(true, 0, 1);
};

void RightCursorLeft::execute() {
  move(false, -2, 0);
};
void RightCursorRight::execute() {
  move(false, 2, 0);
};
void RightCursorUp::execute() {
  move(false, 0, -1);
};
void RightCursorDown::execute() {
  move(false, 0, 1);
};



