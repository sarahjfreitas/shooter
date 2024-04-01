#include "texture_model.h"

namespace SpaceShooter::Graphics
{
  TextureModel::~TextureModel()
  {
    SDL_DestroyTexture(texture);
  }

  void TextureModel::load(const char* filename, int weight, int height, SDL_Renderer* renderer) const
  {
    this->weight = weight;
    this->height = height;
    texture = IMG_LoadTexture(renderer, filename);
  }
}