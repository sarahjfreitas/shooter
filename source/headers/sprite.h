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
    void virtual draw(SDL_Renderer* renderer);
    void virtual update() {};
    void loadTexture(SDL_Renderer* renderer);
    Direction direction = Direction::Right;
    SDL_Point position;
  
  protected:
    Sprite(int x, int y, string imagePath, int width, int height, int speed);
    
    string imagePath;
    int width;
    int height;
    int speed;
    SDL_Texture* texture = nullptr;

    bool isOutOfBounds();
    void move();
    void draw_(SDL_Renderer* renderer, int xSource, int ySource);
};