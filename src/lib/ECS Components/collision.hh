#pragma once

#include "../Engine/ecs.hh"
#include "../Engine/Managers/textureManager.hh"
#include "../Engine/engine.hh"
#include "transform.hh"
#include <SDL2/SDL.h>

class CollisionComponent : public Component
{
public:
  SDL_Rect collider;
  std::string tag;

  SDL_Texture* texture;
  SDL_Rect src, dst;

  TransformComponent* transform;

  CollisionComponent(std::string nTag, int nX, int nY, int nSize)
  {
    tag = nTag;
    collider = {nX, nY, nSize, nSize};
  }

  void init() override
  {
    if(!entity->hasComponent<TransformComponent>()) entity->addComponent<TransformComponent>();
    transform = &entity->getComponent<TransformComponent>();

    texture = TextureManager::load("dat/collider.png");
    src = {0, 0, _TILESIZE, _TILESIZE};
    dst = {collider.x, collider.y, collider.w, collider.h};
  }

  void update() override
  {
    if(tag != "terrain") 
    {
      collider = {static_cast<int>(transform->pos.x), static_cast<int>(transform->pos.y),
        static_cast<int>(transform->size.x) * transform->scale, static_cast<int>(transform->size.y) * transform->scale};
    }
    
    dst.x = collider.x - Engine::camera.x;
    dst.y = collider.y - Engine::camera.y;
  }

  void draw() override
  {
    TextureManager::draw(texture, src, dst, SDL_FLIP_NONE);
  }
};