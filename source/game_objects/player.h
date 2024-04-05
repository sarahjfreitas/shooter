#pragma once

#include <SDL.h>
#include <memory>

#include "graphics/texture.h"
#include "graphics/texture_model.h"

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;

using namespace SpaceShooter::Graphics;

class Player
{
  public:
    Player(shared_ptr<TextureModel> spriteSheet);

    void update();
    void draw();
  
  private:
    unique_ptr<Texture> texture;
    double rotation = 0; // maybe move to texture?
    SDL_Point position = {0, 0};
    SDL_Point spriteSheetPosition = {0, 0}; //TODO: check where the player ship is on the sprite sheet 
};