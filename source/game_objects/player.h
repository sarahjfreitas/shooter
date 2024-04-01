#pragma once

#include "sprite.h"
#include "bullet.h"
#include <SDL.h>

#include "../graphics/texture.h"
#include "../graphics/texture_model.h"

class Player
{
  public:
    Player();
    ~Player();

    void update();
    void draw(SDL_Renderer* renderer);
  
  private:
    Texture texture;
    double rotation = 0; // maybe move to texture?
    SDL_Point position = {0, 0};
    SDL_Point spriteSheetPosition = {0, 0}; //TODO: check where the player ship is on the sprite sheet 
};