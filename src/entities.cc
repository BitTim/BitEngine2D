#include "lib/entities.hh"
#include "lib/ECS Components/components.hh"
#include "lib/game.hh"

void EntitiyCreator::player()
{
  Entity& playerEntity(Engine::entityManager->addEntity());
  playerEntity.addComponent<TransformComponent>(10, 10, 2);
  playerEntity.addComponent<SpriteComponent>("missing");
  playerEntity.addComponent<PlatformerPhysicsComponent>();
  playerEntity.addComponent<PlatformerInputClass>();
  
  playerEntity.addGroup(Game::egPlayer);

  Engine::entities.push_back(&playerEntity);
}

void EntitiyCreator::tile()
{

}