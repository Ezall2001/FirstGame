#include "../headers/event.h"

void event_manager(GameObject *G)
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    window_events(&event, &(G->window));
  }
}
