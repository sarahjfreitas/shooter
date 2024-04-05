#pragma once

#include <SDL.h>
#include <memory>

#include "graphics/texture.h"
#include "graphics/texture_model.h"

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;

using namespace SpaceShooter::Graphics;

namespace SpaceShooter::GameObjects {
  class Player
  {
    public:
      Player(shared_ptr<TextureModel> spriteSheet);

      void update();
      void draw();

    private:
      unique_ptr<Texture> texture;
      double rotation = 0; // maybe move to texture?
      SDL_Point position = { 300, 300 };

      // TODO: maybe change it latter to allow the user to choose different ships
      SDL_Point spriteSheetPosition = { 224, 832 };
      int spriteWidth = 99;
      int spriteHeight = 75;
  };
}