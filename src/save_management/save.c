#include "../headers/save.h"

void save_Settings(GameSound *sound, GameWindow *window)
{
  char *Save_Sound;
  FILE *file_Save_Sound = NULL;
  file_Save_Sound = fopen(Save_Sound, "w");
  if (file_Save_Sound != NULL)
    fprintf(file_Save_Sound, "volume du music = %d\n volume du SFX = %d \n etat du son =  %d \n", sound->music_volume, sound->SFX_volume, sound->mute);
  fclose(file_Save_Sound);
  char *Save_Display;
  FILE *file_Save_Display = NULL;
  file_Save_Display = fopen(Save_Display, "w");
  if (file_Save_Display != NULL)
    fprintf(file_Save_Display, " Dimensions = %d | %d | %d | %d\n", window->x, window->y, window->w, window->h);
  fprintf(file_Save_Display, " etat d'ecran = %d\n", window->fullScreen);
  fclose(file_Save_Display);
}

void save_Dev(GameDev *dev)
{
  char *Save_Dev;
  FILE *file_Save_Dev = NULL;
  file_Save_Dev = fopen(Save_Dev, "w");
  if (file_Save_Dev != NULL)
    fprintf(file_Save_Dev, "FPS = %d\n Outlines = %d \n Change_caracter =  %d \n Spawn_enemy = %d \n", dev->show_FPS, dev->show_outlines, dev->change_character, dev->spawn_enemy);
  fclose(file_Save_Dev);
}