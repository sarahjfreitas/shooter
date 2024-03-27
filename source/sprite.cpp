#include "sprite.h"
#include <iostream>

Sprite::Sprite(int x, int y, int width, int height, int speed)
{
  position = {x, y};
  this->width = width;
  this->height = height;
  this->speed = speed;
}

SDL_Texture* Sprite::loadTexture_(SDL_Renderer* renderer, string imagePath)
{
  SDL_Texture* texture = IMG_LoadTexture(renderer, imagePath.c_str());
  if (texture == nullptr)
  {
    std::cout << "Failed to load texture: " << imagePath << std::endl;
  }

  return texture;
}

void Sprite::draw_(SDL_Renderer* renderer, SDL_Texture* texture, int xSource, int ySource)
{
  if (texture == nullptr)
  {
    return;
  }

  SDL_Rect dest = { position.x, position.y, width, height };
  SDL_Rect src = { xSource, ySource, width, height };
  SDL_QueryTexture(texture, nullptr, nullptr, nullptr, nullptr);
  SDL_RenderCopy(renderer, texture, &src, &dest);
}

bool Sprite::isOutOfBounds()
{
  return position.x < 0 || position.x + width > windowWidth || position.y < 0 || position.y + height > windowHeight;
}

void Sprite::move()
{
  switch (direction)
  {
    case Direction::Up:
      position.y -= speed;
      break;
    case Direction::Down:
      position.y += speed;
      break;
    case Direction::Left:
      position.x -= speed;
      break;
    case Direction::Right:
      position.x += speed;
      break;
    case Direction::UpLeft:
      position.x -= speed;
      position.y -= speed;
      break;
    case Direction::UpRight:
      position.x += speed;
      position.y -= speed;
      break;
    case Direction::DownLeft:
      position.x -= speed;
      position.y += speed;
      break;
    case Direction::DownRight:
      position.x += speed;
      position.y += speed;
      break;
  }
}