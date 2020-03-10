#include "../../lib/Entity Component System/entityCompSys.hh"

void Entity::addGroup(Group nGroup)
{
  groupBitSet[nGroup] = true;
  manager.addToGroup(this, nGroup);
}