#pragma once

#include <SDL.h>
#include <memory>

#include "graphics/texture.h"

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;

using namespace SpaceShooter::Graphics;

namespace SpaceShooter::GameObjects {
  class Player
  {
    public:
      Player(shared_ptr<Texture> spriteSheet) : texture(spriteSheet) {}

      void update();
      void draw();

    private:
      shared_ptr<Texture> texture;
      SDL_Point position = { 300, 300 };
      double rotation = 0;

      // TODO: maybe change it latter to allow the user to choose different ships
      SDL_Point spriteSheetPosition = { 224, 832 };
      int spriteWidth = 99;
      int spriteHeight = 75;
  };
}