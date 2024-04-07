#pragma once

#include <SDL.h>
#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;

#include "graphics/texture.h"
#include "game_objects/movable_game_object.h"
#include "input/input_handler.h"
#include "input/input_type.h"
#include "input/command/command.h"
#include "input/command/attack_command.h"
#include "input/command/speed_up_command.h"
#include "input/command/speed_down_command.h"
#include "input/command/turn_left_command .h"
#include "input/command/turn_right_command.h"

using SpaceShooter::Input::InputHandler;
using SpaceShooter::Input::InputType;
using SpaceShooter::Input::Command::AttackCommand;
using SpaceShooter::Input::Command::AttackCommand;
using SpaceShooter::Input::Command::SpeedUpCommand;
using SpaceShooter::Input::Command::SpeedDownCommand;
using SpaceShooter::Input::Command::TurnLeftCommand;
using SpaceShooter::Input::Command::TurnRightCommand;

using namespace SpaceShooter::Graphics;

namespace SpaceShooter::GameObjects {
  class Player : public MovableGameObject
  {
    public:
      Player(shared_ptr<Texture> spriteSheet) : texture(spriteSheet) {}

      void update();
      void draw();

      void turnRight() override;
      void turnLeft() override;
      void speedUp() override;
      void speedDown() override;
      void attack() override;

    private:
      shared_ptr<Texture> texture;
      SDL_Point position = { 300, 300 };
      double rotation = 0;
      int speed = 0;
      int aceleleration = 5;
      int const maxSpeed = 30;
      bool isAtacking = false;

      // TODO: maybe change it latter to allow the user to choose different ships
      SDL_Point spriteSheetPosition = { 224, 832 };
      int spriteWidth = 99;
      int spriteHeight = 75;

      void fixRotation();
  };
}