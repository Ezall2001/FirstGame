#include "../headers/sound.h"
#include "../headers/dev.h"

void sound_manager(GameObject *G)
{
    if (!G->sound.playing)
    {
        if (!G->sound.pause)
        {
            menu_music(&(G->sound));
        }
    }
    if (!G->sound.playing)
    {
        if (!G->sound.pause)
        {
            SFX(&(G->sound));
        }
    }
}