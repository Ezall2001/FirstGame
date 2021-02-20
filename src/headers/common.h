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
  int menu_scene; // 0:mainMenu - 1:startMenu - 2:optionsMenu - 3:tutorialMenu
  int mute;
  int music_volume; // 0 -> 100
  int SFX_volume;   // 0 -> 100

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
  char name[20];
  SDL_Texture *text;
  SDL_Rect button_Coords;
  SDL_Rect text_Coords;
  int hover; // 0: static - 1: hover
  int staged;
} Button;

typedef struct
{
  Button scene_buttons[4];
  SDL_Texture *buttons_Background;
  SDL_Rect buttons_Background_Coords;
  int buttons_Margin;

} Menu_Scene0_UI;

typedef struct
{

  // font & color
  TTF_Font *menu_Font;
  SDL_Color title_Color;
  SDL_Color text_Color;

  // text
  SDL_Texture *title_Text;

  // imgs
  SDL_Texture *static_Button;
  SDL_Texture *static_Blue_Button;
  SDL_Texture *hover_Button;
  SDL_Texture *main_Background;

  // coords
  SDL_Rect title_Coords;
  SDL_Rect main_Background_Coords;

} Menu_Common_UI;

typedef struct
{
  ///TODO: make this the big UI struct
  Menu_Common_UI common_UI;
  Menu_Scene0_UI scene0_UI;

} MenuUI;

typedef struct
{
  // mouse
  int mouse_x, mouse_y;

  // keyboard
  int ctrl;
  SDL_KeyCode keys[50];
  int num_keys;

} GameInput;

typedef struct
{
  GameWindow window;
  GameDev dev;
  GameInput input;

  // UI
  DevUI devUI;
  MenuUI menuUI;

} GameObject;

#endif