#include "texture.h"

namespace SpaceShooter::Graphics
{
  Texture::Texture(unique_ptr<TextureModel> textureModel)
  {
    _textureModel = textureModel;
  }

  void Texture::draw(SDL_Renderer* renderer, const SDL_Point& renderPosition)
  {
    SDL_Rect destination = {renderPosition.x, renderPosition.y, _textureModel.weight, _textureModel.height};
    SDL_Rect source = {sourcePosition.x, sourcePosition.y, _textureModel.weight, _textureModel.height}
    SDL_QueryTexture(_textureModel.texture, NULL, NULL, &destination.w, &destination.h);
    SDL_RenderCopy(renderer, _textureModel.texture, &source, &destination);
  }
}