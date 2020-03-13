#pragma once

#include "../Engine/ecs.hh"
#include "../Engine/vector2.hh"
#include "transform.hh"

class PlatformerPhysicsComponent : public Component
{
private:
  TransformComponent* transform;
  const float gravity = 0.5f;

public:
  float speed = 2.0f;
  Vector2 vel;

  void init() override
  {
    transform = &entity->getComponent<TransformComponent>();
  }

  void update() override
  {
    vel.y += gravity;
    transform->pos += vel;
  }
};