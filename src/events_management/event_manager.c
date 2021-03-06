#include "../headers/event.h"

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

    case SDL_KEYDOWN:
      keyboard_Input_events(&event, &(G->input));
      break;

    case SDL_MOUSEBUTTONUP:
    case SDL_MOUSEBUTTONDOWN:
      mouse_Input_events(&event, G);
      break;

    default:
      break;
    }
  }
  G->input.keyboard_state = SDL_GetKeyboardState(NULL);
}
