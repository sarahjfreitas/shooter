#include "player.h"

namespace SpaceShooter::GameObjects {
  Player::Player(shared_ptr<TextureModel> spriteSheet)
  {
    texture = make_unique<Texture>(spriteSheet);
  }

  void Player::update()
  {
    texture->setSourcePosition(spriteSheetPosition);
    texture->setSize(spriteWidth, spriteHeight);
    // rotate based on left and right input
    // change speed based on up and down input
    // should I change the image on rotation or just rotate the texture?
  }

  void Player::draw()
  {
    texture->draw(position);
  }
}