#pragma once

#include <scene.h>

namespace SpaceShooter::Scenes
{
  class GameScene : public Scene
  {
    public:
      void update() override;
      void draw() override;

    private:
      void handleEvents();
  };
}