#include "lib/game.hh"

Engine* Game::engine = nullptr;

void Game::init()
{
  engine = new Engine();
  engine->init("BitEngine2D Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, false);
}

void Game::evHandle()
{
  engine->evHandle();
}

void Game::update()
{
  engine->update();
}

void Game::render()
{
  SDL_SetRenderDrawColor(Engine::renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(Engine::renderer);

  engine->render();

  SDL_RenderPresent(Engine::renderer);
}

void Game::terminate()
{
  engine->terminate();
  delete engine;
}