#ifndef STATE_H
#define STATE_H

#include <memory>
#include <vector>

#include "controller.h"
#include "command.h"


class Controller; // Forward declaration
class Command;

class State {
  protected:
    Controller *controller;
    std::vector<std::unique_ptr<Command>> commands;
    void printStateMsg(const char *message, size_t n) const;
  public:
    virtual ~State();
    virtual void stateMessage() = 0;
    void handleInput(const char &c);
};

class InitState : public State {
  public:
    InitState(Controller *controller);
    void stateMessage() override;
};

class QuitState : public State {
  public:
    QuitState(Controller *controller);
    void stateMessage() override;
};

#endif