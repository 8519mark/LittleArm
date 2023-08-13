#include "state.h"

State::~State() {
  this->commands.clear();
}
void State::handleInput(const char &c) {
  for (const std::unique_ptr<Command>& command : commands) {
    if (command->MatchKey(c)) {
      command->execute();
      break;
    }
  }
}
void State::printStateMsg(const char *message, size_t n) const {
  int i = 0;
  while (i < n) {
    this->controller->screen.addChar(message[i], 2 + i, 0);
    i++;
  }
  this->controller->screen.refresh();
}

InitState::InitState(Controller *controller) {
  this->controller = controller;
  this->commands.push_back(std::make_unique<QuitCommand>(this->controller, 'q'));
}
void InitState::stateMessage() {
  printStateMsg("Init", 4);
}



QuitState::QuitState(Controller *controller) {
  this->controller = controller;
  this->commands.push_back(std::make_unique<BackCommand>(this->controller, 'n'));
  this->commands.push_back(std::make_unique<OffCommand>(this->controller, 'y'));
}
void QuitState::stateMessage() {
  printStateMsg("Quit", 4);
}