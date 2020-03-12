#include "../../lib/Engine/Managers/assetManager.hh"
#include "../../lib/Engine/Managers/textureManager.hh"

void AssetManager::addTexture(std::string id, std::string path)
{ textures.emplace(id, TextureManager::load(path)); }

SDL_Texture* AssetManager::getTexture(std::string id)
{ return textures[id]; }