#include "../headers/logic.h"

void update_Window_Coords(GameWindow *window)
{
  int x = 0, y = 0, w = 0, h = 0;
  SDL_GetWindowPosition(window->mainWindow, &x, &y);
  SDL_GetWindowSize(window->mainWindow, &w, &h);

  if (h == window->h && w != window->w)
    h = w * (float)9 / 16;
  else if (w == window->w && h != window->h)
    w = h * (float)16 / 9;
  if (w != window->w || h != window->h)
    SDL_SetWindowSize(window->mainWindow, w, h);

  window->win_width_ratio = (float)w / window->default_w;
  window->x = x;
  window->y = y;
  window->w = w;
  window->h = h;
}
