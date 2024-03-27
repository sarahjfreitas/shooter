#pragma once

#include "config.h"

#pragma once
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <SDL.h>
#include <SDL_image.h>


#include "config.h"
#include "sprite.h"  
#include "player.h"

using std::runtime_error;
using std::string;
using std::vector;

class Game
{
  public:
    Game();
    ~Game();
    bool isRunning() { return running; };
    void handleEvents();
    void draw();
    void update();
    void limitFps(Uint32 frameStart);

    Player player;
    vector<Bullet> bullets;

  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running = true;

    void initSdl();
    void handleKeyDownEvents(SDL_KeyboardEvent* event);
    void handleKeyUpEvents(SDL_KeyboardEvent* event);
};