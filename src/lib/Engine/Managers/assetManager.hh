#pragma once

#include <SDL2/SDL.h>
#include <map>

class AssetManager
{
public:
  void addTexture(std::string id, std::string path);
  SDL_Texture* getTexture(std::string id);

private:
  std::map<std::string, SDL_Texture*> textures;
};