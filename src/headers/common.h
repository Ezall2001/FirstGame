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
  SDL_Renderer *mainRenderer;
  int fullScreen;
  int running;
  int x, y, w, h, max_w, max_h;
  int game_scene; // 0:outgame - 1:ingame
  int menu_scene; // 0:mainMenu

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
  SDL_Texture *FPS_Text;
  SDL_Color FPS_Color;

} DevUI;

typedef struct
{
  TTF_Font *menu_Font;
  SDL_Color title_Color;
  SDL_Color text_Color;

  // text
  SDL_Texture *title_Text;
  SDL_Texture *start_Text;
  SDL_Texture *settings_Text;
  SDL_Texture *tutorial_Text;
  SDL_Texture *quit_Text;

  // imgs
  SDL_Texture *static_Button;
  SDL_Texture *hover_Button;
  SDL_Texture *main_Background;
  SDL_Texture *menu_Background;

  // coords
  SDL_Rect main_Background_Coords;
  SDL_Rect title_Coords;
  SDL_Rect start_Coords;
  SDL_Rect sttings_Coords;
  SDL_Rect tutorial_Coords;
  SDL_Rect quit_Coords;

} MenuUI;

typedef struct
{
  GameWindow window;
  GameDev dev;

  // UI
  DevUI devUI;
  MenuUI menuUI;

} GameObject;

#endif