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

    case SDLK_m:
    {
      if (input->ctrl == 1)
        window->mute = 1;
      break;
    }

    case SDLK_s:
    {
      if (input->ctrl == 1)
        window->menu_scene = 1;
      break;
    }

    case SDLK_o:
    {
      if (input->ctrl == 1)
        window->menu_scene = 2;
      break;
    }

    case SDLK_t:
    {
      if (input->ctrl == 1)
        window->menu_scene = 3;
      break;
    }

      ///TODO: update the coords of the music and SFX slider
    case SDLK_KP_PLUS:
    {
      // music
      if (window->music_volume >= 90)
        window->music_volume = 100;
      else
        window->music_volume += 10;

      // SFX
      if (window->SFX_volume >= 90)
        window->SFX_volume = 100;
      else
        window->SFX_volume += 10;

      break;
    }

    case SDLK_KP_MINUS:
    {
      // music
      if (window->music_volume <= 10)
        window->music_volume = 0;
      else
        window->music_volume -= 10;

      // SFX
      if (window->SFX_volume <= 100)
        window->SFX_volume = 0;
      else
        window->SFX_volume -= 10;

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

void mouse_Button_Collision(Button buttons[], int num_Button, GameInput *input)
{
  for (int i = 0; i < num_Button; i++)
  {
    int x1 = buttons[i].button_Coords.x;
    int x2 = x1 + buttons[i].button_Coords.w;
    int y1 = buttons[i].button_Coords.y;
    int y2 = y1 + buttons[i].button_Coords.h;

    if (input->mouse_x > x1 && input->mouse_x < x2 && input->mouse_y > y1 && input->mouse_y < y2)
    {
      buttons[i].hover = 1;
    }
    else
    {
      buttons[i].hover = 0;
      buttons[i].staged = 0;
    }
  }
}

void stage_Button(Button buttons[], int num_Button)
{
  for (int i = 0; i < num_Button; i++)
  {
    if (buttons[i].hover == 1)
      buttons[i].staged = 1;
  }
}

void click_Button(Button buttons[], int num_Button, GameWindow *window)
{
  for (int i = 0; i < num_Button; i++)
  {
    if (buttons[i].staged == 1)
    {
      if (strcmp(buttons[i].name, "Start") == 0)
        window->menu_scene = 1;
      else if (strcmp(buttons[i].name, "Settings") == 0)
        window->menu_scene = 2;
      else if (strcmp(buttons[i].name, "Tutorial") == 0)
        window->menu_scene = 3;
      else if (strcmp(buttons[i].name, "Quit") == 0)
        window->running = 0;
      ///TODO: popup to confirm exit
      else if (strcmp(buttons[i].name, "Mute") == 0)
        window->mute = (window->mute + 1) % 2;
      else if (strcmp(buttons[i].name, "Back") == 0)
        window->menu_scene = 0;
    }
  }
}

void unstage_Buttons(Button buttons[], int num_Button)
{
  for (int i = 0; i < num_Button; i++)
  {
    buttons[i].staged = 0;
  }
}