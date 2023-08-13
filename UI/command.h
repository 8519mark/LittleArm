#ifndef COMMAND_H
#define COMMAND_H

#include "controller.h"

class Controller; // Forward declaration

class Command {
  protected:
    char key;
    Controller *controller;
  public:
    Command(Controller *controller, char key) : controller(controller), key(key) {};
    bool MatchKey(char key);
    virtual void execute() = 0;
};

class QuitCommand: public Command {
  public:
    using Command::Command;
    void execute() override;
};

class BackCommand: public Command {
  public:
    using Command::Command;
    void execute() override;
};

class OffCommand: public Command {
  public:
    using Command::Command;
    void execute() override;
};


#endif