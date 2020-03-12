#include "lib/game.hh"
#include "lib/Engine/logger.hh"
#include "lib/Engine/Managers/textureManager.hh"
#include "lib/entities.hh"

Engine* Game::engine = nullptr;

void Game::init()
{
  engine = new Engine();
  engine->init("BitEngine2D Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, false);

  Engine::assets->addTexture("missing", "dat/missing.png");
  Logger::log("init", "Loaded Textures");

  EntitiyCreator::player();
  Logger::log("init", "Created Entities");

  Engine::entityGroups.push_back(Engine::entityManager->getGroup(egPlayer));
  Logger::log("init", "Created Entity Groups");
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