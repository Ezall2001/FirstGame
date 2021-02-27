#ifndef SOUND_H_DEFINED
#define SOUND_H_DEFINED

#include "./common.h"

void sound_manager(GameObject *G);

// music
void play_Menu_Music(GameSound *sound);

// SFX
void play_waves_SFX(GameSound *sound);
void play_wind_SFX(GameSound *sound);
void play_click_SFX(GameSound *sound);
void play_bird_SFX(GameSound *sound);

#endif