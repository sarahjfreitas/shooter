#include "game_scene.h"

namespace SpaceShooter::Scenes
{
  void GameScene::update()
  {
    handleEvents();
    // updates player and enemies
    // check for collisions
    // spawn new enemies
  }

  void GameScene::draw()
  {
    SDL_RenderClear(renderer);
    
    // draw players and enemies

    SDL_RenderPresent(renderer);
  }

  // private

  void GameScene::handleEvents()
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

}