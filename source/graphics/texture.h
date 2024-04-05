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

      void setSourcePosition(SDL_Point _sourcePosition) { sourcePosition.x = _sourcePosition.x; sourcePosition.y = _sourcePosition.y; }
      void setSize(int w, int h) { widht = w; height = h; };
      void draw(const SDL_Point& renderPosition);

    private:
      shared_ptr<TextureModel> textureModel;
      SDL_Point sourcePosition = {0,0};
      int widht = 0;
      int height = 0;
  };
}