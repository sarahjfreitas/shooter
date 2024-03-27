#include "bullet.h"

void Bullet::update()
{
  move();
}

void Bullet::loadTexture(SDL_Renderer* renderer)
{
  texture = loadTexture_(renderer, "assets/bullet.png");
}

void Bullet::draw(SDL_Renderer* renderer)
{
  draw_(renderer, texture, 0, 0);
}
