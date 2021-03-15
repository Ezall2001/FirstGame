#include "../headers/init.h"

void init_Common_Menu(Menu_Common_UI *ui, GameWindow *window)
{
  // font and colors
  ui->menu_Font = NULL;
  ui->menu_Font = TTF_OpenFont("./assets/fonts/menu's font.ttf", 255);
  if (ui->menu_Font == NULL)
    lib_errorLog("failed at loading font", TTF_GetError());

  ui->text_Color = set_color(255, 255, 255, 255);

  // imgs
  ui->static_Button = NULL;
  ui->static_Red_Button = NULL;
  ui->static_Blue_Button = NULL;
  ui->hover_Button = NULL;
  ui->click_Button = NULL;
  ui->main_Background = NULL;
  ui->mute_Shortcut = NULL;
  ui->hover_Mute_Shortcut = NULL;
  ui->unmute_Shortcut = NULL;
  ui->hover_Unmute_Shortcut = NULL;
  ui->back_Shortcut = NULL;
  ui->hover_Back_Shortcut = NULL;

  load_Texture_Img(&(ui->static_Button), "./assets/imgs/menu/static_yellow_button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->static_Red_Button), "./assets/imgs/menu/static_red_button.png", &(window->mainRenderer));
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

  // --- animation ---
  // sprite
  load_Sprite(ui->bird1, 9, "./assets/sprites/menu/bird1/", &(window->mainRenderer));
  load_Sprite(ui->bird2, 9, "./assets/sprites/menu/bird2/", &(window->mainRenderer));
  load_Sprite(ui->bird3, 9, "./assets/sprites/menu/bird3/", &(window->mainRenderer));
  load_Sprite(ui->wind, 29, "./assets/sprites/menu/wind/", &(window->mainRenderer));

  // states
  ui->bird_speed = 0;
  ui->wind_speed = 0;
  ui->bird_animation_play = 0;
  ui->wind_animation_play = 0;
}

void init_Scene0_Menu(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  //  --- button's background ---
  ui->buttons_Background = NULL;
  load_Texture_Img(&(ui->buttons_Background), "./assets/imgs/menu/buttons_main_menu_background.png", &(window->mainRenderer));

  //  --- main buttons ---
  char options[4][10] = {"Start", "Settings", "Tutorial", "Quit"};
  char icons[4][20] = {"play_icon.png", "settings_icon.png", "tutorial_icon.png", "quit_icon.png"};

  for (int i = 0; i < 4; i++)
  {
    // name
    strcpy(ui->scene_buttons[i].name, options[i]);

    // text
    ui->scene_buttons[i].text = NULL;
    load_Texture_Text(&(ui->scene_buttons[i].text), &(common_ui->menu_Font), options[i], common_ui->text_Color, &(window->mainRenderer));

    // button's icons
    char base_icon_path[50] = "./assets/icons/menu/";
    strcat(base_icon_path, icons[i]);

    ui->button_Icons[i] = NULL;
    load_Texture_Img(&(ui->button_Icons[i]), base_icon_path, &(window->mainRenderer));

    // state
    ui->scene_buttons[i].hover = 0;
    ui->scene_buttons[i].staged = 0;
  }
}

void init_Scene1_Menu(Menu_Scene1_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  ///TODO: init scene1
}

void init_Scene2_Menu(Menu_Scene2_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  // imgs
  ui->settings_Backgournd = NULL;
  ui->plus = NULL;
  ui->minus = NULL;
  ui->hover_Plus = NULL;
  ui->hover_Minus = NULL;
  ui->sound_Bar = NULL;
  ui->sound_Scroller = NULL;

  load_Texture_Img(&(ui->settings_Backgournd), "./assets/imgs/menu/buttons_tutorial_settings_background.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->plus), "./assets/imgs/menu/+.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->minus), "./assets/imgs/menu/-.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Plus), "./assets/imgs/menu/hover_+.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Minus), "./assets/imgs/menu/hover_-.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->sound_Bar), "./assets/imgs/menu/volume_bar.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->sound_Scroller), "./assets/imgs/menu/volume_scroller.png", &(window->mainRenderer));

  // --- settings title ---
  // text
  ui->settings_Title_Text = NULL;
  load_Texture_Text(&(ui->settings_Title_Text), &(common_ui->menu_Font), "Settings", common_ui->text_Color, &(window->mainRenderer));

  // --- sound rows ---
  // titles
  ui->music_Text = NULL;
  ui->SFX_Text = NULL;
  load_Texture_Text(&(ui->music_Text), &(common_ui->menu_Font), "Music", common_ui->text_Color, &(window->mainRenderer));
  load_Texture_Text(&(ui->SFX_Text), &(common_ui->menu_Font), "SFX", common_ui->text_Color, &(window->mainRenderer));

  // scrollers
  char volume_scrollers[2][20] = {"Music_Scroller", "SFX_Scroller"};
  for (int i = 0; i < 2; i++)
  {
    strcpy(ui->volume_Scorllers[i].name, volume_scrollers[i]);

    ui->volume_Scorllers[i].text = NULL;
    ui->volume_Scorllers[i].hover = 0;
    ui->volume_Scorllers[i].staged = 0;
    ui->volume_Scorllers[i].selected = 0;
  }

  // controllers
  char volume_controllers[4][20] = {"Music_-", "Music_+", "SFX_-", "SFX_+"};
  for (int i = 0; i < 4; i++)
  {
    strcpy(ui->volume_Controllers[i].name, volume_controllers[i]);
    ui->volume_Controllers[i].text = NULL;

    ui->volume_Controllers[i].hover = 0;
    ui->volume_Controllers[i].staged = 0;
    ui->volume_Controllers[i].selected = 0;
  }

  // --- resolution row ---
  char resolutions[4][20] = {"FullScreen", "1920 x 1080", "1280 x 720"};
  for (int i = 0; i < 3; i++)
  {
    strcpy(ui->resolution_Controllers[i].name, resolutions[i]);

    ui->resolution_Controllers[i].text = NULL;
    load_Texture_Text(&(ui->resolution_Controllers[i].text), &(common_ui->menu_Font), resolutions[i], common_ui->text_Color, &(window->mainRenderer));

    ui->resolution_Controllers[i].staged = 0;
    ui->resolution_Controllers[i].selected = 0;
    ui->resolution_Controllers[i].hover = 0;
  }
  ui->resolution_Controllers[2].selected = 1;

  // --- FPS row ---
  char FPS[4][20] = {"uncapped", "144 FPS", "60 FPS"};
  for (int i = 0; i < 3; i++)
  {
    strcpy(ui->fps_Controllers[i].name, FPS[i]);

    ui->fps_Controllers[i].text = NULL;
    load_Texture_Text(&(ui->fps_Controllers[i].text), &(common_ui->menu_Font), FPS[i], common_ui->text_Color, &(window->mainRenderer));

    ui->fps_Controllers[i].staged = 0;
    ui->fps_Controllers[i].selected = 0;
    ui->fps_Controllers[i].hover = 0;
  }
  ui->fps_Controllers[2].selected = 1;

  // --- credits ---
  strcpy(ui->credits[0].name, "Credits");

  ui->credits[0].text = NULL;
  load_Texture_Text(&(ui->credits[0].text), &(common_ui->menu_Font), "Credits", common_ui->text_Color, &(window->mainRenderer));

  ui->credits[0].staged = 0;
  ui->credits[0].selected = 0;
  ui->credits[0].hover = 0;
}

void init_Scene3_Menu(Menu_Scene3_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  // --- tutorial background ---
  // background
  ui->tutorial_Backgournd = NULL;
  load_Texture_Img(&(ui->tutorial_Backgournd), "./assets/imgs/menu/buttons_tutorial_settings_background.png", &(window->mainRenderer));

  // --- tutorial title ---
  ui->tutorial_Title_Text = NULL;
  load_Texture_Text(&(ui->tutorial_Title_Text), &(common_ui->menu_Font), "Tutorial", common_ui->text_Color, &(window->mainRenderer));
  ///TODO: finish init scene3
}

void init_DevUI(DevUI *ui)
{
  ui->dev_Font = NULL;
  ui->dev_Font = TTF_OpenFont("./assets/fonts/BalooChettan2-Regular.ttf", 255);
  if (ui->dev_Font == NULL)
    lib_errorLog("failed at loaing font", TTF_GetError());
  ui->FPS_Text = NULL;

  ui->FPS_Color = set_color(255, 255, 0, 255);

  ui->outlines_num = 0;
  ui->distances_num = 0;
}

void init_Quit_PopUp(Quit_PopUp *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  // texture
  ui->pop_Background = NULL;
  load_Texture_Img(&(ui->pop_Background), "./assets/imgs/menu/buttons_tutorial_settings_background.png", &(window->mainRenderer));

  ui->title_Text = NULL;
  load_Texture_Text(&(ui->title_Text), &(common_ui->menu_Font), "Confirm Quit", common_ui->text_Color, &(window->mainRenderer));

  // buttons
  char options[2][10] = {"Quit_Yes", "Quit_No"};
  char text[2][10] = {"Yes", "No"};

  for (int i = 0; i < 2; i++)
  {
    strcpy(ui->confirm[i].name, options[i]);

    ui->confirm[i].text = NULL;
    load_Texture_Text(&(ui->confirm[i].text), &(common_ui->menu_Font), text[i], common_ui->text_Color, &(window->mainRenderer));

    ui->confirm[i].hover = 0;
    ui->confirm[i].staged = 0;
    ui->confirm[i].selected = 0;
  }
}

void init_In_Game_UI(In_Game_UI *ui, GameWindow *window)
{
  // test map
  ui->map = NULL;
  ///TODO: change this to a real map
  load_Texture_Img(&(ui->map), "./assets/test/map_4Kx1.5.png", &(window->mainRenderer));

  // minimap
  ui->minimap_frame = NULL;
  load_Texture_Img(&(ui->minimap_frame), "./assets/imgs/in_game/minimap_frame.png", &(window->mainRenderer));
  ui->enemies_num = 0;
}