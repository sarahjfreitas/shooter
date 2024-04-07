#pragma once

#include <SDL.h>
#include <memory>

using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;
using std::move;

#include "config.h"
#include "graphics/texture.h"
#include "scenes/scene.h"
#include "game_objects/player.h"
#include "input/input_handler.h"

using SpaceShooter::GameObjects::Player;
using SpaceShooter::Input::InputHandler;


namespace SpaceShooter::Scenes
{
  class GameScene : public Scene
  {
    public:
      GameScene();
      void update() override;
      void draw() override;

    private:
      shared_ptr<Texture> spriteSheet = nullptr;
      shared_ptr<Player> player = nullptr;
      InputHandler inputHandler;
      void initializeInputHandler();
  };
}