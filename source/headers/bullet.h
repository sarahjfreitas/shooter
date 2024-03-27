#pragma once
#include "sprite.h"

class Bullet : public Sprite
{
  public:
    Bullet() : Sprite(0, 0, "assets/bullet.png", 32, 32, 2) {}
    bool isFiring = false;

    void draw(SDL_Renderer* renderer) override;
    void update() override;

  private:
};