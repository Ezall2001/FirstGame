#include "../headers/sound.h"
#include "../headers/dev.h"

void menu_music(GameSound *sound)
{

   int openmusic = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
   if (openmusic != 0)
      lib_errorLog("Failed at opnening Audio", Mix_GetError());

   Mix_Music *music = Mix_LoadMUS("./assets/music/menu_music.mp3");
   if (music == NULL)
      lib_errorLog("Failed at opnening music File", Mix_GetError());

   int playmusic = Mix_PlayMusic(music, -1);
   if (playmusic != 0)
      lib_errorLog("Failed at opnening Audio", Mix_GetError());
}