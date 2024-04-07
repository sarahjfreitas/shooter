#include "player.h"

namespace SpaceShooter::GameObjects {

  void Player::update()
  {
    position.x += speed * sin(rotation * M_PI / 180);
    position.y -= speed * cos(rotation * M_PI / 180);

    if(speed > 0) speed -= aceleleration;
    if(speed < 0) speed = 0;
  }

  void Player::draw()
  {
    texture->draw(position, spriteSheetPosition, spriteWidth, spriteHeight);
  }

  void Player::turnRight()
  {
    rotation += aceleleration * speed;
    fixRotation();
  }

  void Player::turnLeft()
  {
    rotation -= aceleleration * speed;
    fixRotation();
  }

  void Player::speedUp()
  {
    speed += aceleleration;
    if(speed > maxSpeed)
    {
      speed = maxSpeed;
    }
  }

  void Player::speedDown()
  {
    speed -= aceleleration;
    if(speed < 0)
    {
      speed = 0;
    }
  }

  void Player::attack()
  {
    isAtacking = true;
  }

  // private
  void Player::fixRotation()
  {
    if(rotation > 360)
    {
      rotation -= 360;
    }
    else if(rotation < 0)
    {
      rotation += 360;
    }
  }
}