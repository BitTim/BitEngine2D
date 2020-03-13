
#include "../lib/Engine/collisionDetect.hh"
#include "../lib/ECS Components/collision.hh"

bool Collision::aabb(const SDL_Rect& rA, const SDL_Rect& rB)
{
  if(
    rA.x + rA.w >= rB.x &&
    rB.x + rB.w >= rA.x &&
    rA.y + rA.h >= rB.y &&
    rB.y + rB.h >= rA.y
    )
    return true;
  else return false;
}
bool Collision::aabb(const CollisionComponent& cA, const CollisionComponent& cB) { return aabb(cA.collider, cB.collider); }