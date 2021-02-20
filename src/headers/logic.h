#ifndef LOGIC_H_DEFINED
#define LOGIC_H_DEFINED

#include "./common.h"

void logic_manager(GameObject *G);

// out game
void update_Window_Coords(GameWindow *window);
void update_Menu_Coords(MenuUI *ui, GameWindow *window);
void update_Menu_Common_Coords(Menu_Common_UI *ui, GameWindow *window);
void mouse_Button_Collision(Menu_Scene0_UI *ui, GameWindow *window);

#endif
