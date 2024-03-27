#pragma once
#include "sprite.h"

class Bullet : public Sprite
{
  public:
    Bullet() : Sprite(0, 0,  32, 32, 20) {}

    void update() override;
    void static loadTexture(SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer) override;

  private:
    static inline SDL_Texture* texture = nullptr;
};