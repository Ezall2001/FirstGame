#include "../headers/sound.h"
#include "../headers/dev.h"

void play_bird_SFX(GameSound *sound)
{
    int playch = Mix_PlayChannel(1, sound->bird_SFX, 0);
    if (playch == -1)
        lib_errorLog("Failed at opnening music File", Mix_GetError());
}
void play_click_SFX(GameSound *sound)
{
    int playch = Mix_PlayChannel(2, sound->click_SFX, 0);
    if (playch == -1)
        lib_errorLog("Failed at opnening music File", Mix_GetError());
}
void play_wind_SFX(GameSound *sound)
{
    int playch = Mix_PlayChannel(3, sound->wind_SFX, 0);
    if (playch == -1)
        lib_errorLog("Failed at opnening music File", Mix_GetError());
}
void play_waves_SFX(GameSound *sound)
{
    int playch = Mix_PlayChannel(4, sound->waves_SFX, 0);
    if (playch == -1)
        lib_errorLog("Failed at opnening music File", Mix_GetError());
}
