#pragma once

#include <memory>

using std::shared_ptr;
using std::make_shared;

#include "game_objects/movable_game_object.h"

using SpaceShooter::GameObjects::MovableGameObject;

namespace SpaceShooter::Input::Command
{
  class Command
  {
    public:
      Command() { movableGameObject = make_shared<MovableGameObject>(); } // initialize to prevent null pointer exceptions
      virtual void execute() = 0;
      void setMovableGameObject(shared_ptr<MovableGameObject> movableGameObject) { this->movableGameObject = movableGameObject; }

    protected:
      shared_ptr<MovableGameObject> movableGameObject;
  };
}