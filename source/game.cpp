#include "game.h"

//public
Game::Game()
{
  initSdl();
};

Game::~Game()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
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

void Game::handleEvents()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      running = false;
    }
  }
};


void Game::draw()
{
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
  player.draw(renderer);  
  SDL_RenderPresent(renderer);
};