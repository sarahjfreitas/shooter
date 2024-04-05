#pragma once

namespace SpaceShooter::Scenes
{
  class Scene
  {
    public:
      virtual void update() = 0;
      virtual bool handleEvents() = 0;
      virtual void draw() = 0;
  };
}