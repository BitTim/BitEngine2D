#include "../lib/Engine/engine.hh"
#include "../lib/Engine/logger.hh"

SDL_Renderer* Engine::renderer = nullptr;
SDL_Event Engine::event;
bool Engine::running = true;

EntityManager* Engine::entityManager = nullptr;
AssetManager* Engine::assets = nullptr;
std::vector<Entity*> Engine::entities;
std::vector<std::vector<Entity*>> Engine::entityGroups;

SDL_Rect Engine::camera = {0, 0, 640, 480};

void Engine::init(std::string title, int x, int y, int w, int h, bool fullscreen)
{
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow(title.c_str(), x, y, w, h, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  Logger::log("init", "Initialized SDL");

  entityManager = new EntityManager();
  assets = new AssetManager();
  Logger::log("init", "Created Managers");
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
  for(int i = 0; i < entityGroups.size(); i++)
  {
    for(auto& e : entityGroups[i]) e->draw();
  }
}

void Engine::terminate()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  Logger::log("terminate", "Terminated SDL");
}