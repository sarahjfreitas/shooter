#pragma once

#include "config.h"

#pragma once
#include <stdexcept>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include "config.h"
#include "sprite.h"  
#include "player.h"

using std::runtime_error;
using std::string;

class Game
{
  public:
    Game();
    ~Game();
    bool isRunning() { return running; };
    void handleEvents();
    void draw();

    Player player;

  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running = true;

    void initSdl();
};