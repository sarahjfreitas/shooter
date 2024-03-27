#include "sprite.h"
#include <iostream>

Sprite::Sprite(int x, int y, string image, int width, int height, int speed)
{
  position = {x, y};
  imagePath = image;
  this->width = width;
  this->height = height;
  this->speed = speed;
}

void Sprite::loadTexture(SDL_Renderer* renderer)
{
  texture = IMG_LoadTexture(renderer, imagePath.c_str());
  if (texture == nullptr)
  {
    std::cout << "Failed to load texture: " << imagePath << std::endl;
  }
}

void Sprite::draw(SDL_Renderer* renderer)
{
  draw_(renderer, 0, 0);
}

void Sprite::draw_(SDL_Renderer* renderer, int xSource, int ySource)
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

// protected
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