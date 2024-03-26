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
    switch (event.type)
    {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        handleKeyDownEvents(&event.key);
        break;
      case SDL_KEYUP:
        handleKeyUpEvents(&event.key);
        break;

    }
  }
};

void Game::update()
{
  player.move();
};

void Game::draw()
{
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
  player.draw(renderer);  
  SDL_RenderPresent(renderer);
};

// private

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