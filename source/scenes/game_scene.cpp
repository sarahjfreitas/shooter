#include "game_scene.h"

namespace SpaceShooter::Scenes
{
  GameScene::GameScene()
  {
    spriteSheet = make_shared<TextureModel>();
    spriteSheet->load("assets/sprites/sheet.png");

    player = make_unique<Player>(spriteSheet);
  }

  void GameScene::update()
  {
    player->update();
    // updates player and enemies
    // check for collisions
    // spawn new enemies
  }

  void GameScene::draw()
  {
    SDL_RenderClear(renderer);
    player->draw();
    SDL_RenderPresent(renderer);
  }

  // private

  bool GameScene::handleEvents()
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          return false;
        case SDL_KEYDOWN:
          handleKeyDownEvents(&event.key);
          break;
        case SDL_KEYUP:
          handleKeyUpEvents(&event.key);
          break;
      }
    }

    return true;
  };
  
  void GameScene::handleKeyDownEvents(SDL_KeyboardEvent* event)
  {
    switch (event->keysym.scancode)
    {
    case SDL_SCANCODE_UP:
    case SDL_SCANCODE_W:
      break;
    case SDL_SCANCODE_DOWN:
    case SDL_SCANCODE_S:
      break;
    case SDL_SCANCODE_LEFT:
    case SDL_SCANCODE_A:
      break;
    case SDL_SCANCODE_RIGHT:
    case SDL_SCANCODE_D:
      break;
    case SDL_SCANCODE_SPACE:
      break;
    }
  }

  void GameScene::handleKeyUpEvents(SDL_KeyboardEvent* event)
  {
    switch (event->keysym.scancode)
    {
    case SDL_SCANCODE_UP:
    case SDL_SCANCODE_W:
      break;
    case SDL_SCANCODE_DOWN:
    case SDL_SCANCODE_S:
      break;
    case SDL_SCANCODE_LEFT:
    case SDL_SCANCODE_A:
      break;
    case SDL_SCANCODE_RIGHT:
    case SDL_SCANCODE_D:
      break;
    }
  }

}