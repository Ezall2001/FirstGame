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
  strncpy(extVal, flag + 10, 4);

  if (strcmp(extFlag, "limit_fps") == 0)
    dev->FPS_cap = atoi(extVal);
}

void set_mute(char flag[], GameSound *sound)
{
  if (strcmp(flag, "mute") == 0)
    sound->mute = 1;
}

void set_full_dev(char flag[], GameDev *dev)
{
  if (strcmp(flag, "full_dev") == 0)
  {
    dev->show_boxes = 1;
    dev->change_character = 1;
    dev->spawn_enemy = 1;
  }
}

void set_boxes(char flag[], GameDev *dev)
{
  if (strcmp(flag, "boxes") == 0)
    dev->show_boxes = 1;
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