#ifndef INIT_H_DEFINED
#define INIT_H_DEFINED

#include "./common.h"

void init_manager(GameObject *G);

// lib
void init_lib();
void quit_lib();

// gameObject
void init_gameWindow(GameWindow *window);
void init_gameDev(GameDev *dev);
void init_devUI(DevUI *ui);

void init_menuUI(MenuUI *ui, GameWindow *window);
void init_Common_Menu(Menu_Common_UI *ui, GameWindow *window);
void init_Scene0_Menu(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window);


void destroy_GameObject(GameObject *G);

// load texture
void load_Texture_Img(SDL_Texture **texture, char path[], SDL_Renderer **renderer);
void load_Texture_Text(SDL_Texture **texture, TTF_Font **font, char text[], SDL_Color color, SDL_Renderer **renderer);

#endif