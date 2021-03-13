#ifndef UISTRUCTS_H_DEFINED
#define UISTRUCTS_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "mtwister.h"

////////////////////////////////////
// minor struct
////////////////////////////////////
typedef struct
{
  char name[20];
  SDL_Texture *text;
  SDL_Rect button_Coords;
  SDL_Rect text_Coords;
  int hover;    // 0: static - 1: hover
  int staged;   // 0: nokeydown - 1: keydown
  int selected; // 0: notSelected - 1: selected

} Button;

typedef struct
{
  ///TODO: finish the Outline struct
  // coords
  SDL_Rect box_coords;
  SDL_Rect roam_range_coords;
  SDL_Rect detection_range_coords;
  SDL_Rect obstacle_range_coords;
  SDL_Rect attack_range_coords;
  SDL_Rect dmg_range_coords;
  SDL_Rect escape_range_coords;
  SDL_Rect direction_coords;
  SDL_Rect checkpoints[4];

  // colors
  SDL_Color box_color;             // brown: bird
  SDL_Color roam_range_color;      // cian
  SDL_Color detection_range_color; // dark cian
  SDL_Color obstacle_range_color;  // orange
  SDL_Color attack_range_color;    // red pink
  SDL_Color dmg_range_color;       // red
  SDL_Color escape_range_color;    // white
  SDL_Color direction_color;
  SDL_Color checkpoints_color;

} Outline;

////////////////////////////////////
// popups UI
////////////////////////////////////
typedef struct
{
  // texture
  SDL_Texture *title_Text;
  SDL_Texture *pop_Background;

  // coords
  SDL_Rect pop_Background_Coords;
  SDL_Rect title_Text_Coords;
  SDL_Rect title_Background_Coords;

  // buttons
  Button confirm[2];
  int column_Margin;

} Quit_PopUp;

typedef struct
{
  ///TODO: finish credits struct
} Credits_PopUp;

////////////////////////////////////
// menu UIs
////////////////////////////////////
typedef struct
{

  // font & color
  TTF_Font *menu_Font;
  SDL_Color text_Color;

  // imgs
  SDL_Texture *static_Button;
  SDL_Texture *static_Red_Button;
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

  // sprite
  SDL_Texture *bird1[9];
  SDL_Texture *bird2[9];
  SDL_Texture *bird3[9];
  SDL_Texture *wind[28];

  // coords
  SDL_Rect main_Background_Coords;
  SDL_Rect birdCoords;
  SDL_Rect dst_birdCoords;
  SDL_Rect windCoords;

  // animation states
  float bird_speed;
  float wind_speed;
  int bird_animation_play; // 0:noAnimation - 1:bird1 - 2:bird2 - 3:bird3 - negative:flipAnimation
  int wind_animation_play;

  // shortcuts
  Button scene_shortcuts[2];
  int shortcuts_Margin;

} Menu_Common_UI;

typedef struct
{
  Button scene_buttons[4];
  SDL_Texture *buttons_Background;
  SDL_Texture *button_Icons[4];
  SDL_Rect icons_Coords[4];
  SDL_Rect buttons_Background_Coords;
  int buttons_Margin;

} Menu_Scene0_UI;

typedef struct
{
  ///TODO: finish scene1 struct

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
  Button resolution_Controllers[3];
  Button fps_Controllers[3];
  Button credits[1];

  int row_Margin;
  int column_Margin;

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

////////////////////////////////////
// other UIs
////////////////////////////////////
typedef struct
{

  TTF_Font *dev_Font;
  SDL_Texture *FPS_Text;
  SDL_Color FPS_Color;
  Outline outlines[40];
  int outlines_num;
} DevUI;

typedef struct
{
  // sprites
  ///TODO: finish gameUI struct

  // test map
  ///TODO: delete test map
  SDL_Texture *map;
  SDL_Rect src_Map_Coords;

} In_Game_UI;

#endif