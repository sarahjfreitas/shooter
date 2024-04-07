#pragma once

#include "input/command/command.h"
#include "game_objects/movable_game_object.h"

using SpaceShooter::GameObjects::MovableGameObject;

namespace SpaceShooter::Input::Command 
{
  class TurnRightCommand : public Command
  {
    public:
      void execute() override { movableGameObject->turnRight(); };
  };
}