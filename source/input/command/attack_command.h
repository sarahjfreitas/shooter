#pragma once

#include "input/command/command.h"

namespace SpaceShooter::Input::Command 
{
  class AttackCommand : public Command
  {
    public:
      void execute() override { movableGameObject->attack(); };
  };
}