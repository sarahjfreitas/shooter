#include "texture.h"

namespace SpaceShooter::Graphics
{
  Texture::Texture(shared_ptr<TextureModel> textureModel)
  {
    this->textureModel = textureModel;
  }

  void Texture::draw(const SDL_Point& renderPosition)
  {
    SDL_Rect destination = {renderPosition.x, renderPosition.y, widht, height};
    SDL_Rect source = { sourcePosition.x, sourcePosition.y, widht, height };
    SDL_QueryTexture(textureModel->texture, NULL, NULL, &widht, &height);
    SDL_RenderCopy(renderer, textureModel->texture, &source, &destination);
  }
}