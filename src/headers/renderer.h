#ifndef RENDERER_H_DEFINED
#define RENDERER_H_DEFINED

#include "./common.h"

void renderer_manager(GameObject *G);

// common
void update_renderer(GameWindow *window);
void render_FPS(GameWindow *window, DevUI *ui, GameDev dev);

// menu
void render_Scene0_Menu(MenuUI *ui, GameWindow *window);
void render_Common_Menu(Menu_Common_UI *ui, GameWindow *window);


#endif