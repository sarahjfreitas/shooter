#pragma once

#include "config.h"

#pragma once
#include <stdexcept>
#include <iostream>
#include <string>

#include "config.h"
#include "scenes/scene_handler.h"
#include "scenes/scene_id.h"

using std::runtime_error;
using std::string;
using SpaceShooter::Scenes::SceneHandler;
using SpaceShooter::Scenes::SceneId;

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

  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running = true;
    SceneHandler sceneHandler;

    void initSdl();
    void initScenes();
    void handleKeyDownEvents(SDL_KeyboardEvent* event);
    void handleKeyUpEvents(SDL_KeyboardEvent* event);
};