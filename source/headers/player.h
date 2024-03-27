#pragma once

#include "sprite.h"
#include "bullet.h"
#include <SDL.h>

class Player : public Sprite
{
  public:
    Player();
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;

    void update() override;
    void draw(SDL_Renderer* renderer) override;
    Bullet shoot();
    void static loadTexture(SDL_Renderer* renderer);
  
  private:
    bool isMoving();
    static inline SDL_Texture* texture = nullptr;
};