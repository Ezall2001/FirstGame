#include "../headers/logic.h"
#include "../headers/dev.h"

void shortcut_Input(GameInput *input, GameWindow *window)
{
  for (int i = 0; i < input->num_keys; i++)
  {
    switch (input->keys[i])
    {
    case SDLK_ESCAPE:
    {
      if (window->menu_scene == 0)
        ///TODO: make a popup to confirm exit
        window->running = 0;
      else
        window->menu_scene = 0;
      break;
    }

    case SDLK_f:
    {
      if (input->ctrl == 1)
      {
        if (window->fullScreen == 0)
        {
          int fullscreen = SDL_SetWindowFullscreen(window->mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
          if (fullscreen != 0)
            lib_errorLog("failed at setting the window to full screen", SDL_GetError());
          window->fullScreen = 1;
        }
        else if (window->fullScreen == 1)
        {
          int fullscreen = SDL_SetWindowFullscreen(window->mainWindow, 0);
          if (fullscreen != 0)
            lib_errorLog("failed at setting the window to full screen", SDL_GetError());

          SDL_SetWindowSize(window->mainWindow, window->max_w / 2, window->max_h / 2);
          window->fullScreen = 0;
        }
      }
      break;
    }
    default:
      break;
    }
  }
}
