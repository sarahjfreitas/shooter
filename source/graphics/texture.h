#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <memory>

#include "config.h"

using std::shared_ptr;

namespace SpaceShooter::Graphics 
{
  class Texture
  {
    public:
      void load(const char* filename);
      void draw(const SDL_Point& renderPosition, const SDL_Point& sourcePosition, int widht, int height);

    private:
      SDL_Texture* texture;
      SDL_Point sourcePosition = {0,0};
      int widht = 0;
      int height = 0;
  };
}