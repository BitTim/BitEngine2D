#pragma once

#include "../Engine/ecs.hh"
#include "../Engine/vector2.hh"

class TransformComponent : public Component
{
private:
  Vector2 pos;
  Vector2 size;

public:
  TransformComponent() { pos.set(0, 0); }
  TransformComponent(int x, int y, int scale)
  { pos.set(x, y); size.set(32, 32); size.scale(scale); }
  TransformComponent(int x, int y, int w, int h, int scale)
  { pos.set(x, y); size.set(32, 32); size.scale(scale); }
};