#ifndef INIT_H_DEFINED
#define INIT_H_DEFINED

#include "./common.h"

void init_manager(GameObject *G);

// lib
void init_lib();
void quit_lib();

// gameObject
void init_gameWindow(GameWindow *window);

#endif