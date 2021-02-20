#include "../headers/logic.h"
#include "../headers/dev.h"

void update_Window_Coords(GameWindow *window)
{
  int x = 0, y = 0, w = 0, h = 0;
  SDL_GetWindowPosition(window->mainWindow, &x, &y);
  SDL_GetWindowSize(window->mainWindow, &w, &h);

  if (h == window->h && w != window->w)
    h = w * (float)9 / 16;
  else if (w == window->w && h != window->h)
    w = h * (float)16 / 9;
  if (w != window->w || h != window->h)
    SDL_SetWindowSize(window->mainWindow, w, h);

  window->win_width_ratio = (float)w / window->default_w;
  window->x = x;
  window->y = y;
  window->w = w;
  window->h = h;
}

void update_Menu_Coords(MenuUI *ui, GameWindow *window)
{
  update_Menu_Common_Coords(&(ui->common_UI), window);
}

void update_Menu_Common_Coords(Menu_Common_UI *ui, GameWindow *window)
{
  // menu background coords
  ui->main_Background_Coords.x = 0;
  ui->main_Background_Coords.y = 0;
  ui->main_Background_Coords.w = window->w;
  ui->main_Background_Coords.h = window->h;

  // title coords
  ui->title_Coords.x = window->w * 0.5;
  ui->title_Coords.y = window->h * 0.1;
  ui->title_Coords.w = 700 * window->win_width_ratio;
  ui->title_Coords.h = 85 * window->win_width_ratio;
}

void mouse_Button_Collision(Menu_Scene0_UI *ui, GameWindow *window)
{
  for (int i = 0; i < 4; i++)
  {
    int x1 = ui->scene_buttons[i].button_Coords.x;
    int x2 = x1 + ui->scene_buttons[i].button_Coords.w;
    int y1 = ui->scene_buttons[i].button_Coords.y;
    int y2 = y1 + ui->scene_buttons[i].button_Coords.h;

    ui->scene_buttons[i].hover = 0;

    if (window->mouse_x > x1 && window->mouse_x < x2)
    {
      if (window->mouse_y > y1 && window->mouse_y < y2)
      {
        ui->scene_buttons[i].hover = 1;
      }
    }
  }
}