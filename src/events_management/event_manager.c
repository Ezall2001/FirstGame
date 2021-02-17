#include "../headers/event.h"
#include "../headers/dev.h"

void event_manager(GameObject *G)
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_WINDOWEVENT)
    {
      window_events(&event, G);
    }
  }
}
