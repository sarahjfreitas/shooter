#pragma once

#include <string>
#include <SDL.h>
#include <memory>

#include "texture_model.h"
#include "config.h"

using std::shared_ptr;
using SpaceShooter::Graphics::TextureModel;

namespace SpaceShooter::Graphics 
{
  class Texture
  {
    public:
      Texture(shared_ptr<TextureModel> textureModel);

      void setSourcePosition(int x, int y) { sourcePosition.x = x; sourcePosition.y = y; }
      void draw(const SDL_Point& renderPosition);

    private:
      shared_ptr<TextureModel> textureModel;
      SDL_Point sourcePosition = {0,0}; 
  };
}