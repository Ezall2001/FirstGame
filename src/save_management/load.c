#include "../headers/save.h"

void load_Settings(GameSound *sound, GameWindow *window)
{
  char *Load_Sound;
  FILE *file_Save_Sound = NULL;
  file_Save_Sound = fopen(Load_Sound, "r");
  if (file_Save_Sound != NULL)
    fscanf(file_Save_Sound, "%d %d %d \n", sound->music_volume, sound->SFX_volume, sound->mute);
  fclose(file_Save_Sound);
  char *Load_Display;
  FILE *file_Save_Display = NULL;
  file_Save_Display = fopen(Load_Display, "r");
  if (file_Save_Display != NULL)
    fscanf(file_Save_Display, "  %d %d %d %d\n", window->x, window->y, window->w, window->h);
  fscanf(file_Save_Display, "%d\n", window->fullScreen);
  fclose(file_Save_Display);
}

void load_Dev(GameDev *dev)
{
  char *Load_Dev;
  FILE *file_Save_Dev = NULL;
  file_Save_Dev = fopen(Load_Dev, "r");
  if (file_Save_Dev != NULL)
    fscanf(file_Save_Dev, "%d %d %d  %d \n", dev->show_FPS, dev->show_outlines, dev->change_character, dev->spawn_enemy);
  fclose(file_Save_Dev);
}
