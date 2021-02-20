#ifndef LOGIC_H_DEFINED
#define LOGIC_H_DEFINED

#include "./common.h"

void logic_manager(GameObject *G);

//   ---- common ----
// coords
void update_Window_Coords(GameWindow *window);


//   ---- menu ----
// coords 
void update_Menu_Coords(MenuUI *ui, GameWindow *window);
void update_Menu_Common_Coords(Menu_Common_UI *ui, GameWindow *window);
void update_Menu_Scene0_Coords(Menu_Scene0_UI *ui, GameWindow *window);

// collisions
void mouse_Button_Collision(Button buttons[], int num_Button, GameWindow *window);

#endif
