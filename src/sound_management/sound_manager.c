#include "../headers/sound.h"
#include "../headers/dev.h"

void sound_manager(GameObject *G)
{
    if (G->window.game_scene == 0)
    {

        // volume control
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

        // music
        if (!Mix_PlayingMusic())
            play_Menu_Music(&(G->sound));

        // click SFX
        if (G->sound.button_click_play == 1)
        {
            play_click_SFX(&G->sound);
            G->sound.button_click_play = 0;
        }

        // waves SFX
        play_waves_SFX(&(G->sound), &(G->window.r));

        // bird SFX
        if (G->sound.bird_play == 1)
        {
            if (!Mix_Playing(1))
            {
                play_bird_SFX(&(G->sound));
            }
        }
        else if (G->sound.bird_play == 0)
        {
            if (Mix_Playing(1))
            {
                Mix_FadeOutChannel(1, 1500);
            }
        }
    }
}