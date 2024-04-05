#pragma once

#include <SDL.h>
#include <SDL_image.h>

namespace SpaceShooter::Graphics
{
  class TextureModel
  {
    public:
      ~TextureModel();
      SDL_Texture* texture;
      void load(const char* filename);
  };
}