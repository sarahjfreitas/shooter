#include "game.h"

SDL_Renderer* renderer = nullptr; // Define renderer

Game::Game()
{
  initSdl();
  initScenes();
  running = true;
};

Game::~Game()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
};

void Game::update()
{
  sceneHandler.getCurrentScene()->update();
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
  sceneHandler.addScene(SpaceShooter::Scenes::SceneId::game);
  sceneHandler.switchTo(SpaceShooter::Scenes::SceneId::game);
}

void Game::limitFps(Uint32 frameStart)
{
  Uint32 frameDuration = SDL_GetTicks() - frameStart;
  if (frameDuration <= frameDelay)
  {
    SDL_Delay(frameDelay - frameDuration);
  }
}