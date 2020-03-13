#pragma once

#include "../Engine/ecs.hh"
#include "../Engine/engine.hh"
#include "platformerPhysics.hh"

class PlatformerInputClass : public Component
{
private:
  PlatformerPhysicsComponent* physics;
  bool apressed = false, dpressed = false;

public:
  void init() override
  {
    physics = &entity->getComponent<PlatformerPhysicsComponent>();
  }

  void update() override
  {
    if(Engine::event.type == SDL_KEYDOWN)
    {
      if(Engine::event.key.keysym.sym == SDLK_a)
      {
        physics->vel.x = dpressed ? 0 : -physics->speed;
        apressed = true;
      }

      if(Engine::event.key.keysym.sym == SDLK_d)
      {
        physics->vel.x = apressed ? 0 : physics->speed;
        dpressed = true;
      }
      
      if(Engine::event.key.keysym.sym == SDLK_SPACE) physics->vel.y = -10;
    }

    if(Engine::event.type == SDL_KEYUP)
    {
      if(Engine::event.key.keysym.sym == SDLK_a)
      {
        physics->vel.x = dpressed ? physics->speed : 0;
        apressed = false;
      }

      if(Engine::event.key.keysym.sym == SDLK_d)
      {
        physics->vel.x = apressed ? -physics->speed : 0;
        dpressed = false;
      }
    }
  }
};