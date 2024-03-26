#include <iostream>

using std::cout;
using std::endl;

#include "game.h"

int main(int argc, char* argv[])
{
	Game game;

  while (game.isRunning())
  {
    game.handleEvents();
    game.draw();
    SDL_Delay(16);
  }

  return 0;
}
