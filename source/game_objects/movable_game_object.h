#pragma once

namespace SpaceShooter::GameObjects
{
  class MovableGameObject
  {
    public:
      virtual void turnRight() {};
      virtual void turnLeft() {};
      virtual void speedUp() {};
      virtual void speedDown() {};
      virtual void attack() {};
  };
}