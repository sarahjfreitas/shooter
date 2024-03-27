#include "bullet.h"

void Bullet::draw(SDL_Renderer* renderer)
{
  if(isFiring)
  {
    Sprite::draw(renderer);
  }
}

void Bullet::update()
{
  move();

  if (isOutOfBounds())
  {
    isFiring = false;
  }
}