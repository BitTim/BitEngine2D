#include "lib/entities.hh"
#include "lib/ECS Components/components.hh"
#include "lib/Engine/engine.hh"

void EntitiyCreator::player()
{
  auto& playerEntity(Engine::entityManager->addEntity());
  playerEntity.addComponent<TransformComponent>(10, 10, 2);

  Engine::entities.emplace("player", playerEntity);
}