#include "../headers/sound.h"
#include "../headers/dev.h"

void sound_manager(GameObject *G)
{
    static int playing = 0;
    if (!playing)
    {
        mus();
        playing = 1;
    }
}