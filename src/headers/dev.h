#ifndef DEV_H_DEFINED
#define DEV_H_DEFINED

#include "./common.h"

void dev_manager(int argc, char *argv[], GameObject *G);
void dev_loop(GameObject *G);

// flags
void set_fullScreen(char flag[], GameWindow *window);
void set_FPS(char flag[], GameDev *dev);
void set_FPS_cap(char flag[], GameDev *dev);

// scenarios
void proto1(char scn[]);
void lvl_simulation(char scn[]);

//main loop
void calcFPS(GameDev *dev);
void set_DeltaTime(GameDev *dev);

//direct call functions
void cap_FPS(GameDev dev);

// errors handling
void lib_errorLog(char msg[], const char *error);

#endif
