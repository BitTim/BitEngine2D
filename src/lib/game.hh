#pragma once
#include "Engine/engine.hh"

class Game
{
public:
  static Engine* engine;
  
  Game() { }

  void init();
  void evHandle();
  void update();
  void render();
  void terminate();

  ~Game() { }
};