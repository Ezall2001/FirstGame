#ifndef LOGIC_H_DEFINED
#define LOGIC_H_DEFINED

#include "./common.h"

void logic_manager(GameObject *G);

//   ---- common ----
// coords
void update_Window_Coords(GameWindow *window);

//   ---- menu ----
// coords
void update_Menu_Common_Coords(Menu_Common_UI *ui, GameWindow *window);
void update_Menu_Scene0_Coords(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void update_Menu_Scene1_Coords(Menu_Scene1_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void update_Menu_Scene2_Coords(Menu_Scene2_UI *ui, Menu_Common_UI *common_ui, GameWindow *window, GameSound *sound);
void update_Menu_Scene3_Coords(Menu_Scene3_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);

// input
void shortcut_Input(GameInput *input, GameSound *sound, GameWindow *window, GameUI *ui, GameDev *dev);
void mouse_Button_Collision(Button buttons[], int num_Button, GameInput *input, GameSound *sound);
void stage_Button(Button buttons[], int num_Button);
void click_Button(Button buttons[], int num_Button, GameWindow *window, GameSound *sound, GameDev *dev);

#endif
