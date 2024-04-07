#include "input/input_handler.h"

namespace SpaceShooter::Input
{
  void InputHandler::addObserver(InputType inputType, unique_ptr<Command::Command> command)
  {
    commands[inputType].push_back(move(command));
  }

  void InputHandler::handleInput() {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          exit(0);
        case SDL_KEYDOWN:
          handleKeyDownEvents(&event.key);
          break;
        case SDL_KEYUP:
          handleKeyUpEvents(&event.key);
          break;
      }
    }

    for (auto& input : activeInputs)
    {
      for (auto& command : commands[input])
      {
        command->execute();
      }
    }
  }

  //private:

  void InputHandler::handleKeyDownEvents(SDL_KeyboardEvent* event)
  {
    switch (event->keysym.scancode)
    {
      case SDL_SCANCODE_UP:
      case SDL_SCANCODE_W:
        activeInputs.insert(InputType::SpeedUp);
        break;
      case SDL_SCANCODE_DOWN:
      case SDL_SCANCODE_S:
        activeInputs.insert(InputType::SpeedDown);
        break;
      case SDL_SCANCODE_LEFT:
      case SDL_SCANCODE_A:
        activeInputs.insert(InputType::TurnLeft);
        break;
      case SDL_SCANCODE_RIGHT:
      case SDL_SCANCODE_D:
        activeInputs.insert(InputType::TurnRight);
        break;
      case SDL_SCANCODE_SPACE:
        activeInputs.insert(InputType::Attack);
        break;
    }
  }

  void InputHandler::handleKeyUpEvents(SDL_KeyboardEvent* event)
  {
    switch (event->keysym.scancode)
    {
      case SDL_SCANCODE_UP:
      case SDL_SCANCODE_W:
        activeInputs.erase(InputType::SpeedUp);
        break;
      case SDL_SCANCODE_DOWN:
      case SDL_SCANCODE_S:
        activeInputs.erase(InputType::SpeedDown);
        break;
      case SDL_SCANCODE_LEFT:
      case SDL_SCANCODE_A:
        activeInputs.erase(InputType::TurnLeft);
        break;
      case SDL_SCANCODE_RIGHT:
      case SDL_SCANCODE_D:
        activeInputs.erase(InputType::TurnRight);
        break;
      case SDL_SCANCODE_SPACE:
        activeInputs.erase(InputType::Attack);
        break;
    }
  }
}