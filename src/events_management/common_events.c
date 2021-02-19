#include "../headers/event.h"
#include "../headers/logic.h"
#include "../headers/dev.h"

void window_events(SDL_Event *event, GameObject *G)
{

  switch (event->window.event)
  {
  case SDL_WINDOWEVENT_CLOSE:
  {
    G->window.running = 0;
    break;
  }
  case SDL_WINDOWEVENT_SIZE_CHANGED:
  {
    update_Window_Coords(&(G->window));
    update_Menu_Coords(&(G->menuUI), &(G->window));
    break;
  }
  case SDL_WINDOWEVENT_MOVED:
  {
    update_Window_Coords(&(G->window));
    break;
  }

  default:
    break;
  }
}