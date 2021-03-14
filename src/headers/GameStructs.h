#ifndef GAMESTRUCTS_H_DEFINED
#define GAMESTRUCTS_H_DEFINED

#include "./logicStructs.h"
#include "./UIStructs.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "mtwister.h"

typedef struct
{
  SDL_Window *mainWindow;
  SDL_Renderer *mainRenderer;
  MTRand r;
  int fullScreen;
  int running;
  int x, y, w, h, default_w, default_h, max_w, max_h;
  float win_width_ratio;
  int game_scene; // 0:outgame - 1:ingame
  int game_stage;
  int in_game_init;
  int menu_scene; // 0:mainMenu - 1:startMenu - 2:optionsMenu - 3:tutorialMenu
  int popUp;      // 0:nopopUp - 1:QuitPopUp - 2:CreditsPopUp

} GameWindow;

typedef struct
{
  // states
  int show_FPS;
  int show_boxes;
  int show_ranges;
  int show_directions;
  int change_character;
  int spawn_enemy;

  // FPS things
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

  DevUI dev_UI;
  // menu
  Menu_Common_UI common_UI;
  Menu_Scene0_UI scene0_UI;
  Menu_Scene1_UI scene1_UI;
  Menu_Scene2_UI scene2_UI;
  Menu_Scene3_UI scene3_UI;

  // in game
  In_Game_UI in_game_UI;

  // pop ups
  Quit_PopUp quit_PopUp;
  Credits_PopUp credits_PopUp;

} GameUI;

typedef struct
{
  // mouse
  int mouse_x, mouse_y;

  // keyboard
  int ctrl;
  int keys[50];
  int num_keys;
  const Uint8 *keyboard_state;

} GameInput;

typedef struct
{
  // music
  Mix_Music *menu_music;

  // chunk
  Mix_Chunk *bird_SFX;
  Mix_Chunk *wind_SFX;
  Mix_Chunk *waves_SFX;
  Mix_Chunk *click_SFX;

  // states
  int mute;         // 0:volume  1:volume=0
  int music_volume; // 0 -> 100
  int SFX_volume;   // 0 -> 100

  int wind_play;
  int button_click_play;
  int bird_play;
  int wave_play;
} GameSound;

typedef struct
{
  // map system coords
  real_Rect MAP_Origin_Coords;
  real_Rect MAP_Map_Coords;
  real_Rect MAP_Cam_Coords;
  float CAM_REAL_Cam_w_Ratio;

  // real system coords
  real_Rect cam_Coords;

  // objects definition
  Character survivors[4]; // 0:JAMES - 1:MARIE - 2:CAPTAIN WILL - 3:HULI
  Enemie enemy_types[10]; // 0:BIRD - 1:SHEEP
  Obstacle obstacle_types[5];

  // stage objects
  Character players[3]; // 0:ACTIVE - 1:ACTIVE - 2:PASSIVE
  Enemie enemies[50];
  Obstacle obstacles[20];

  int enemy_num;
  int obstacle_num;

} GameLogic;

#endif