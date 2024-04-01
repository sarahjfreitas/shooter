#include "game.h"

//public
Game::Game()
{
  initSdl();
  initScenes();
};

Game::~Game()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
};

void Game::update()
{
  SceneHandler.getCurrentScene()->update();
}
void Game::draw()
{
  sceneHandler.getCurrentScene()->draw();
};

//private

void Game::initSdl()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
      throw runtime_error("SDL could not initialize! SDL_Error: " + string(SDL_GetError()));
  }

  window = SDL_CreateWindow("Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE);
  if (!window)
  {
    throw runtime_error("Window could not be created! SDL_Error: " + string(SDL_GetError()));
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(!renderer)
  {
    throw runtime_error("Renderer could not be created! SDL_Error: " + string(SDL_GetError()));
  }

  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
};

void Game::initScenes()
{
  sceneHandler.addScene(SceneId::game);
}

void Game::limitFps(Uint32 frameStart)
{
  Uint32 frameDuration = SDL_GetTicks() - frameStart;
  if (frameDuration <= frameDelay)
  {
    SDL_Delay(frameDelay - frameDuration);
  }
}

void Game::handleKeyDownEvents(SDL_KeyboardEvent *event)
{
  switch (event->keysym.scancode)
  {
    case SDL_SCANCODE_UP:
    case SDL_SCANCODE_W:
      player.moveUp = true;
      break;
    case SDL_SCANCODE_DOWN:
    case SDL_SCANCODE_S:
      player.moveDown = true;
      break;
    case SDL_SCANCODE_LEFT:
    case SDL_SCANCODE_A:
      player.moveLeft = true;
      break;
    case SDL_SCANCODE_RIGHT:
    case SDL_SCANCODE_D:
      player.moveRight = true;
      break;
    case SDL_SCANCODE_SPACE:
      bullets.push_back(player.shoot());
      break;
  }
}

void Game::handleKeyUpEvents(SDL_KeyboardEvent* event)
{
  switch (event->keysym.scancode)
  {
  case SDL_SCANCODE_UP:
  case SDL_SCANCODE_W:
    player.moveUp = false;
    break;
  case SDL_SCANCODE_DOWN:
  case SDL_SCANCODE_S:
    player.moveDown = false;
    break;
  case SDL_SCANCODE_LEFT:
  case SDL_SCANCODE_A:
    player.moveLeft = false;
    break;
  case SDL_SCANCODE_RIGHT:
  case SDL_SCANCODE_D:
    player.moveRight = false;
    break;
  }
}