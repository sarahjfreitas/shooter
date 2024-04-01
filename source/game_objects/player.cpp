#include "player.h"

Player::Player(TextureModel spriteSheet)
{
  texture = new Texture(spriteSheet);
  texture.setSourcePosition(spriteSheetPosition.x, spriteSheetPosition.y);
}

void Player::update()
{
  // rotate based on left and right input
  // change speed based on up and down input
  // should I change the image on rotation or just rotate the texture?
}

void Player::draw(SDL_Renderer* renderer)
{
  texture.draw(renderer, position);
}