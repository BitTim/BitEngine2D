#pragma once

#include "../Engine/ecs.hh"
#include "../Engine/vector2.hh"
#include "../Engine/constants.hh"

class TransformComponent : public Component
{
public:
  Vector2 pos;
  Vector2 size;
  int scale = 1;

  TransformComponent() { pos.set(0, 0); }
  TransformComponent(int x, int y, int scale)
  { pos.set(x, y); size.set(_TILESIZE, _TILESIZE); this->scale = scale; }
  TransformComponent(int x, int y, int w, int h, int scale)
  { pos.set(x, y); size.set(w, h); this->scale = scale; }
};