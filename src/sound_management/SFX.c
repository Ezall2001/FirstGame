#include "../headers/sound.h"
#include "../headers/dev.h"

void play_bird_SFX(GameSound *sound)
{
    int playch1 = Mix_PlayChannel(-1, sound->bird_SFX, 0);
    if (playch1 == -1)
        lib_errorLog("Failed at opnening music File", Mix_GetError());
}
void play_click_SFX(GameSound *sound)
{
    int playch2 = Mix_PlayChannel(-1, sound->click_SFX, 0);
    if (playch2 == -1)
        lib_errorLog("Failed at opnening music File", Mix_GetError());
}
void play_wind_SFX(GameSound *sound)
{
    int playch3 = Mix_PlayChannel(-1, sound->wind_SFX, 0);
    if (playch3 == -1)
        lib_errorLog("Failed at opnening music File", Mix_GetError());
}
void play_waves_SFX(GameSound *sound)
{
    int playch4 = Mix_PlayChannel(-1, sound->waves_SFX, 0);
    if (playch4 == -1)
        lib_errorLog("Failed at opnening music File", Mix_GetError());
}
void SFX(GameSound *sound)
{

    play_bird_SFX(sound);
    play_click_SFX(sound);
    play_wind_SFX(sound);
    play_waves_SFX(sound);
}