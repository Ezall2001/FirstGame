#include "../headers/init.h"
#include "../headers/dev.h"

void load_Texture_Img(SDL_Texture **texture, char path[], SDL_Renderer **renderer)
{
  SDL_Surface *tempSurface = NULL;
  SDL_RWops *tempPath = NULL;

  tempPath = tempPath = SDL_RWFromFile(path, "rb");
  if (tempPath == NULL)
    lib_errorLog("failed at getting img path", SDL_GetError());

  tempSurface = IMG_LoadPNG_RW(tempPath);
  if (tempSurface == NULL)
    lib_errorLog("failed at loading img from path", IMG_GetError());

  *texture = SDL_CreateTextureFromSurface(*renderer, tempSurface);

  SDL_FreeSurface(tempSurface);
  SDL_FreeRW(tempPath);
}

void load_Texture_Text(SDL_Texture **texture, TTF_Font **font, char text[], SDL_Color color, SDL_Renderer **renderer)
{
  SDL_Surface *tempSurface = NULL;

  tempSurface = TTF_RenderUTF8_Blended(*font, text, color);
  if (tempSurface == NULL)
    lib_errorLog("failed at rendering font", TTF_GetError());

  *texture = SDL_CreateTextureFromSurface(*renderer, tempSurface);
  if (*texture == NULL)
  {
    lib_errorLog("failed at creating texture from font", SDL_GetError());
  }

  SDL_FreeSurface(tempSurface);
}
