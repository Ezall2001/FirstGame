#include "../headers/event.h"
#include "../headers/dev.h"

void event_manager(GameObject *G)
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_WINDOWEVENT:
      window_events(&event, G);
      break;

    case SDL_MOUSEMOTION:
      mouse_motion_events(&event, G);
      break;

    default:
      break;
    }
  }
}
