#ifndef DEV_H_DEFINED
#define DEV_H_DEFINED

#include "./common.h"

void dev_manager(int *argc, char *argv[], GameObject *G);
void dev_loop(GameObject *G);

// flags
void set_fullScreen(char flag[], GameWindow *window);
void set_FPS(char flag[], GameDev *dev);
void set_FPS_cap(char flag[], GameDev *dev);
void set_mute(char flag[], GameSound *sound);
void set_outlines(char flag[], GameDev *dev);

// scenarios
void proto1(char scn[], GameObject *G);
void lvl_simulation(char scn[]);
void responsive_UI(char scn[]);

//main loop
void calcFPS(GameDev *dev);
void set_DeltaTime(GameDev *dev);
void set_Outlines_Coords(GameLogic *logic, DevUI *ui, GameWindow *window);

//direct call functions
void cap_FPS(GameDev dev);

#endif
