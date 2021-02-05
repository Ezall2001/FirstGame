#include "../headers/init.h"
#include "../headers/dev.h"

/// TODO: change the name of the wingdow
void init_gameWindow(GameWindow *window)
{
  window->mainWindow = NULL;
  window->mainWindow = SDL_CreateWindow("FirstGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
  if (window->mainWindow == NULL)
    lib_errorLog("failed at creating a window", SDL_GetError());

  ///TODO: delete this if you don't need it
  SDL_Rect max_Window;
  SDL_GetDisplayBounds(0, &max_Window);
  window->max_w = max_Window.w;
  window->max_h = max_Window.h;

  window->fullScreen = 0;
}