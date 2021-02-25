#include "../headers/sound.h"
#include "../headers/dev.h"

void sound_manager(GameObject *G)
{
    if (G->window.game_scene == 0)
    {
        if (G->sound.mute == 1)
        {
        }
        if (G->sound.menu_playing == 0)
        {
            menu_music(&(G->sound));
            G->sound.menu_playing = 1;
        }
        else if (G->sound.pause == 1)
        {
        }
    }
}