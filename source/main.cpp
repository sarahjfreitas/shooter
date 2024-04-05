#include <iostream>
#include <SDL.h>

using std::cout;
using std::endl;

#include "game.h"

int main(int argc, char* argv[])
{
  Game game;
  while (game.isRunning())
  {
    Uint32 frameStart = SDL_GetTicks();
    game.update();
    game.draw();
    game.limitFps(frameStart);
  }

  return 0;
}
