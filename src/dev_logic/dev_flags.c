#include "../headers/dev.h"

void set_fullScreen(char flag[], GameWindow *window)
{
  if (strcmp(flag, "full_screen") == 0)
  {
    int fullscreen = SDL_SetWindowFullscreen(window->mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

    ///TODO: delete the second fullScreen method after tests
    ///TODO: extract the x,y,w,h to the window struct
    // SDL_SetWindowSize(window->mainWindow, window->max_w, window->max_h);

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