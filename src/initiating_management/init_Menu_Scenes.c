#include "../headers/init.h"
#include "../headers/dev.h"

void init_Common_Menu(Menu_Common_UI *ui, GameWindow *window)
{
  // font and colors
  ui->menu_Font = NULL;
  ui->menu_Font = TTF_OpenFont("./assets/fonts/menu's font.ttf", 255);
  if (ui->menu_Font == NULL)
    lib_errorLog("failed at loading font", TTF_GetError());

  ui->title_Color.r = 247;
  ui->title_Color.g = 147;
  ui->title_Color.b = 30;
  ui->title_Color.a = 0;

  ui->text_Color.r = 255;
  ui->text_Color.g = 255;
  ui->text_Color.b = 255;
  ui->text_Color.a = 0;

  // text
  load_Texture_Text(&(ui->title_Text), &(ui->menu_Font), "Surrounded By Water", ui->title_Color, &(window->mainRenderer));

  // imgs
  ///TODO: finish this
  load_Texture_Img(&(ui->static_Button), "./assets/imgs/menu/static_yellow_button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->static_Blue_Button), "./assets/imgs/menu/static-blue-button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Button), "./assets/imgs/menu/hover-button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->click_Button), "./assets/imgs/menu/click_button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->main_Background), "./assets/imgs/menu/menu's-background.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->mute_Shortcut), "./assets/imgs/menu/mute_shortcut.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Mute_Shortcut), "./assets/imgs/menu/mute_shortcut.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->back_Shortcut), "./assets/imgs/menu/back_shortcut.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Back_Shortcut), "./assets/imgs/menu/back_shortcut.png", &(window->mainRenderer));

  // coords
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

void init_Scene0_Menu(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  //  --- button's background ---
  load_Texture_Img(&(ui->buttons_Background), "./assets/imgs/menu/buttons_main_menu_background.png", &(window->mainRenderer));
  ui->buttons_Background_Coords.w = 912 * window->win_width_ratio;
  ui->buttons_Background_Coords.h = 650 * window->win_width_ratio;
  ui->buttons_Background_Coords.x = window->w * 0.935 - ui->buttons_Background_Coords.w;
  ui->buttons_Background_Coords.y = window->h * 0.3;

  //  --- main buttons ---
  char options[4][10] = {"Start", "Settings", "Tutorial", "Quit"};
  ui->buttons_Margin = 30;

  for (int i = 0; i < 4; i++)
  {
    // name
    strcpy(ui->scene_buttons[i].name, options[i]);

    // text
    load_Texture_Text(&(ui->scene_buttons[i].text), &(common_ui->menu_Font), options[i], common_ui->text_Color, &(window->mainRenderer));

    // button coords
    ui->scene_buttons[i].button_Coords.w = ui->buttons_Background_Coords.w * 0.7;
    ui->scene_buttons[i].button_Coords.h = (ui->buttons_Background_Coords.h - ui->buttons_Margin * 5) / 4;
    ui->scene_buttons[i].button_Coords.x = ui->buttons_Background_Coords.x + (ui->buttons_Background_Coords.w - ui->scene_buttons[i].button_Coords.w) / 2;
    ui->scene_buttons[i].button_Coords.y = ui->buttons_Background_Coords.y + ui->buttons_Margin + (ui->buttons_Margin + ui->scene_buttons[i].button_Coords.h) * i;

    // text coords
    int text_w = 0, text_h = 0;
    float text_w_ratio = 1;

    int mesure = TTF_SizeUTF8(common_ui->menu_Font, options[i], &text_w, &text_h);
    if (mesure != 0)
      lib_errorLog("failed at calculating the text mesures", TTF_GetError());

    text_w_ratio = (float)text_h / text_w;

    ui->scene_buttons[i].text_Coords.w = ui->scene_buttons[i].button_Coords.w * 0.3;
    ui->scene_buttons[i].text_Coords.h = ui->scene_buttons[i].text_Coords.w * text_w_ratio;
    ui->scene_buttons[i].text_Coords.x = ui->scene_buttons[i].button_Coords.x + ((ui->scene_buttons[i].button_Coords.w - ui->scene_buttons[i].text_Coords.w) / 2);
    ui->scene_buttons[i].text_Coords.y = ui->scene_buttons[i].button_Coords.y + ((ui->scene_buttons[i].button_Coords.h - ui->scene_buttons[i].text_Coords.h) / 2);

    // state
    ui->scene_buttons[i].hover = 0;
    ui->scene_buttons[i].staged = 0;
  }

  char shortcuts[2][10] = {"Mute", "Back"};
  ui->shortcuts_Margin = 20;

  for (int i = 0; i < 2; i++)
  {
    // name
    strcpy(ui->scene_shortcuts[i].name, shortcuts[i]);

    // text
    ui->scene_shortcuts[i].text = NULL;

    // button coords
    ui->scene_shortcuts[i].button_Coords.w = 50 * window->win_width_ratio;
    ui->scene_shortcuts[i].button_Coords.h = 50 * window->win_width_ratio;
    ui->scene_shortcuts[i].button_Coords.x = window->w * 0.95 - ui->scene_shortcuts[i].button_Coords.w * (i + 1) - ui->shortcuts_Margin * i;
    ui->scene_shortcuts[i].button_Coords.y = window->h * 0.95 - ui->scene_shortcuts[i].button_Coords.h;

    // text coords
    ui->scene_shortcuts[i].text_Coords.x = 0;
    ui->scene_shortcuts[i].text_Coords.y = 0;
    ui->scene_shortcuts[i].text_Coords.w = 0;
    ui->scene_shortcuts[i].text_Coords.h = 0;

    // state
    ui->scene_shortcuts[i].hover = 0;
    ui->scene_shortcuts[i].staged = 0;
  }
}