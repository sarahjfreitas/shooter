#include "texture_model.h"
#include "config.h"

namespace SpaceShooter::Graphics
{
  TextureModel::~TextureModel()
  {
    SDL_DestroyTexture(texture);
  }

  void TextureModel::load(const char* filename)
  {
    texture = IMG_LoadTexture(renderer, filename);
  }
}