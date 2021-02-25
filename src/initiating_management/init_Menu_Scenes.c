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
  load_Texture_Img(&(ui->static_Button), "./assets/imgs/menu/static_yellow_button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->static_Blue_Button), "./assets/imgs/menu/static_blue_button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Button), "./assets/imgs/menu/hover_blue_button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->click_Button), "./assets/imgs/menu/click_button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->main_Background), "./assets/imgs/menu/menu_background.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->mute_Shortcut), "./assets/imgs/menu/mute.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Mute_Shortcut), "./assets/imgs/menu/hover_mute.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->unmute_Shortcut), "./assets/imgs/menu/unmute.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Unmute_Shortcut), "./assets/imgs/menu/hover_unmute.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->back_Shortcut), "./assets/imgs/menu/back.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Back_Shortcut), "./assets/imgs/menu/hover_back.png", &(window->mainRenderer));

  // --- shortcuts ---
  char shortcuts[2][10] = {"Mute", "Back"};
  for (int i = 0; i < 2; i++)
  {
    // name
    strcpy(ui->scene_shortcuts[i].name, shortcuts[i]);

    // text
    ui->scene_shortcuts[i].text = NULL;

    // state
    ui->scene_shortcuts[i].hover = 0;
    ui->scene_shortcuts[i].staged = 0;
  }
}

void init_Scene0_Menu(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  //  --- button's background ---
  load_Texture_Img(&(ui->buttons_Background), "./assets/imgs/menu/buttons_main_menu_background.png", &(window->mainRenderer));

  //  --- main buttons ---
  char options[4][10] = {"Start", "Settings", "Tutorial", "Quit"};

  for (int i = 0; i < 4; i++)
  {
    // name
    strcpy(ui->scene_buttons[i].name, options[i]);

    // text
    load_Texture_Text(&(ui->scene_buttons[i].text), &(common_ui->menu_Font), options[i], common_ui->text_Color, &(window->mainRenderer));

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
  // imgs
  load_Texture_Img(&(ui->settings_Backgournd), "./assets/imgs/menu/buttons_tutorial_settings_background.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->plus), "./assets/imgs/menu/+.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->minus), "./assets/imgs/menu/-.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Plus), "./assets/imgs/menu/hover_+.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Minus), "./assets/imgs/menu/hover_-.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->sound_Bar), "./assets/imgs/menu/volume_bar.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->sound_Scroller), "./assets/imgs/menu/volume_scroller.png", &(window->mainRenderer));

  // --- settings title ---
  // text
  load_Texture_Text(&(ui->settings_Title_Text), &(common_ui->menu_Font), "Settings", common_ui->text_Color, &(window->mainRenderer));

  // --- music row ---
  // music text
  load_Texture_Text(&(ui->music_Text), &(common_ui->menu_Font), "Music", common_ui->text_Color, &(window->mainRenderer));

  // music minus controller
  strcpy(ui->volume_Controllers[0].name, "Music_-");

  ui->volume_Controllers[0].text = NULL;

  ui->volume_Controllers[0].hover = 0;
  ui->volume_Controllers[0].staged = 0;

  // music volume scorller
  strcpy(ui->volume_Scorllers[0].name, "Music_Scroller");

  ui->volume_Scorllers[0].text = NULL;

  ui->volume_Scorllers[0].hover = 0;
  ui->volume_Scorllers[0].staged = 0;

  // music plus controller
  strcpy(ui->volume_Controllers[1].name, "Music_+");

  ui->volume_Controllers[1].text = NULL;

  ui->volume_Controllers[1].hover = 0;
  ui->volume_Controllers[1].staged = 0;

  // --- SFX row ---
  // SFX text
  load_Texture_Text(&(ui->SFX_Text), &(common_ui->menu_Font), "SFX", common_ui->text_Color, &(window->mainRenderer));

  // SFX minus controller
  strcpy(ui->volume_Controllers[2].name, "SFX_-");

  ui->volume_Controllers[2].text = NULL;

  ui->volume_Controllers[2].hover = 0;
  ui->volume_Controllers[2].staged = 0;

  //SFX volume scorller
  strcpy(ui->volume_Scorllers[1].name, "SFX_Scroller");

  ui->volume_Scorllers[1].text = NULL;

  ui->volume_Scorllers[1].hover = 0;
  ui->volume_Scorllers[1].staged = 0;

  // SFX plus controller
  strcpy(ui->volume_Controllers[3].name, "SFX_+");

  ui->volume_Controllers[3].text = NULL;

  ui->volume_Controllers[3].hover = 0;
  ui->volume_Controllers[3].staged = 0;

  // --- resolution row ---
  ///TODO: finish this
}

void init_Scene3_Menu(Menu_Scene3_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  // --- tutorial background ---
  // background
  load_Texture_Img(&(ui->tutorial_Backgournd), "./assets/imgs/menu/buttons_tutorial_settings_background.png", &(window->mainRenderer));

  // --- tutorial title ---
  load_Texture_Text(&(ui->tutorial_Title_Text), &(common_ui->menu_Font), "Tutorial", common_ui->text_Color, &(window->mainRenderer));
  ///TODO: finish this
}
