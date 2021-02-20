#include "../headers/logic.h"
#include "../headers/dev.h"

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

void update_Menu_Scene0_Coords(Menu_Scene0_UI *ui, GameWindow *window)
{
  ///TODO: finish this
}

void mouse_Button_Collision(Button buttons[], int num_Button, GameInput *input)
{
  for (int i = 0; i < num_Button; i++)
  {
    int x1 = buttons[i].button_Coords.x;
    int x2 = x1 + buttons[i].button_Coords.w;
    int y1 = buttons[i].button_Coords.y;
    int y2 = y1 + buttons[i].button_Coords.h;

    buttons[i].hover = 0;

    if (input->mouse_x > x1 && input->mouse_x < x2)
    {
      if (input->mouse_y > y1 && input->mouse_y < y2)
      {
        buttons[i].hover = 1;
      }
    }
  }
}