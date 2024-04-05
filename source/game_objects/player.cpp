#include "player.h"

Player::Player(shared_ptr<TextureModel> spriteSheet)
{
  texture = make_unique<Texture>(spriteSheet);
  texture->setSourcePosition(spriteSheetPosition.x, spriteSheetPosition.y);
}

void Player::update()
{
  // rotate based on left and right input
  // change speed based on up and down input
  // should I change the image on rotation or just rotate the texture?
}

void Player::draw()
{
  texture->draw(position);
}