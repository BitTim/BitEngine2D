#include "../lib/Engine/ecs.hh"

void Entity::addGroup(Group nGroup)
{
  groupBitSet[nGroup] = true;
  manager.addToGroup(this, nGroup);
}