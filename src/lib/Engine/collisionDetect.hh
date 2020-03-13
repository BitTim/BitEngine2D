#pragma once
#include <SDL2/SDL.h>

class CollisionComponent;

class Collision
{
public:
  static bool aabb(const SDL_Rect& rA, const SDL_Rect& rB);
  static bool aabb(const CollisionComponent& cA, const CollisionComponent& cB);
};