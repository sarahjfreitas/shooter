#include "player.h"

Player::Player() : Sprite(100,100, 64, 64, 10) {}

void Player::update()
{
  SDL_Point oldPosition = position;

  if(moveUp)
  {
    if (moveLeft)
    {
      direction = Direction::UpLeft;
    }
    else if (moveRight)
    {
      direction = Direction::UpRight;
    }
    else
    {
      direction = Direction::Up;
    }
  }
  else if(moveDown)
  {
    if (moveLeft)
    {
      direction = Direction::DownLeft;
    }
    else if (moveRight)
    {
      direction = Direction::DownRight;
    }
    else
    {
      direction = Direction::Down;
    }
  }
  else if(moveLeft)
  {
    direction = Direction::Left;
  }
  else if(moveRight)
  {
    direction = Direction::Right;
  }

  if (isMoving())
  {
    move();
  }

  if (isOutOfBounds())
  {
    position = oldPosition;
  }
}

void Player::draw(SDL_Renderer* renderer)
{
  switch(direction)
  {
    case Direction::Up:
      draw_(renderer, texture, 0, 0);
      break;
    case Direction::Down:
      draw_(renderer, texture, 0, height * 6);
      break;
    case Direction::Right:
      draw_(renderer, texture, 0, height * 3);
      break;
    case Direction::Left:
      draw_(renderer, texture, 0, height * 9);
      break;
    case Direction::UpRight:
      draw_(renderer, texture, 0, height * 2);
      break;
    case Direction::DownRight:
      draw_(renderer, texture, 0, height * 5);
      break;
    case Direction::DownLeft:
      draw_(renderer, texture, 0, height * 8);
      break;
    case Direction::UpLeft:
      draw_(renderer, texture, 0, height * 11);
      break;
  }
}

Bullet Player::shoot()
{
  Bullet bullet;
  bullet.direction = direction;

  int bulletDistance = 10;

  switch (direction)
  {
    case Direction::Up:
      bullet.position = { position.x, position.y - bulletDistance };
      break;
    case Direction::Down:
      bullet.position = { position.x, position.y + + height + bulletDistance };
      break;
    case Direction::Right:
      bullet.position = { position.x + width + bulletDistance, position.y };
      break;
    case Direction::Left:
      bullet.position = { position.x + bulletDistance, position.y };
      break;
    case Direction::UpRight:
      bullet.position = { position.x + width + bulletDistance, position.y - bulletDistance };
      break;
    case Direction::DownRight:
      bullet.position = { position.x + width + bulletDistance, position.y - bulletDistance };
      break;
    case Direction::DownLeft:
      bullet.position = { position.x + bulletDistance, position.y - bulletDistance };
      break;
    case Direction::UpLeft:
      bullet.position = { position.x + bulletDistance, position.y - bulletDistance };
      break;
  }

  return bullet;
}

void Player::loadTexture(SDL_Renderer* renderer)
{
  texture = loadTexture_(renderer, "assets/ship360_64_0.png");
}

bool Player::isMoving()
{
  return moveUp || moveDown || moveLeft || moveRight;
}
