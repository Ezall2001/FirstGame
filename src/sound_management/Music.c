#include "../headers/sound.h"
#include "../headers/dev.h"

void play_Menu_Music(GameSound *sound)
{

   int playmusic = Mix_PlayMusic(sound->menu_music, -1);
   if (playmusic != 0)
      lib_errorLog("Failed at opnening Audio", Mix_GetError());
}