#ifndef LOGIC_H_DEFINED
#define LOGIC_H_DEFINED

#include "./common.h"

void logic_manager(GameObject *G);

/////////////////////////////////////
/////// common
////////////////////////////////////
void update_Window_Coords(GameWindow *window);

/////////////////////////////////////
/////// menu
////////////////////////////////////
// coords
void update_Menu_Common_Coords(Menu_Common_UI *ui, GameWindow *window);
void update_Menu_Scene0_Coords(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void update_Menu_Scene1_Coords(Menu_Scene1_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void update_Menu_Scene2_Coords(Menu_Scene2_UI *ui, Menu_Common_UI *common_ui, GameWindow *window, GameSound *sound);
void update_Menu_Scene3_Coords(Menu_Scene3_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void update_Quit_PopUp_Coords(Quit_PopUp *ui, Menu_Common_UI *common_ui, GameWindow *window);

// input
void shortcut_Input(GameInput *input, GameSound *sound, GameWindow *window, GameUI *ui, GameDev *dev);
void mouse_Button_Collision(Button buttons[], int num_Button, GameInput *input, GameSound *sound);
void stage_Button(Button buttons[], int num_Button);
void click_Button(Button buttons[], int num_Button, GameWindow *window, GameSound *sound, GameDev *dev, GameUI *ui);
void drag_Volume(Button buttons[], int num_Button, GameInput *input, GameSound *sound, SDL_Rect bar);
void update_Scroller_Coords(Button buttons[], int num_Button, GameSound *sound, SDL_Rect bar);

// animation
void bird_Animation(Menu_Common_UI *ui, GameWindow *window, GameSound *sound, GameDev *dev);
void wind_Animation(Menu_Common_UI *ui, GameWindow *window, GameSound *sound, GameDev *dev);
void menu_Intro_Animation(Menu_Common_UI *ui, GameWindow *window, GameDev *dev);
void scene0_Intro_Animation(Menu_Scene0_UI *ui, GameWindow *window, GameDev *dev);

/////////////////////////////////////
/////// game
////////////////////////////////////
// behavior
void main_player_Behavior(GameLogic *logic, GameWindow *window, GameDev *dev, GameInput *input);
void bird_Behavior(GameLogic *logic, GameWindow *window, GameDev *dev);

// spawn
void spawn_Players(GameLogic *logic, GameWindow *window);
void spawn_Obstacle(GameLogic *logic, GameWindow *window);
void spawn_on_edge(GameLogic *logic, GameWindow *window, int enemy_type);

void update_Cam_Coords(GameLogic *logic, GameWindow *window, In_Game_UI *ui);
void move(float speed, float ang, real_Rect *coords);
float get_ang(real_Rect src, real_Rect dst);

// input
void keyboard_Player_Input(GameLogic *logic, GameWindow *window, GameInput *input);

#endif
