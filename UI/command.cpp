#include "command.h"

bool Command::MatchKey(char key) {
  refresh();
  return this->key == key;
};


void QuitCommand::execute() {
  this->controller->ChangeState(std::make_unique<QuitState>(this->controller));
};
void BackCommand::execute() {
  this->controller->ChangeState(std::make_unique<InitState>(this->controller));
};
void OffCommand::execute() {
  this->controller->running = false;
};



