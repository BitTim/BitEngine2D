#include "lib/game.hh"

Game* game;

int targetFPS = 60;
int targetDelay = 1000 / targetFPS;
Uint32 frameDelay;

int main()
{
  game = new Game();
  game->init();

  while(Engine::running)
  {
    frameDelay = SDL_GetTicks();

    game->evHandle();
    game->update();
    game->render();

    frameDelay = SDL_GetTicks() - frameDelay;
    if(frameDelay < targetDelay) SDL_Delay(targetDelay - frameDelay);
  }

  game->terminate();
  return 0;
}