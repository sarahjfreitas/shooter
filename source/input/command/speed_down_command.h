#pragma once

#include "input/command/command.h"

namespace SpaceShooter::Input::Command 
{
  class SpeedDownCommand : public Command
  {
    public:
      void execute() override { movableGameObject->speedDown(); };
  };
}