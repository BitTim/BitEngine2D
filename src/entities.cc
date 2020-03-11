#include "lib/entities.hh"
#include "lib/ECS Components/components.hh"
#include "lib/Engine/engine.hh"

void EntitiyCreator::player()
{
  Entity& playerEntity(Engine::entityManager->addEntity());
  playerEntity.addComponent<TransformComponent>(10, 10, 2);
  
  playerEntity.addGroup(Engine::egPlayer);

  Engine::entities.push_back(&playerEntity);
}

void EntitiyCreator::tile()
{

}