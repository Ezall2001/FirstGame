#include "../headers/sound.h"
#include "../headers/dev.h"
int SFX()
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2248);
    Mix_Chunk *birds = Mix_LoadWAV("birds_sfx.wav");
    Mix_Chunk *wind = Mix_LoadWAV("wind_sfx.wav");
    Mix_Chunk *woves = Mix_LoadWAV("woves_sfx.wav");
    Mix_Chunk *click = Mix_LoadWAV("click_sfx.wav");
    Mix_PlayChannel(-1, birds, 0);
    Mix_PlayChannel(-1, wind, 0);
    Mix_PlayChannel(-1, woves, 0);
    Mix_PlayChannel(-1, click, 0);

    Mix_FreeChunk(birds);
    Mix_FreeChunk(wind);
    Mix_FreeChunk(woves); 
    Mix_FreeChunk(click);

    Mix_CloseAudio();
}
