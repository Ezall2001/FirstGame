#include "../headers/dev.h"

void set_fullScreen(char flag[], GameWindow *window)
{
  if (strcmp(flag, "fullscreen") == 0)
  {
    int fullscreen = SDL_SetWindowFullscreen(window->mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (fullscreen != 0)
      lib_errorLog("failed at setting the window to full screen", SDL_GetError());
    window->fullScreen = 1;
  }
}

void set_FPS(char flag[], GameDev *dev)
{
  if (strcmp(flag, "fps") == 0)
    dev->show_FPS = 1;
}

void set_FPS_cap(char flag[], GameDev *dev)
{
  char extFlag[10];
  char extVal[10];

  strncpy(extFlag, flag, 9);
  extFlag[9] = '\0';

  if (strcmp(extFlag, "limit_fps") == 0)
  {
    strncpy(extVal, flag + 10, 4);
    dev->FPS_cap = atoi(extVal);
  }
}

void set_mute(char flag[], GameSound *sound)
{
  if (strcmp(flag, "mute") == 0)
    sound->mute = 1;
}

void set_sprites(char flag[])
{
  char extFlag[10];
  char extVal[50];

  strncpy(extFlag, flag, 6);
  extFlag[6] = '\0';

  if (strcmp(extFlag, "sprite") == 0)
  {
    strncpy(extVal, flag + 7, strlen(flag) - 7);
    extVal[strlen(flag) - 7] = '\0';

    DIR *d = opendir(extVal);
    if (d == NULL)
      lib_errorLog("failed at opening dir", NULL);
    else
    {
      int renamed = 0;
      int i = 0;
      char i_string[3] = "\0";
      struct dirent *dir;

      while ((dir = readdir(d)) != NULL)
      {
        if (dir->d_type != DT_DIR)
        {
          char file[80] = "";
          char renameFile[80] = "";

          strcat(file, extVal);
          strcat(file, "/\0");
          strcat(file, dir->d_name);

          itoa(i, i_string, 10);
          strcat(renameFile, extVal);
          strcat(renameFile, "/\0");
          strcat(renameFile, i_string);
          strcat(renameFile, ".png\0");

          printf("file: %s\n", file);
          printf("renameFile: %s\n", renameFile);

          renamed = rename(file, renameFile);
          if (renamed != 0)
            lib_errorLog("failed at renaming file", NULL);

          i++;
        }
      }
    }

    closedir(d);
  }
}

void set_full_dev(char flag[], GameDev *dev)
{
  if (strcmp(flag, "full_dev") == 0)
  {
    dev->show_boxes = 1;
    dev->show_ranges = 1;
    dev->show_directions = 1;
    dev->change_character = 1;
    dev->spawn_enemy = 1;
  }
}

void set_boxes(char flag[], GameDev *dev)
{
  if (strcmp(flag, "boxes") == 0)
    dev->show_boxes = 1;
}

void set_ranges(char flag[], GameDev *dev)
{
  if (strcmp(flag, "ranges") == 0)
  {
    dev->show_ranges = 1;
  }
}

void set_directions(char flag[], GameDev *dev)
{
  if (strcmp(flag, "directions") == 0)
  {
    dev->show_directions = 1;
  }
}

void set_spawn(char flag[], GameDev *dev)
{
  if (strcmp(flag, "spawn") == 0)
  {
    dev->change_character = 1;
    dev->spawn_enemy = 1;
  }
}

void set_character(char flag[], GameDev *dev)
{
  if (strcmp(flag, "character") == 0)
    dev->change_character = 1;
}

void set_enemy(char flag[], GameDev *dev)
{
  if (strcmp(flag, "enemy") == 0)
    dev->spawn_enemy = 1;
}