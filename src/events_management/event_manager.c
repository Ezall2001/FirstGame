#include "../headers/event.h"

void event_manager(GameObject *G)
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {

    ///TODO: refactor this
    if (event.type == SDL_QUIT)
    {
      G->running = 0;
    }
  }
}
