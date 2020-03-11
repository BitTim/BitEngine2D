#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <map>

#include "ecs.hh"

class Engine
{
public:
  static SDL_Renderer* renderer;
  static SDL_Event event;
  static bool running;

  static EntityManager* entityManager;
  static std::map<std::string, Entity&> entities;

  SDL_Window* window;

  Engine() { }

  void init(std::string title, int x, int y, int w, int h, bool fullscreen);
  void evHandle();
  void update();
  void render();
  void terminate();

  ~Engine() { }
};