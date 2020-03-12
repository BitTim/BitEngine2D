#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "../Engine/engine.hh"
#include "../Engine/Managers/textureManager.hh"
#include "transform.hh"

class SpriteComponent : public Component
{
private:
  TransformComponent* transform;
  SDL_Texture* texture;
  SDL_Rect src, dst;

public:
  SDL_RendererFlip flip = SDL_FLIP_NONE;

  SpriteComponent() { }
  SpriteComponent(std::string textureID)
  {
    setTexture(textureID);
  }

  void setTexture(std::string textureID)
  {
    texture = Engine::assets->getTexture(textureID);
  }

  void init() override
  {
    transform = &entity->getComponent<TransformComponent>();
    src = {0, 0,
      static_cast<int>(transform->size.x),
      static_cast<int>(transform->size.y)};
    dst = {0, 0,
      static_cast<int>(transform->size.x) * transform->scale,
      static_cast<int>(transform->size.y) * transform->scale};
  }

  void update() override
  {
    dst.x = static_cast<int>(transform->pos.x) - Engine::camera.x;
    dst.y = static_cast<int>(transform->pos.y) - Engine::camera.y;
    dst.w = static_cast<int>(transform->size.x) * transform->scale;
    dst.h = static_cast<int>(transform->size.y) * transform->scale;
  }

  void draw() override
  {
    TextureManager::draw(texture, src, dst, flip);
  }
};