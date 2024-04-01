#pragma once

#include <string>
#include <SDL.h>
#include <memory>

using std::unique_ptr;

namespace SpaceShooter::Graphics 
{
  class Texture
  {
    public:
      Texture(unique_ptr<TextureModel> textureModel)

      void setSourcePosition(int x, int y) { sourcePosition.x = x; sourcePosition.y = y; }
      void draw(SDL_Renderer* renderer, const SDL_Point& renderPosition);

    private:
      unique_ptr<TextureModel> _textureModel;
      SDL_Point sourcePosition = {0,0}; 
  };
}