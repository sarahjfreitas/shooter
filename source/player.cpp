#include "player.h"

Player::Player() : Sprite(100,100, "assets/ship360_64_0.png", 64, 64) {}

void Player::move()
{
  SDL_Point oldPosition = position;

  if(moveUp)
  {
    position.y -= speed;
  }
  if(moveDown)
  {
    position.y += speed;
  }
  if(moveLeft)
  {
    position.x -= speed;
  }
  if(moveRight)
  {
    position.x += speed;
  }

  if (isOutOfBounds())
  {
    position = oldPosition;
  }
}