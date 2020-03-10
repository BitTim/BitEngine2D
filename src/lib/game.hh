#pragma once
#include "Engine/engine.hh"

struct Game
{
  static Engine* engine;
  
  Game() { }

  void init();
  void evHandle();
  void update();
  void render();
  void terminate();

  ~Game() { }
};