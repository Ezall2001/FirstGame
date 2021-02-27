#include "../headers/sound.h"
#include "../headers/dev.h"

void sound_manager(GameObject *G)
{
    if (G->window.game_scene == 0)
    {
        if (G->sound.mute == 1)
        {
            Mix_Volume(-1, 0);
            Mix_VolumeMusic(0);
        }
        else
        {
            Mix_Volume(-1, MIX_MAX_VOLUME * G->sound.SFX_volume * 0.01);
            Mix_VolumeMusic(MIX_MAX_VOLUME * G->sound.music_volume * 0.01);
        }

        if (!Mix_PlayingMusic())
            play_Menu_Music(&(G->sound));

        if (G->sound.button_click_play == 1)
        {
            play_click_SFX(&G->sound);
            G->sound.button_click_play = 0;
        }
    }
}