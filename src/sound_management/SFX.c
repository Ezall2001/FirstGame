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

void play_waves_SFX(GameSound *sound, MTRand *r)
{

    static int counting = 0;
    static Uint32 startCount = 0;
    static Uint16 delay = 0;
    static int wave_pause = 0;

    if (wave_pause == 0)
    {
        if (counting == 1)
        {
            if (SDL_GetTicks() - startCount > delay)
            {
                counting = 0;
                delay = 0;
                wave_pause = 1;
                Mix_FadeOutChannel(4, 3000);
            }
        }
        else
        {
            int playch = Mix_FadeInChannel(4, sound->waves_SFX, -1, 3000);
            if (playch == -1)
                lib_errorLog("Failed at opnening music File", Mix_GetError());

            counting = 1;
            startCount = SDL_GetTicks();
            delay = get_Random_Delay(r, 12000, 17000);
        }
    }
    else if (wave_pause == 1)
    {
        if (counting == 1)
        {
            if (SDL_GetTicks() - startCount > delay)
            {
                counting = 0;
                delay = 0;
                wave_pause = 0;
            }
        }
        else
        {
            counting = 1;
            startCount = SDL_GetTicks();
            delay = get_Random_Delay(r, 3000, 8000);
        }
    }
}
