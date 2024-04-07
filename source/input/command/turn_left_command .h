#pragma once

#include "input/command/command.h"

namespace SpaceShooter::Input::Command 
{
  class TurnLeftCommand : public Command
  {
    public:
      void execute() override { movableGameObject->turnLeft(); };
  };
}