#ifndef SAVE_H_DEFINED
#define SAVE_H_DEFINED

#include "./common.h"

void save_manager(GameObject *G, int save_load);

// save
void save_Settings(GameSound *sound, GameWindow *window);
void save_Dev(GameDev *dev);

// load
void load_Settings(GameSound *sound, GameWindow *window);
void load_Dev(GameDev *dev);

#endif