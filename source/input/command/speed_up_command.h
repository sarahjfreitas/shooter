#pragma once

#include "input/command/command.h"

namespace SpaceShooter::Input::Command 
{
  class SpeedUpCommand : public Command
  {
    public:
      void execute() override { movableGameObject->speedUp(); };
  };
}