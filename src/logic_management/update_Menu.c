#include "../headers/logic.h"
#include "../headers/dev.h"

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

void update_Menu_Scene0_Coords(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  // --- button's background ---
  ui->buttons_Background_Coords.w = 800 * window->win_width_ratio;
  ui->buttons_Background_Coords.h = 650 * window->win_width_ratio;
  ui->buttons_Background_Coords.x = window->w * 0.935 - ui->buttons_Background_Coords.w;
  ui->buttons_Background_Coords.y = window->h * 0.3;

  // --- main buttons ---
  ui->buttons_Margin = ui->buttons_Background_Coords.h * 0.1;

  for (int i = 0; i < 4; i++)
  {
    // buttons
    ui->scene_buttons[i].button_Coords.w = ui->buttons_Background_Coords.w * 0.7;
    ui->scene_buttons[i].button_Coords.h = (ui->buttons_Background_Coords.h - ui->buttons_Margin * 5) / 4;
    ui->scene_buttons[i].button_Coords.x = ui->buttons_Background_Coords.x + (ui->buttons_Background_Coords.w - ui->scene_buttons[i].button_Coords.w) / 2;
    ui->scene_buttons[i].button_Coords.y = ui->buttons_Background_Coords.y + ui->buttons_Margin * 0.85 + (ui->buttons_Margin + ui->scene_buttons[i].button_Coords.h) * i;

    // text
    int text_w = 0, text_h = 0;
    float text_w_ratio = 1;
    int num_letters = strlen(ui->scene_buttons[i].name);

    int mesure = TTF_SizeUTF8(common_ui->menu_Font, ui->scene_buttons[i].name, &text_w, &text_h);
    if (mesure != 0)
      lib_errorLog("failed at calculating the text mesures", TTF_GetError());

    text_w_ratio = (float)text_h / text_w;

    ui->scene_buttons[i].text_Coords.w = ui->scene_buttons[i].button_Coords.w * 0.42 * ((float)num_letters / 8);
    ui->scene_buttons[i].text_Coords.h = ui->scene_buttons[i].text_Coords.w * text_w_ratio;
    ui->scene_buttons[i].text_Coords.x = ui->scene_buttons[i].button_Coords.x + ((ui->scene_buttons[i].button_Coords.w - ui->scene_buttons[i].text_Coords.w) / 2);
    ui->scene_buttons[i].text_Coords.y = ui->scene_buttons[i].button_Coords.y + ((ui->scene_buttons[i].button_Coords.h - ui->scene_buttons[i].text_Coords.h * 1.1) / 2);
  }

  // --- shortcuts ---
  ui->scene_shortcuts[0].button_Coords.w = 67 * window->win_width_ratio;
  ui->scene_shortcuts[0].button_Coords.h = 56 * window->win_width_ratio;
  ui->scene_shortcuts[0].button_Coords.x = window->w * 0.98 - ui->scene_shortcuts[0].button_Coords.w;
  ui->scene_shortcuts[0].button_Coords.y = window->h * 0.98 - ui->scene_shortcuts[0].button_Coords.h;
}
