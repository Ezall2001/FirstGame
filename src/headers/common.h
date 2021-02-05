#ifndef COMMON_H_DEFINED
#define COMMON_H_DEFINED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

typedef struct
{
  SDL_Window *mainWindow;
  int fullScreen;

  ///TODO: delete these if you don't need it after tests
  int max_w;
  int max_h;
} GameWindow;

typedef struct
{
  GameWindow window;

  int running;

} GameObject;

#endif