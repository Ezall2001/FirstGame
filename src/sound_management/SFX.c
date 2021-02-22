#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
int main(int argc, char **argv[])
{
    SDL_Event event;
    SDL_Init(SDL_INIT_AUDIO);                          //initialitation audio systeme
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048); // initialisation sdl mixer
                                                       //load audio files
    Mix_Chunk *birdseffect = Mix_LoadWAV("birds_sfx.wav");

    Mix_Chunk *windeffect = Mix_LoadWAV("wind_sfx.wav");
    Mix_Chunk *woveseffect = Mix_LoadWAV("woves_sfx.wav");
    Mix_Chunk *clickeffect = Mix_LoadWAV("click_sfx.wav");
    bool running = true;
    while (SDL_PollEvent(&event))
    {

        if (event.type == SDL_Quit)
        {
            running = false;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_F1) // cliquer sur f1;
                                                 //start effect sound music
                Mix_PlayChannel(-1, birdseffect, 0);
            Mix_PlayChannel(-1, windeffect, 0);
            Mix_PlayChannel(-1, woveseffect, 0);
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {

            if (event.button.button == SDL_BUTTON_RIGHT)
            { //star mouseeffect sound
                Mix_PlayChannel(-1, clickeffect, 0);
            }
        }
    }
    //liberation du memoire
    Mix_FreeChunk(birdseffect);
    Mix_FreeChunk(windeffect);
    Mix_FreeChunk(woveseffect);
    Mix_FreeChunk(clickeffect);

    Mix_CloseAudio();
    SDL_Quit();
}