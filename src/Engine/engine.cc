#include "../lib/Engine/engine.hh"
#include "../lib/Engine/entityLoader.hh"

SDL_Renderer* Engine::renderer = nullptr;
SDL_Event Engine::event;
bool Engine::running = true;

EntityManager* Engine::entityManager = nullptr;
std::map<std::string, Entity&> Engine::entities;

void Engine::init(std::string title, int x, int y, int w, int h, bool fullscreen)
{
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow(title.c_str(), x, y, w, h, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

  entityManager = new EntityManager();
  EntityLoader::load("dat/entitites.json");
}

void Engine::evHandle()
{
  SDL_PollEvent(&event);
  if(event.type == SDL_QUIT) running = false;
}

void Engine::update()
{
  entityManager->refresh();
  entityManager->update();
}

void Engine::render()
{
  entityManager->draw();
}

void Engine::terminate()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}