#include "../headers/sound.h"
#include "../headers/dev.h"

void menu_music(GameSound *sound)
{

   int playmusic = Mix_PlayMusic(sound->title_music, -1);
   if (playmusic != 0)
      lib_errorLog("Failed at opnening Audio", Mix_GetError());
}