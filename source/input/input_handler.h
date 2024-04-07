#pragma once

#include <memory>
#include <unordered_map>
#include <set>
#include <SDL.h>

using std::vector;
using std::set;
using std::unique_ptr;
using std::unordered_map;

#include "input/input_type.h"
#include "input/command/command.h"

using SpaceShooter::Input::Command::Command;
using SpaceShooter::Input::InputType;

namespace SpaceShooter::Input
{
  class InputHandler
  {
    public:
      void addObserver(InputType inputType, unique_ptr<Command::Command> command);
      void handleInput();

    private:
      unordered_map<InputType, vector<unique_ptr<Command::Command>>> commands;
      set<InputType> activeInputs;

      void handleKeyDownEvents(SDL_KeyboardEvent* event);
      void handleKeyUpEvents(SDL_KeyboardEvent* event);
  };
}