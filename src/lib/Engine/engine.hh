#pragma once

#include <SDL2/SDL.h>
#include <string>

class Engine
{
public:
  static SDL_Renderer* renderer;
  static SDL_Event event;
  static bool running;

  SDL_Window* window;

  Engine() { }

  void init(std::string title, int x, int y, int w, int h, bool fullscreen);
  void evHandle();
  void update();
  void terminate();

  ~Engine() { }
};