#include "../headers/dev.h"

void displayFPS()
{
  printf("FPS");
}

void set_fullScreen(GameWindow *window)
{
  int fullscreen = SDL_SetWindowFullscreen(window->mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

  ///TODO: delete the second fullScreen method after tests
  // SDL_SetWindowSize(window->mainWindow, window->max_w, window->max_h);

  window->fullScreen = 1;
}
