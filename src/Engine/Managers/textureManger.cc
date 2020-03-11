#include "../../lib/Engine/Managers/textureManager.hh"
#include "../../lib/Engine/engine.hh"
#include <SDL2/SDL_image.h>

SDL_Texture* TextureManager::load(std::string path)
{
  SDL_Surface* surface = IMG_Load(path.c_str());
  SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::renderer, surface);
  SDL_FreeSurface(surface);

  return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip)
{
  SDL_RenderCopyEx(Engine::renderer, texture, &src, &dst, 0, NULL, flip);
}