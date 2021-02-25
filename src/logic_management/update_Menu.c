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

  // --- shortcuts ---
  ui->shortcuts_Margin = 40 * window->win_width_ratio;
  for (int i = 0; i < 2; i++)
  {
    // button coords
    ui->scene_shortcuts[i].button_Coords.w = 75 * window->win_width_ratio;
    ui->scene_shortcuts[i].button_Coords.h = 62 * window->win_width_ratio;
    ui->scene_shortcuts[i].button_Coords.x = window->w * 0.98 - ui->scene_shortcuts[i].button_Coords.w * (i + 1) - ui->shortcuts_Margin * i;
    ui->scene_shortcuts[i].button_Coords.y = window->h * 0.98 - ui->scene_shortcuts[i].button_Coords.h;

    // text coords
    ui->scene_shortcuts[i].text_Coords.x = 0;
    ui->scene_shortcuts[i].text_Coords.y = 0;
    ui->scene_shortcuts[i].text_Coords.w = 0;
    ui->scene_shortcuts[i].text_Coords.h = 0;
  }
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
    char options[4][10] = {"Start", "Settings", "Tutorial", "Quit"};

    float text_w_ratio = get_Text_W_ratio(common_ui, options[i]);
    int num_letters = strlen(ui->scene_buttons[i].name);

    ui->scene_buttons[i].text_Coords.w = ui->scene_buttons[i].button_Coords.w * 0.42 * ((float)num_letters / 8);
    ui->scene_buttons[i].text_Coords.h = ui->scene_buttons[i].text_Coords.w * text_w_ratio;
    ui->scene_buttons[i].text_Coords.x = ui->scene_buttons[i].button_Coords.x + ((ui->scene_buttons[i].button_Coords.w - ui->scene_buttons[i].text_Coords.w) / 2);
    ui->scene_buttons[i].text_Coords.y = ui->scene_buttons[i].button_Coords.y + ((ui->scene_buttons[i].button_Coords.h - ui->scene_buttons[i].text_Coords.h * 1.1) / 2);
  }
}

void update_Menu_Scene1_Coords(Menu_Scene1_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  ///TODO: finish this
}

void update_Menu_Scene2_Coords(Menu_Scene2_UI *ui, Menu_Common_UI *common_ui, GameWindow *window, GameSound *sound)
{
  // settings background
  ui->settings_Backgournd_Coords.w = 0.95 * window->w;
  ui->settings_Backgournd_Coords.h = 0.85 * window->h;
  ui->settings_Backgournd_Coords.x = (window->w - ui->settings_Backgournd_Coords.w) / 2;
  ui->settings_Backgournd_Coords.y = (window->h * 0.97 - ui->settings_Backgournd_Coords.h) / 2;

  // settings title background
  ui->settings_Title_Coords.w = 450 * window->win_width_ratio;
  ui->settings_Title_Coords.h = 70 * window->win_width_ratio;
  ui->settings_Title_Coords.x = ui->settings_Backgournd_Coords.x + (ui->settings_Backgournd_Coords.w - ui->settings_Title_Coords.w) / 2;
  ui->settings_Title_Coords.y = ui->settings_Backgournd_Coords.y - (ui->settings_Title_Coords.h / 2);

  // settings title text
  float text_w_ratio = get_Text_W_ratio(common_ui, "Music");

  ui->settings_Title_Text_Coords.w = 0.3 * ui->settings_Title_Coords.w;
  ui->settings_Title_Text_Coords.h = ui->settings_Title_Text_Coords.w * text_w_ratio;
  ui->settings_Title_Text_Coords.x = ui->settings_Title_Coords.x + (ui->settings_Title_Coords.w - ui->settings_Title_Text_Coords.w) / 2;
  ui->settings_Title_Text_Coords.y = ui->settings_Title_Coords.y + (ui->settings_Title_Coords.h * 0.97 - ui->settings_Title_Text_Coords.h) / 2;

  ui->row_Margin = 70 * window->win_width_ratio;
  ui->column_Margin = 70 * window->win_width_ratio;

  // --- music row ---
  // music title
  ui->music_Title_Coords.w = 300 * window->win_width_ratio;
  ui->music_Title_Coords.h = 70 * window->win_width_ratio;
  ui->music_Title_Coords.x = ui->settings_Backgournd_Coords.x + ui->column_Margin;
  ui->music_Title_Coords.y = ui->settings_Backgournd_Coords.y + ui->row_Margin * 2;

  // music text
  text_w_ratio = get_Text_W_ratio(common_ui, "Music");

  ui->music_Title_Text_Coords.w = ui->music_Title_Coords.w * 0.3;
  ui->music_Title_Text_Coords.h = ui->music_Title_Text_Coords.w * text_w_ratio;
  ui->music_Title_Text_Coords.x = ui->music_Title_Coords.x + (ui->music_Title_Coords.w - ui->music_Title_Text_Coords.w) / 2;
  ui->music_Title_Text_Coords.y = ui->music_Title_Coords.y + (ui->music_Title_Coords.h - ui->music_Title_Text_Coords.h) / 2;

  // music minus controller
  ui->volume_Controllers[0].button_Coords.w = 70 * window->win_width_ratio;
  ui->volume_Controllers[0].button_Coords.h = 62 * window->win_width_ratio;
  ui->volume_Controllers[0].button_Coords.x = ui->music_Title_Coords.x + ui->music_Title_Coords.w + ui->column_Margin * 2;
  ui->volume_Controllers[0].button_Coords.y = ui->music_Title_Coords.y + (ui->music_Title_Coords.h - ui->volume_Controllers[0].button_Coords.h) / 2;

  // music volume bar
  ui->music_Bar_Coords.w = 700 * window->win_width_ratio;
  ui->music_Bar_Coords.h = 20 * window->win_width_ratio;
  ui->music_Bar_Coords.x = ui->volume_Controllers[0].button_Coords.x + ui->volume_Controllers[0].button_Coords.w + ui->column_Margin;
  ui->music_Bar_Coords.y = ui->volume_Controllers[0].button_Coords.y + (ui->volume_Controllers[0].button_Coords.h - ui->music_Bar_Coords.h) / 2;

  // music volume scroller
  ui->volume_Scorllers[0].button_Coords.w = 20 * window->win_width_ratio;
  ui->volume_Scorllers[0].button_Coords.h = 70 * window->win_width_ratio;
  ui->volume_Scorllers[0].button_Coords.x = ui->music_Bar_Coords.x + ((float)ui->music_Bar_Coords.w / 100) * sound->music_volume - ui->volume_Scorllers[0].button_Coords.w / 2;
  ui->volume_Scorllers[0].button_Coords.y = ui->music_Bar_Coords.y + (ui->music_Bar_Coords.h - ui->volume_Scorllers[0].button_Coords.h) / 2;

  // music plus controller
  ui->volume_Controllers[1].button_Coords.w = 70 * window->win_width_ratio;
  ui->volume_Controllers[1].button_Coords.h = 62 * window->win_width_ratio;
  ui->volume_Controllers[1].button_Coords.x = ui->music_Bar_Coords.x + ui->music_Bar_Coords.w + ui->column_Margin * 1.1;
  ui->volume_Controllers[1].button_Coords.y = ui->music_Bar_Coords.y + (ui->music_Bar_Coords.h - ui->volume_Controllers[1].button_Coords.h) / 2;

  // --- SFX row ---
  // SFX title
  ui->SFX_Title_Coords.w = 300 * window->win_width_ratio;
  ui->SFX_Title_Coords.h = 70 * window->win_width_ratio;
  ui->SFX_Title_Coords.x = ui->settings_Backgournd_Coords.x + ui->column_Margin;
  ui->SFX_Title_Coords.y = ui->music_Title_Coords.y + ui->music_Title_Coords.h + ui->row_Margin;

  // SFX text
  text_w_ratio = get_Text_W_ratio(common_ui, "SFX");

  ui->SFX_Title_Text_Coords.w = ui->SFX_Title_Coords.w * 0.3;
  ui->SFX_Title_Text_Coords.h = ui->SFX_Title_Text_Coords.w * text_w_ratio;
  ui->SFX_Title_Text_Coords.x = ui->SFX_Title_Coords.x + (ui->SFX_Title_Coords.w - ui->SFX_Title_Text_Coords.w) / 2;
  ui->SFX_Title_Text_Coords.y = ui->SFX_Title_Coords.y + (ui->SFX_Title_Coords.h - ui->SFX_Title_Text_Coords.h) / 2;

  // SFX minus controller
  ui->volume_Controllers[2].button_Coords.w = 70 * window->win_width_ratio;
  ui->volume_Controllers[2].button_Coords.h = 62 * window->win_width_ratio;
  ui->volume_Controllers[2].button_Coords.x = ui->SFX_Title_Coords.x + ui->SFX_Title_Coords.w + ui->column_Margin * 2;
  ui->volume_Controllers[2].button_Coords.y = ui->SFX_Title_Coords.y + (ui->SFX_Title_Coords.h - ui->volume_Controllers[2].button_Coords.h) / 2;

  // SFX volume bar
  ui->SFX_Bar_Coords.w = 700 * window->win_width_ratio;
  ui->SFX_Bar_Coords.h = 20 * window->win_width_ratio;
  ui->SFX_Bar_Coords.x = ui->volume_Controllers[2].button_Coords.x + ui->volume_Controllers[2].button_Coords.w + ui->column_Margin;
  ui->SFX_Bar_Coords.y = ui->volume_Controllers[2].button_Coords.y + (ui->volume_Controllers[2].button_Coords.h - ui->SFX_Bar_Coords.h) / 2;

  //SFX volume scorller
  ui->volume_Scorllers[1].button_Coords.w = 20 * window->win_width_ratio;
  ui->volume_Scorllers[1].button_Coords.h = 70 * window->win_width_ratio;
  ui->volume_Scorllers[1].button_Coords.x = ui->SFX_Bar_Coords.x + ((float)ui->SFX_Bar_Coords.w / 100) * sound->SFX_volume - ui->volume_Scorllers[1].button_Coords.w / 2;
  ui->volume_Scorllers[1].button_Coords.y = ui->SFX_Bar_Coords.y + (ui->SFX_Bar_Coords.h - ui->volume_Scorllers[1].button_Coords.h) / 2;

  // SFX plus controller
  ui->volume_Controllers[3].button_Coords.w = 70 * window->win_width_ratio;
  ui->volume_Controllers[3].button_Coords.h = 62 * window->win_width_ratio;
  ui->volume_Controllers[3].button_Coords.x = ui->SFX_Bar_Coords.x + ui->SFX_Bar_Coords.w + ui->column_Margin * 1.1;
  ui->volume_Controllers[3].button_Coords.y = ui->SFX_Bar_Coords.y + (ui->SFX_Bar_Coords.h - ui->volume_Controllers[3].button_Coords.h) / 2;

  ///TODO: finish this
}

void update_Menu_Scene3_Coords(Menu_Scene3_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  // tutorial background
  ui->tutorial_Backgournd_Coords.w = 0.95 * window->w;
  ui->tutorial_Backgournd_Coords.h = 0.85 * window->h;
  ui->tutorial_Backgournd_Coords.x = (window->w - ui->tutorial_Backgournd_Coords.w) / 2;
  ui->tutorial_Backgournd_Coords.y = (window->h * 0.97 - ui->tutorial_Backgournd_Coords.h) / 2;

  // title background
  ui->tutorial_Title_Coords.w = 450 * window->win_width_ratio;
  ui->tutorial_Title_Coords.h = 70 * window->win_width_ratio;
  ui->tutorial_Title_Coords.x = ui->tutorial_Backgournd_Coords.x + (ui->tutorial_Backgournd_Coords.w - ui->tutorial_Title_Coords.w) / 2;
  ui->tutorial_Title_Coords.y = ui->tutorial_Backgournd_Coords.y - (ui->tutorial_Title_Coords.h / 2);

  // text coords
  float text_w_ratio = get_Text_W_ratio(common_ui, "Tutorial");

  ui->tutorial_Title_Text_Coords.w = 0.3 * ui->tutorial_Title_Coords.w;
  ui->tutorial_Title_Text_Coords.h = ui->tutorial_Title_Text_Coords.w * text_w_ratio;
  ui->tutorial_Title_Text_Coords.x = ui->tutorial_Title_Coords.x + (ui->tutorial_Title_Coords.w - ui->tutorial_Title_Text_Coords.w) / 2;
  ui->tutorial_Title_Text_Coords.y = ui->tutorial_Title_Coords.y + (ui->tutorial_Title_Coords.h * 0.97 - ui->tutorial_Title_Text_Coords.h) / 2;

  ///TODO: finish this
}