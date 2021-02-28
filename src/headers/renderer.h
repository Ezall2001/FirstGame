#ifndef RENDERER_H_DEFINED
#define RENDERER_H_DEFINED

#include "./common.h"

void renderer_manager(GameObject *G);

// common
void update_renderer(GameWindow *window);
void render_FPS(GameWindow *window, DevUI *ui, GameDev dev);
void render_BlackLayer(GameWindow *window, Uint8 alpha);

// menu
void render_Common_Menu(Menu_Common_UI *ui, GameWindow *window, GameSound *sound);
void render_Scene0_Menu(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void render_Scene1_Menu(Menu_Scene1_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void render_Scene2_Menu(Menu_Scene2_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void render_Scene3_Menu(Menu_Scene3_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);
void render_Quit_PopUp(Quit_PopUp *ui, Menu_Common_UI *common_ui, GameWindow *window);

#endif