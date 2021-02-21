#include <SDL2/SDL.h>    
#include <SDL2/SDL_mixer.h>  
#include <stdio.h>

int music()
{
   SDL_Init(SDL_INIT_AUDIO);
   if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
   Mix_Music *musique; //Création du pointeur de type Mix_Music
   musique = Mix_LoadMUS("menu_music.mp3"); //Chargement de la musique
   Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
   Mix_FreeMusic(musique); //Libération de la musique 
   Mix_CloseAudio(); //Fermeture de l'API
   SDL_Quit(); 
   return 0 ;
}