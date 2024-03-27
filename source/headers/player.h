#pragma once

#include "sprite.h"
#include "bullet.h"

class Player : public Sprite
{
  public:
    Player();
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    Bullet bullet;

    void update() override;
    void draw(SDL_Renderer* renderer) override;
    void shoot();
  
  private:
    bool isMoving();
};