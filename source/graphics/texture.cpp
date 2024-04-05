#include "texture.h"

namespace SpaceShooter::Graphics
{
  void Texture::load(const char* filename)
  {
    texture = IMG_LoadTexture(renderer, filename);
  }

  void Texture::draw(const SDL_Point& renderPosition, const SDL_Point& sourcePosition, int widht, int height)
  {
    SDL_Rect destination = {renderPosition.x, renderPosition.y, widht, height};
    SDL_Rect source = { sourcePosition.x, sourcePosition.y, widht, height };
    SDL_QueryTexture(texture, NULL, NULL, &widht, &height);
    SDL_RenderCopy(renderer, texture, &source, &destination);
  }
}