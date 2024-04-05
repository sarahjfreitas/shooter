#include "player.h"

namespace SpaceShooter::GameObjects {

  void Player::update()
  {
    // rotate based on left and right input
    // change speed based on up and down input
    // should I change the image on rotation or just rotate the texture?
  }

  void Player::draw()
  {
    texture->draw(position, spriteSheetPosition, spriteWidth, spriteHeight);
  }
}