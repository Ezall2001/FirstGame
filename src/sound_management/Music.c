#include "../headers/sound.h"
#include "../headers/dev.h" 

int music()
{
   if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //ouverture du fichier audio
   printf("%s", Mix_GetError()) ; 
   Mix_Music *musique; //Création du pointeur de type Mix_Music qui va contenir notre musique 
   musique = Mix_LoadMUS("menu_music.mp3"); //Chargement de la musique
   Mix_PlayMusic(musique, -1); // Pour jouer infiniment la musique
   Mix_FreeMusic(musique); //Libération de la musique 
   Mix_CloseAudio(); //Fermeture du fichier audio 
   return 0 ;   
}