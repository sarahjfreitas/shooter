#include "texture_model.h"
#include "config.h"

namespace SpaceShooter::Graphics
{
  TextureModel::~TextureModel()
  {
    SDL_DestroyTexture(texture);
  }

  void TextureModel::load(const char* filename, int widht, int height)
  {
    this->widht = widht;
    this->height = height;
    texture = IMG_LoadTexture(renderer, filename);
  }
}