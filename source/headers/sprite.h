#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "config.h"

using std::string;

class Sprite
{
  public:
    void draw(SDL_Renderer* renderer);
    void update();
  
  protected:
    Sprite(int x, int y, string imagePath, int w, int h);
    
    string imagePath;
    SDL_Point position;
    int width;
    int height;

    bool isOutOfBounds();
};