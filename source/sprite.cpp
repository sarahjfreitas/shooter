#include "sprite.h"
#include <iostream>

Sprite::Sprite(int x, int y, string image, int w, int h)
{
  position = {x, y};
  imagePath = image;
  width = w;
  height = h;
}

void Sprite::draw(SDL_Renderer* renderer)
{
  SDL_Texture* texture = IMG_LoadTexture(renderer, imagePath.c_str());
  if (texture == nullptr)
  {
    std::cout << "Failed to load texture: " << imagePath << std::endl;
  }

  SDL_Rect dest = {position.x, position.y, width, height };
  SDL_Rect src = {0, 0, width, height };
  SDL_QueryTexture(texture, nullptr, nullptr, nullptr, nullptr);
  SDL_RenderCopy(renderer, texture, &src, &dest);
}


// private

bool Sprite::isOutOfBounds()
{
  return position.x < 0 || position.x + width > windowWidth || position.y < 0 || position.y + height > windowHeight;
}