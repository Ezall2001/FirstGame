#ifndef LOGIC_H_DEFINED
#define LOGIC_H_DEFINED

#include "./common.h"

void logic_manager(GameObject *G);

// out game
void update_Window_Coords(GameWindow *window);
void update_Menu_Coords(MenuUI *ui, GameWindow *window);

#endif
