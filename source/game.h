#pragma once

#include <stdexcept>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include "config.h"
#include "scenes/scene_handler.h"

using std::runtime_error;
using std::string;

class Game
{
  public:
    Game();
    ~Game();

    bool isRunning() { return running; };
    void draw();
    void update();
    void limitFps(Uint32 frameStart);

  private:
    SDL_Window *window;
    bool running;
    SpaceShooter::Scenes::SceneHandler sceneHandler;

    void initSdl();
    void initScenes();
};