#include "../headers/logic.h"

void shortcut_Input(GameInput *input, GameSound *sound, GameWindow *window, GameUI *ui, GameDev *dev)
{
  static int select = -1;

  for (int i = 0; i < input->num_keys; i++)
  {
    switch (input->keys[i])
    {
    case SDLK_ESCAPE:
    {
      if (window->menu_scene == 0)
        window->popUp = 1;
      else
        window->menu_scene = 0;

      sound->button_click_play = 1;
      break;
    }

    case SDLK_m:
    {
      if (input->ctrl == 1)
      {
        if (sound->mute == 1)
          sound->mute = 0;
        else if (sound->mute == 0)
          sound->mute = 1;
      }

      break;
    }

    case SDLK_s:
    {
      if (input->ctrl == 1)
        window->menu_scene = 1;

      sound->button_click_play = 1;
      break;
    }

    case SDLK_o:
    {
      if (input->ctrl == 1)
        window->menu_scene = 2;

      sound->button_click_play = 1;
      break;
    }

    case SDLK_t:
    {
      if (input->ctrl == 1)
        window->menu_scene = 3;

      sound->button_click_play = 1;
      break;
    }

    case SDLK_KP_PLUS:
    {
      // music
      if (sound->music_volume >= 90)
        sound->music_volume = 100;
      else
        sound->music_volume += 10;

      // SFX
      if (sound->SFX_volume >= 90)
        sound->SFX_volume = 100;
      else
        sound->SFX_volume += 10;

      update_Scroller_Coords(ui->scene2_UI.volume_Scorllers, 2, sound, ui->scene2_UI.music_Bar_Coords);

      sound->button_click_play = 1;
      break;
    }

    case SDLK_KP_MINUS:
    {
      // music
      if (sound->music_volume <= 10)
        sound->music_volume = 0;
      else
        sound->music_volume -= 10;

      // SFX
      if (sound->SFX_volume <= 10)
        sound->SFX_volume = 0;
      else
        sound->SFX_volume -= 10;

      update_Scroller_Coords(ui->scene2_UI.volume_Scorllers, 2, sound, ui->scene2_UI.music_Bar_Coords);

      sound->button_click_play = 1;
      break;
    }

    case SDLK_DOWN:
    {
      if (window->menu_scene == 0)
      {
        if (select >= 0)
          ui->scene0_UI.scene_buttons[select].staged = 0;

        if (select >= 3)
          select = 0;
        else
          select++;

        ui->scene0_UI.scene_buttons[select].staged = 1;

        sound->button_click_play = 1;
      }
      break;
    }

    case SDLK_UP:
    {
      if (window->menu_scene == 0)
      {
        if (select >= 0)
          ui->scene0_UI.scene_buttons[select].staged = 0;

        if (select <= 0)
          select = 3;
        else
          select--;

        ui->scene0_UI.scene_buttons[select].staged = 1;

        sound->button_click_play = 1;
      }

      break;
    }

    case SDLK_RETURN:
    case SDLK_KP_ENTER:
    {
      if (window->menu_scene == 0)
      {
        click_Button(ui->scene0_UI.scene_buttons, 4, window, sound, dev, ui);
        select = -1;

        sound->button_click_play = 1;
      }
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

          ui->scene2_UI.resolution_Controllers[0].selected = 1;
          ui->scene2_UI.resolution_Controllers[1].selected = 0;
          ui->scene2_UI.resolution_Controllers[2].selected = 0;
        }
        else if (window->fullScreen == 1)
        {
          int fullscreen = SDL_SetWindowFullscreen(window->mainWindow, 0);
          if (fullscreen != 0)
            lib_errorLog("failed at setting the window to full screen", SDL_GetError());

          SDL_SetWindowSize(window->mainWindow, window->max_w / 2, window->max_h / 2);
          window->fullScreen = 0;

          for (int i = 0; i < 3; i++)
            ui->scene2_UI.resolution_Controllers[i].selected = 0;
        }

        sound->button_click_play = 1;
      }
      break;
    }
    default:
      break;
    }
  }
}

void mouse_Button_Collision(Button buttons[], int num_Button, GameInput *input, GameSound *sound)
{
  for (int i = 0; i < num_Button; i++)
  {
    int x1 = buttons[i].button_Coords.x;
    int x2 = x1 + buttons[i].button_Coords.w;
    int y1 = buttons[i].button_Coords.y;
    int y2 = y1 + buttons[i].button_Coords.h;

    if (input->mouse_x > x1 && input->mouse_x < x2 && input->mouse_y > y1 && input->mouse_y < y2)
    {
      if (buttons[i].selected != 1)
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

void drag_Volume(Button buttons[], int num_Button, GameInput *input, GameSound *sound, SDL_Rect bar)
{
  for (int i = 0; i < num_Button; i++)
  {
    if (buttons[i].staged == 1)
    {
      if (strcmp(buttons[i].name, "Music_Scroller") == 0)
      {
        if (input->mouse_x <= bar.x)
          sound->music_volume = 0;
        else if (input->mouse_x >= bar.x + bar.w)
          sound->music_volume = 100;
        else
          sound->music_volume = ((float)100 / bar.w) * (input->mouse_x - bar.x);
      }
      else if (strcmp(buttons[i].name, "SFX_Scroller") == 0)
      {
        if (input->mouse_x <= bar.x)
          sound->SFX_volume = 0;
        else if (input->mouse_x >= bar.x + bar.w)
          sound->SFX_volume = 100;
        else
          sound->SFX_volume = ((float)100 / bar.w) * (input->mouse_x - bar.x);
      }
    }
  }
  update_Scroller_Coords(buttons, 2, sound, bar);
}

void update_Scroller_Coords(Button buttons[], int num_Button, GameSound *sound, SDL_Rect bar)
{
  for (int i = 0; i < num_Button; i++)
  {
    if (strcmp(buttons[i].name, "Music_Scroller") == 0)
      buttons[i].button_Coords.x = bar.x + ((float)bar.w / 100) * sound->music_volume - buttons[i].button_Coords.w / 2;

    else if (strcmp(buttons[i].name, "SFX_Scroller") == 0)
      buttons[i].button_Coords.x = bar.x + ((float)bar.w / 100) * sound->SFX_volume - buttons[i].button_Coords.w / 2;
  }
}

void click_Button(Button buttons[], int num_Button, GameWindow *window, GameSound *sound, GameDev *dev, GameUI *ui)
{
  for (int i = 0; i < num_Button; i++)
  {
    if (buttons[i].staged == 1)
    {
      buttons[i].staged = 0;

      if (strcmp(buttons[i].name, "Start") == 0)
        window->menu_scene = 1;

      else if (strcmp(buttons[i].name, "Settings") == 0)
        window->menu_scene = 2;

      else if (strcmp(buttons[i].name, "Tutorial") == 0)
        window->menu_scene = 3;

      else if (strcmp(buttons[i].name, "Quit") == 0)
      {
        window->popUp = 1;
        buttons[i].hover = 0;
      }

      else if (strcmp(buttons[i].name, "Quit_Yes") == 0)
        window->running = 0;

      else if (strcmp(buttons[i].name, "Quit_No") == 0)
        window->popUp = 0;

      else if (strcmp(buttons[i].name, "Mute") == 0)
        sound->mute = (sound->mute + 1) % 2;

      else if (strcmp(buttons[i].name, "Back") == 0)
        window->menu_scene = 0;

      else if (strcmp(buttons[i].name, "Music_-") == 0)
      {
        if (sound->music_volume < 5)
          sound->music_volume = 0;
        else
          sound->music_volume -= 5;

        update_Scroller_Coords(ui->scene2_UI.volume_Scorllers, 2, sound, ui->scene2_UI.music_Bar_Coords);
      }

      else if (strcmp(buttons[i].name, "Music_+") == 0)
      {
        if (sound->music_volume > 95)
          sound->music_volume = 100;
        else
          sound->music_volume += 5;

        update_Scroller_Coords(ui->scene2_UI.volume_Scorllers, 2, sound, ui->scene2_UI.music_Bar_Coords);
      }

      else if (strcmp(buttons[i].name, "SFX_-") == 0)
      {
        if (sound->SFX_volume < 5)
          sound->SFX_volume = 0;
        else
          sound->SFX_volume -= 5;

        update_Scroller_Coords(ui->scene2_UI.volume_Scorllers, 2, sound, ui->scene2_UI.music_Bar_Coords);
      }

      else if (strcmp(buttons[i].name, "SFX_+") == 0)
      {
        if (sound->SFX_volume > 95)
          sound->SFX_volume = 100;
        else
          sound->SFX_volume += 5;

        update_Scroller_Coords(ui->scene2_UI.volume_Scorllers, 2, sound, ui->scene2_UI.music_Bar_Coords);
      }

      else if (strcmp(buttons[i].name, "FullScreen") == 0)
      {
        if (buttons[i].selected != 1)
        {
          int fullscreen = SDL_SetWindowFullscreen(window->mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
          if (fullscreen != 0)
            lib_errorLog("failed at setting the window to full screen", SDL_GetError());
          window->fullScreen = 1;

          for (int j = 0; j < num_Button; j++)
          {
            buttons[j].selected = 0;
          }

          buttons[i].selected = 1;
        }
      }

      else if (strcmp(buttons[i].name, "1920 x 1080") == 0)
      {
        if (buttons[i].selected != 1)
        {
          int fullscreen = SDL_SetWindowFullscreen(window->mainWindow, 0);
          if (fullscreen != 0)
            lib_errorLog("failed at setting the window to full screen", SDL_GetError());

          SDL_SetWindowSize(window->mainWindow, 1920, 1080);
          window->fullScreen = 0;

          for (int j = 0; j < num_Button; j++)
          {
            buttons[j].selected = 0;
          }

          buttons[i].selected = 1;
        }
      }

      else if (strcmp(buttons[i].name, "1280 x 720") == 0)
      {
        if (buttons[i].selected != 1)
        {
          int fullscreen = SDL_SetWindowFullscreen(window->mainWindow, 0);
          if (fullscreen != 0)
            lib_errorLog("failed at setting the window to full screen", SDL_GetError());

          SDL_SetWindowSize(window->mainWindow, 1280, 720);
          window->fullScreen = 0;

          for (int j = 0; j < num_Button; j++)
          {
            buttons[j].selected = 0;
          }

          buttons[i].selected = 1;
        }
      }

      else if (strcmp(buttons[i].name, "uncapped") == 0)
      {
        if (buttons[i].selected != 1)
        {

          dev->FPS_cap = 1000;
          for (int j = 0; j < num_Button; j++)
          {
            buttons[j].selected = 0;
          }

          buttons[i].selected = 1;
        }
      }

      else if (strcmp(buttons[i].name, "144 FPS") == 0)
      {
        if (buttons[i].selected != 1)
        {

          dev->FPS_cap = 144;
          for (int j = 0; j < num_Button; j++)
          {
            buttons[j].selected = 0;
          }

          buttons[i].selected = 1;
        }
      }

      else if (strcmp(buttons[i].name, "60 FPS") == 0)
      {
        if (buttons[i].selected != 1)
        {

          dev->FPS_cap = 60;
          for (int j = 0; j < num_Button; j++)
          {
            buttons[j].selected = 0;
          }

          buttons[i].selected = 1;
        }
      }

      sound->button_click_play = 1;
    }
  }
}
