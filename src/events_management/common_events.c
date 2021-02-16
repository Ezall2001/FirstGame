#include "../headers/event.h"
#include "../headers/dev.h"

void window_events(SDL_Event *event, GameWindow *window)
{
  if (event->type == SDL_WINDOWEVENT)
  {
    switch (event->window.event)
    {
    case SDL_WINDOWEVENT_CLOSE:
    {
      window->running = 0;
      break;
    }
    case SDL_WINDOWEVENT_SIZE_CHANGED:
    {
      int w = 0, h = 0;
      SDL_GetWindowSize(window->mainWindow, &w, &h);
      window->w = w;
      window->h = h;
      break;
    }
    case SDL_WINDOWEVENT_MOVED:
    {
      int x = 0, y = 0;
      SDL_GetWindowPosition(window->mainWindow, &x, &y);
      window->x = x;
      window->y = y;
      break;
    }

    default:
      break;
    }
  }
}