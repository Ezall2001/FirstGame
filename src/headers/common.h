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

#define defaultFps 60
typedef struct
{
  SDL_Window *mainWindow;
  SDL_Surface *mainSurface;
  int fullScreen;
  int x, y, w, h, max_w, max_h;

} GameWindow;

typedef struct
{
  int show_FPS;
  int FPS;
  int FPS_cap;
  Uint32 currTick;
  Uint32 prevTick;
  int frameDelays[10];
  int frameDelayCount;
  int frameDelayIndex;
  float frameDelayAvg;
  float deltaTime;

} GameDev;

typedef struct
{
  TTF_Font *dev_Font;
  SDL_Surface *FPS_surface;
  SDL_Color FPS_Color;

} UI;

typedef struct
{
  GameWindow window;
  GameDev dev;
  UI ui;

  int running;

} GameObject;

#endif