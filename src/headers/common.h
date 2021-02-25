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
  int hover;  // 0: static - 1: hover
  int staged; // 0: nokeydown - 1: keydown
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
  ///TODO: finish this

} Menu_Scene1_UI;

typedef struct
{
  // img
  SDL_Texture *settings_Backgournd;
  SDL_Texture *plus;
  SDL_Texture *minus;
  SDL_Texture *hover_Plus;
  SDL_Texture *hover_Minus;
  SDL_Texture *sound_Bar;
  SDL_Texture *sound_Scroller;

  // text
  SDL_Texture *settings_Title_Text;
  SDL_Texture *music_Text;
  SDL_Texture *SFX_Text;

  // coords
  SDL_Rect settings_Title_Coords;
  SDL_Rect settings_Title_Text_Coords;
  SDL_Rect settings_Backgournd_Coords;
  SDL_Rect music_Title_Coords;
  SDL_Rect music_Title_Text_Coords;
  SDL_Rect music_Bar_Coords;
  SDL_Rect SFX_Title_Coords;
  SDL_Rect SFX_Title_Text_Coords;
  SDL_Rect SFX_Bar_Coords;

  // buttons
  Button volume_Scorllers[2];
  Button volume_Controllers[4];
  int row_Margin;
  int column_Margin;
  ///TODO: find a solution for this to make the + - bar scroller  buttons

} Menu_Scene2_UI;

typedef struct
{
  // img
  SDL_Texture *tutorial_Backgournd;

  // text
  SDL_Texture *tutorial_Title_Text;

  // coords
  SDL_Rect tutorial_Title_Coords;
  SDL_Rect tutorial_Title_Text_Coords;
  SDL_Rect tutorial_Backgournd_Coords;

} Menu_Scene3_UI;
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
  SDL_Texture *click_Button;
  SDL_Texture *main_Background;
  SDL_Texture *mute_Shortcut;
  SDL_Texture *hover_Mute_Shortcut;
  SDL_Texture *unmute_Shortcut;
  SDL_Texture *hover_Unmute_Shortcut;
  SDL_Texture *back_Shortcut;
  SDL_Texture *hover_Back_Shortcut;

  // coords
  SDL_Rect title_Coords;
  SDL_Rect main_Background_Coords;

  // shortcuts
  Button scene_shortcuts[2];
  int shortcuts_Margin;

} Menu_Common_UI;

typedef struct
{

  DevUI dev_UI;
  // menu
  Menu_Common_UI common_UI;
  Menu_Scene0_UI scene0_UI;
  Menu_Scene1_UI scene1_UI;
  Menu_Scene2_UI scene2_UI;
  Menu_Scene3_UI scene3_UI;

} GameUI;

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
  // music
  Mix_Music *title_music;

  // chunk
  Mix_Chunk *bird_SFX;
  Mix_Chunk *wind_SFX;
  Mix_Chunk *waves_SFX;
  Mix_Chunk *click_SFX;

  // states
  int pause;
  int rewind;
  int mute;         // 0:volume  1:volume=0
  int music_volume; // 0 -> 100
  int SFX_volume;   // 0 -> 100

  int menu_playing;
  int wind_play;
  int button_click_play;
  int bird_play;
  int wave_play;
} GameSound;

typedef struct
{
  GameWindow window;
  GameDev dev;
  GameInput input;
  GameSound sound;
  GameUI UI;

} GameObject;

// utils
void load_Texture_Img(SDL_Texture **texture, char path[], SDL_Renderer **renderer);
void load_Texture_Text(SDL_Texture **texture, TTF_Font **font, char text[], SDL_Color color, SDL_Renderer **renderer);
float get_Text_W_ratio(Menu_Common_UI *common_ui, char text[]);

#endif