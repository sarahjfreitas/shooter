#pragma once

#include <SDL.h>
#include <memory>

using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;

#include "config.h"
#include "graphics/texture.h"
#include "scenes/scene.h"
#include "game_objects/player.h"

using SpaceShooter::GameObjects::Player;

namespace SpaceShooter::Scenes
{
  class GameScene : public Scene
  {
    public:
      GameScene();
      void update() override;
      void draw() override;
      bool handleEvents();

    private:
      void handleKeyDownEvents(SDL_KeyboardEvent* event);
      void handleKeyUpEvents(SDL_KeyboardEvent* event);
      shared_ptr<Texture> spriteSheet = nullptr;
      unique_ptr<Player> player = nullptr;
  };
}