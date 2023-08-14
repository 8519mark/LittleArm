#ifndef COMMAND_H
#define COMMAND_H

#include "../controller.h"

class Controller; // Forward declaration

class Command {
  protected:
    char key;
    Controller *controller;
    void testCommand(const char &repChar) const;
  public:
    Command(Controller *controller, char key) : controller(controller), key(key) {};
    bool MatchKey(char key);
    virtual void execute() = 0;
};

class InitCommand: public Command {
  public:
    using Command::Command;
    void execute() override;
};

class InfoCommand: public Command {
  public:
    using Command::Command;
    void execute() override;
};

class QuitCommand: public Command {
  public:
    using Command::Command;
    void execute() override;
};

class OffCommand: public Command {
  public:
    using Command::Command;
    void execute() override;
};


class CursorCommand: public Command {
  protected:
    void move(bool isLeft, int dx, int dy);
  public:
    using Command::Command;
    virtual void execute() override = 0;
};
class LeftCursorLeft: public CursorCommand {
  public:
    using CursorCommand::CursorCommand;
    void execute() override;
};
class LeftCursorRight: public CursorCommand {
  public:
    using CursorCommand::CursorCommand;
    void execute() override;
};
class LeftCursorUp: public CursorCommand {
  public:
    using CursorCommand::CursorCommand;
    void execute() override;
};

class LeftCursorDown: public CursorCommand {
  public:
    using CursorCommand::CursorCommand;
    void execute() override;
};


class RightCursorLeft: public CursorCommand {
  public:
    using CursorCommand::CursorCommand;
    void execute() override;
};
class RightCursorRight: public CursorCommand {
  public:
    using CursorCommand::CursorCommand;
    void execute() override;
};
class RightCursorUp: public CursorCommand {
  public:
    using CursorCommand::CursorCommand;
    void execute() override;
};
class RightCursorDown: public CursorCommand {
  public:
    using CursorCommand::CursorCommand;
    void execute() override;
};



#endif