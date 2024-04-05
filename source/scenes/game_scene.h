#pragma once

#include <SDL.h>
#include "config.h"
#include "scenes/scene.h"
#include "game_objects/player.h"

namespace SpaceShooter::Scenes
{
  class GameScene : public Scene
  {
    public:
      void update() override;
      void draw() override;
      bool handleEvents();

    private:
      void handleKeyDownEvents(SDL_KeyboardEvent* event);
      void handleKeyUpEvents(SDL_KeyboardEvent* event);
  };
}