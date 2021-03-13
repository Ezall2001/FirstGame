#ifndef INIT_H_DEFINED
#define INIT_H_DEFINED

#include "./common.h"

void init_manager(GameObject *G);

// lib
void init_lib();
void quit_lib();

// gameObject
void init_GameWindow(GameWindow *window);
void init_GameDev(GameDev *dev);
void init_GameInput(GameInput *input);
void init_GameUI(GameUI *ui, GameWindow *window);
void init_GameSound(GameSound *sound);
void init_GameLogic(GameLogic *logic, In_Game_UI *ui);

void destroy_GameObject(GameObject *G);

// init UI
void init_DevUI(DevUI *ui);
void init_Common_Menu(Menu_Common_UI *ui, GameWindow *window);
void init_Scene0_Menu(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void init_Scene1_Menu(Menu_Scene1_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void init_Scene2_Menu(Menu_Scene2_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void init_Scene3_Menu(Menu_Scene3_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void init_Quit_PopUp(Quit_PopUp *ui, Menu_Common_UI *common_ui, GameWindow *window);
void init_In_Game_UI(In_Game_UI *ui, GameWindow *window);

// init Logic
void init_survivors(GameLogic *logic);
void init_bird(GameLogic *logic, int stage);

#endif