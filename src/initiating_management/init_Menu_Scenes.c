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
  load_Texture_Img(&(ui->static_Blue_Button), "./assets/imgs/menu/static_blue_button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Button), "./assets/imgs/menu/hover_button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->click_Button), "./assets/imgs/menu/click_button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->main_Background), "./assets/imgs/menu/menu_background.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->mute_Shortcut), "./assets/imgs/menu/mute.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Mute_Shortcut), "./assets/imgs/menu/hover_mute.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->unmute_Shortcut), "./assets/imgs/menu/unmute.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Unmute_Shortcut), "./assets/imgs/menu/hover_unmute.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->back_Shortcut), "./assets/imgs/menu/back.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Back_Shortcut), "./assets/imgs/menu/hover_back.png", &(window->mainRenderer));

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

  // --- shortcuts ---
  char shortcuts[2][10] = {"Mute", "Back"};
  ui->shortcuts_Margin = 40 * window->win_width_ratio;
  for (int i = 0; i < 2; i++)
  {
    // name
    strcpy(ui->scene_shortcuts[i].name, shortcuts[i]);

    // text
    ui->scene_shortcuts[i].text = NULL;

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

    // state
    ui->scene_shortcuts[i].hover = 0;
    ui->scene_shortcuts[i].staged = 0;
  }
}

void init_Scene0_Menu(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  //  --- button's background ---
  load_Texture_Img(&(ui->buttons_Background), "./assets/imgs/menu/buttons_main_menu_background.png", &(window->mainRenderer));
  ui->buttons_Background_Coords.w = 800 * window->win_width_ratio;
  ui->buttons_Background_Coords.h = 650 * window->win_width_ratio;
  ui->buttons_Background_Coords.x = window->w * 0.935 - ui->buttons_Background_Coords.w;
  ui->buttons_Background_Coords.y = window->h * 0.3;

  //  --- main buttons ---
  char options[4][10] = {"Start", "Settings", "Tutorial", "Quit"};
  ui->buttons_Margin = ui->buttons_Background_Coords.h * 0.1;

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
    ui->scene_buttons[i].button_Coords.y = ui->buttons_Background_Coords.y + ui->buttons_Margin * 0.85 + (ui->buttons_Margin + ui->scene_buttons[i].button_Coords.h) * i;

    // text coords
    int text_w = 0, text_h = 0;
    float text_w_ratio = 1;
    int num_letters = strlen(options[i]);

    int mesure = TTF_SizeUTF8(common_ui->menu_Font, options[i], &text_w, &text_h);
    if (mesure != 0)
      lib_errorLog("failed at calculating the text mesures", TTF_GetError());

    text_w_ratio = (float)text_h / text_w;

    ui->scene_buttons[i].text_Coords.w = ui->scene_buttons[i].button_Coords.w * 0.42 * ((float)num_letters / 8);
    ui->scene_buttons[i].text_Coords.h = ui->scene_buttons[i].text_Coords.w * text_w_ratio;
    ui->scene_buttons[i].text_Coords.x = ui->scene_buttons[i].button_Coords.x + ((ui->scene_buttons[i].button_Coords.w - ui->scene_buttons[i].text_Coords.w) / 2);
    ui->scene_buttons[i].text_Coords.y = ui->scene_buttons[i].button_Coords.y + ((ui->scene_buttons[i].button_Coords.h - ui->scene_buttons[i].text_Coords.h * 1.1) / 2);

    // state
    ui->scene_buttons[i].hover = 0;
    ui->scene_buttons[i].staged = 0;
  }
}

void init_Scene1_Menu(Menu_Scene1_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  ///TODO: finish this
}

void init_Scene2_Menu(Menu_Scene2_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  // --- settings background ---
  // background
  load_Texture_Img(&(ui->settings_Backgournd), "./assets/imgs/menu/buttons_tutorial_settings_background.png", &(window->mainRenderer));

  // coords
  ui->settings_Backgournd_Coords.w = 0.95 * window->w;
  ui->settings_Backgournd_Coords.h = 0.92 * window->h;
  ui->settings_Backgournd_Coords.x = (window->w - ui->settings_Backgournd_Coords.w) / 2;
  ui->settings_Backgournd_Coords.y = (window->h - ui->settings_Backgournd_Coords.h) / 2;

  // --- settings title ---
  // text
  load_Texture_Text(&(ui->settings_Title_Text), &(common_ui->menu_Font), "Settings", common_ui->text_Color, &(window->mainRenderer));

  // background coords
  ui->settings_Title_Coords.w = 450 * window->win_width_ratio;
  ui->settings_Title_Coords.h = 70 * window->win_width_ratio;
  ui->settings_Title_Coords.x = ui->settings_Backgournd_Coords.x + (ui->settings_Backgournd_Coords.w - ui->settings_Title_Coords.w) / 2;
  ui->settings_Title_Coords.y = ui->settings_Backgournd_Coords.y - (ui->settings_Title_Coords.h / 2);

  // text coords
  int text_w = 0, text_h = 0;
  float text_w_ratio = 1;
  int num_letters = strlen("Tutorial");

  int mesure = TTF_SizeUTF8(common_ui->menu_Font, "Tutorial", &text_w, &text_h);
  if (mesure != 0)
    lib_errorLog("failed at calculating the text mesures", TTF_GetError());

  text_w_ratio = (float)text_h / text_w;

  ui->settings_Title_Text_Coords.w = 0.3 * ui->settings_Title_Coords.w;
  ui->settings_Title_Text_Coords.h = ui->settings_Title_Text_Coords.w * text_w_ratio;
  ui->settings_Title_Text_Coords.x = ui->settings_Title_Coords.x + (ui->settings_Title_Coords.w - ui->settings_Title_Text_Coords.w) / 2;
  ui->settings_Title_Text_Coords.y = ui->settings_Title_Coords.y + (ui->settings_Title_Coords.h * 0.97 - ui->settings_Title_Text_Coords.h) / 2;
}

void init_Scene3_Menu(Menu_Scene3_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  // --- tutorial background ---
  // background
  load_Texture_Img(&(ui->tutorial_Backgournd), "./assets/imgs/menu/buttons_tutorial_settings_background.png", &(window->mainRenderer));

  // coords
  ui->tutorial_Backgournd_Coords.w = 0.95 * window->w;
  ui->tutorial_Backgournd_Coords.h = 0.92 * window->h;
  ui->tutorial_Backgournd_Coords.x = (window->w - ui->tutorial_Backgournd_Coords.w) / 2;
  ui->tutorial_Backgournd_Coords.y = (window->h - ui->tutorial_Backgournd_Coords.h) / 2;

  // --- tutorial title ---
  // text
  load_Texture_Text(&(ui->tutorial_Title_Text), &(common_ui->menu_Font), "Tutorial", common_ui->text_Color, &(window->mainRenderer));

  // background coords
  ui->tutorial_Title_Coords.w = 450 * window->win_width_ratio;
  ui->tutorial_Title_Coords.h = 70 * window->win_width_ratio;
  ui->tutorial_Title_Coords.x = ui->tutorial_Backgournd_Coords.x + (ui->tutorial_Backgournd_Coords.w - ui->tutorial_Title_Coords.w) / 2;
  ui->tutorial_Title_Coords.y = ui->tutorial_Backgournd_Coords.y - (ui->tutorial_Title_Coords.h / 2);

  // text coords
  int text_w = 0, text_h = 0;
  float text_w_ratio = 1;
  int num_letters = strlen("Tutorial");

  int mesure = TTF_SizeUTF8(common_ui->menu_Font, "Tutorial", &text_w, &text_h);
  if (mesure != 0)
    lib_errorLog("failed at calculating the text mesures", TTF_GetError());

  text_w_ratio = (float)text_h / text_w;

  ui->tutorial_Title_Text_Coords.w = 0.3 * ui->tutorial_Title_Coords.w;
  ui->tutorial_Title_Text_Coords.h = ui->tutorial_Title_Text_Coords.w * text_w_ratio;
  ui->tutorial_Title_Text_Coords.x = ui->tutorial_Title_Coords.x + (ui->tutorial_Title_Coords.w - ui->tutorial_Title_Text_Coords.w) / 2;
  ui->tutorial_Title_Text_Coords.y = ui->tutorial_Title_Coords.y + (ui->tutorial_Title_Coords.h * 0.97 - ui->tutorial_Title_Text_Coords.h) / 2;
  ///TODO: finish this
}
