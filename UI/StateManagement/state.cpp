#include "state.h"

State::~State() {
  this->commands.clear();
};
void State::handleInput(const char &inputChar) {
  for (const std::unique_ptr<Command>& command : commands) {
    if (command->MatchKey(inputChar)) {
      command->execute();
      break;
    }
  }
};
void State::printStateMsg(const char *message, size_t n) const {
  int i = 0;
  while (i < n) {
    this->controller->screen->addChar(message[i], 2 + i, 0);
    i++;
  }
  this->controller->screen->refresh();
};

InitState::InitState(Controller *controller) {
  this->controller = controller;
  this->commands.push_back(std::make_unique<QuitCommand>(this->controller, 'q'));

  this->commands.push_back(std::make_unique<InfoCommand>(this->controller, 'x'));

  this->commands.push_back(std::make_unique<LeftCursorUp>(this->controller, 'w'));
  this->commands.push_back(std::make_unique<LeftCursorLeft>(this->controller, 'a'));
  this->commands.push_back(std::make_unique<LeftCursorDown>(this->controller, 's'));
  this->commands.push_back(std::make_unique<LeftCursorRight>(this->controller, 'd'));
};
void InitState::stateMessage() {
  printStateMsg("Init", 4);
};


InfoState::InfoState(Controller *controller) {
  this->controller = controller;
  this->commands.push_back(std::make_unique<QuitCommand>(this->controller, 'q'));

  this->commands.push_back(std::make_unique<InitCommand>(this->controller, 'x'));

  this->commands.push_back(std::make_unique<RightCursorUp>(this->controller, 'w'));
  this->commands.push_back(std::make_unique<RightCursorLeft>(this->controller, 'a'));
  this->commands.push_back(std::make_unique<RightCursorDown>(this->controller, 's'));
  this->commands.push_back(std::make_unique<RightCursorRight>(this->controller, 'd'));
};
void InfoState::stateMessage() {
  printStateMsg("Info", 4);
};


QuitState::QuitState(Controller *controller) {
  this->controller = controller;
  this->commands.push_back(std::make_unique<InitCommand>(this->controller, 'n'));
  this->commands.push_back(std::make_unique<OffCommand>(this->controller, 'y'));
};
void QuitState::stateMessage() {
  printStateMsg("Quit", 4);
};