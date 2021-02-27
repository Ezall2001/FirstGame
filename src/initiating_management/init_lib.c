#include "../headers/init.h"
#include "../headers/dev.h"

void init_lib()
{
  // init mainSDL
  int sdl_init = SDL_Init(SDL_INIT_EVERYTHING);
  if (sdl_init != 0)
    lib_errorLog("failed at SDL_Init", SDL_GetError());

  //init SDL_img
  int IMG_flags = IMG_INIT_JPG | IMG_INIT_PNG;
  int IMG_bitMask = IMG_Init(IMG_flags);
  if ((IMG_bitMask & IMG_flags) != IMG_flags)
    lib_errorLog("failed at IMG_Init", IMG_GetError());

  //init SDL_ttf
  int ttf_init = TTF_Init();
  if (ttf_init == -1)
    lib_errorLog("failed at TTF_Init", TTF_GetError());

  //init SDL_mixer
  int MIX_flags = MIX_INIT_MP3; ///TODO: check for init wav;
  int MIX_bitmask = Mix_Init(MIX_flags);
  if ((MIX_bitmask & MIX_flags) != MIX_flags)
    lib_errorLog("failed at MIX_init", Mix_GetError());
}

void quit_lib()
{
  int opened_audio = Mix_QuerySpec(NULL, NULL, NULL);
  while (opened_audio != 0)
  {
    Mix_CloseAudio();
    opened_audio -= 1;
  }

  while (Mix_Init(0))
    Mix_Quit();

  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}