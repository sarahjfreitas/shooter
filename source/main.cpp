#include <iostream>

using std::cout;
using std::endl;

#include "game.h"

int main(int argc, char* argv[])
{
	Game game;

  while (game.isRunning())
  {
    Uint32 frameStart = SDL_GetTicks();
    game.handleEvents();
    game.update();
    game.draw();
    game.limitFps(frameStart);
  }

  return 0;
}
