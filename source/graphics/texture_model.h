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
      int widht;
      int height;
      void load(const char* filename, int widht, int height);
  };
}