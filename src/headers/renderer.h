#ifndef RENDERER_H_DEFINED
#define RENDERER_H_DEFINED

#include "./common.h"

void renderer_manager(GameObject *G);

// common
void update_window(GameWindow *window);
void render_firstLayer(GameWindow *window);
void render_FPS(GameWindow *window, UI *ui, GameDev dev);

#endif