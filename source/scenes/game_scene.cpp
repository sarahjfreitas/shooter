#include "game_scene.h"

namespace SpaceShooter::Scenes
{
  GameScene::GameScene()
  {
    spriteSheet = make_shared<Texture>();
    spriteSheet->load("assets/sprites/sheet.png");

    player = make_shared<Player>(spriteSheet);
    initializeInputHandler();
  }

  void GameScene::update()
  {
    inputHandler.handleInput();
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

  void GameScene::initializeInputHandler()
  {
    // init input handler
    auto attackCommand = make_unique<AttackCommand>();
    auto speedUpCommand = make_unique<SpeedUpCommand>();
    auto speedDownCommand = make_unique<SpeedDownCommand>();
    auto turnRightCommand = make_unique<TurnRightCommand>();
    auto turnLeftCommand = make_unique<TurnLeftCommand>();

    attackCommand->setMovableGameObject(player);
    speedUpCommand->setMovableGameObject(player);
    speedDownCommand->setMovableGameObject(player);
    turnRightCommand->setMovableGameObject(player);
    turnLeftCommand->setMovableGameObject(player);

    inputHandler.addObserver(InputType::Attack, move(attackCommand));
    inputHandler.addObserver(InputType::SpeedUp, move(speedUpCommand));
    inputHandler.addObserver(InputType::SpeedDown, move(speedDownCommand));
    inputHandler.addObserver(InputType::TurnRight, move(turnRightCommand));
    inputHandler.addObserver(InputType::TurnLeft, move(turnLeftCommand));

  }
}