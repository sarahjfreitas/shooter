#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "texture.h"

namespace SpaceShooter::Graphics
{
  class TextureModel
  {
    public:
      friend class Texture;

      ~TextureModel();
      void load(const char* filename, int weight, int height, SDL_Renderer* renderer) const;

    private:
      SDL_Texture* texture;
      int weight;
      int height;
  };
}