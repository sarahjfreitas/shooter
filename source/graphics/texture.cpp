#include "texture.h"

namespace SpaceShooter::Graphics
{
  Texture::Texture(shared_ptr<TextureModel> textureModel)
  {
    this->textureModel = textureModel;
  }

  void Texture::draw(const SDL_Point& renderPosition)
  {
    SDL_Rect destination = {renderPosition.x, renderPosition.y, textureModel->widht, textureModel->height};
    SDL_Rect source = { sourcePosition.x, sourcePosition.y, textureModel->widht, textureModel->height };
    SDL_QueryTexture(textureModel->texture, NULL, NULL, &destination.w, &destination.h);
    SDL_RenderCopy(renderer, textureModel->texture, &source, &destination);
  }
}