#ifndef COMMON_H_DEFINED
#define COMMON_H_DEFINED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
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
  int x, y, w, h, default_w, default_h, max_w, max_h;
  float win_width_ratio;
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
  ///TODO: refactor the menu UI
} Menu_Scene0_UI;
typedef struct
{
  // fonts
  TTF_Font *menu_Font;

  // colors
  SDL_Color title_Color;
  SDL_Color text_Color;

  // text ( with no background )
  SDL_Texture *title_Text;

  // imgs
  SDL_Texture *static_Button;
  SDL_Texture *hover_Button;
  SDL_Texture *main_Background;
  SDL_Texture *menu_Background;

  // coords
  SDL_Rect title_Coords;
  SDL_Rect main_Background_Coords;

  // menu scene 0 buttons and coords
  SDL_Texture *buttons_Text[4];
  SDL_Rect buttons_Coords[4];

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