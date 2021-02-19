#ifndef RENDERER_H_DEFINED
#define RENDERER_H_DEFINED

#include "./common.h"

void renderer_manager(GameObject *G);

// common
void update_renderer(GameWindow *window);
void render_FPS(GameWindow *window, DevUI *ui, GameDev dev);

// menu
void render_main_menu(MenuUI *ui, GameWindow *window);

#endif