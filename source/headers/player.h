#pragma once

#include "sprite.h"

class Player : public Sprite
{
  public:
    Player();
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    int speed = 10;
    void move();
  
  private:
};