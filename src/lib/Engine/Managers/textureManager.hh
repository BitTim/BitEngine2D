#pragma once

#include <SDL2/SDL.h>
#include <string>

struct TextureManager
{
  static SDL_Texture* load(std::string path);
  static void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip);
};