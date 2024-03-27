#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "config.h"

using std::string;

enum class Direction {
  Up,
  Down,
  Left,
  Right,
  UpLeft,
  UpRight,
  DownLeft,
  DownRight,
};

class Sprite
{
  public:
    void virtual draw(SDL_Renderer* renderer) {};
    void virtual update() {};
    Direction direction = Direction::Right;
    SDL_Point position;
  
  protected:
    Sprite(int x, int y, int width, int height, int speed);
    
    int width;
    int height;
    int speed;
    static inline SDL_Texture* texture = nullptr;

    bool isOutOfBounds();
    void move();
    void draw_(SDL_Renderer* renderer, SDL_Texture* texture, int xSource, int ySource);
    static SDL_Texture* loadTexture_(SDL_Renderer* renderer, string imagePath);
};