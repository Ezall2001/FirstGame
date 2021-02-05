#ifndef DEV_H_DEFINED
#define DEV_H_DEFINED

#include "./common.h"

void dev_manager(int argc, char *argv[], GameObject *G);

// flags
void displayFPS();
void set_fullScreen(GameWindow *window);

// errors handling
void lib_errorLog(char msg[], const char *error);

#endif