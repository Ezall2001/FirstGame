#include "../headers/logic.h"

void update_Menu_Common_Coords(Menu_Common_UI *ui, GameWindow *window)
{
  // menu background coords
  ui->main_Background_Coords.x = 0;
  ui->main_Background_Coords.y = 0;
  ui->main_Background_Coords.w = window->w;
  ui->main_Background_Coords.h = window->h;

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
  ui->buttons_Background_Coords.w = 640 * window->win_width_ratio;
  ui->buttons_Background_Coords.h = 520 * window->win_width_ratio;
  ui->buttons_Background_Coords.x = window->w * 0.96 - ui->buttons_Background_Coords.w;
  ui->buttons_Background_Coords.y = window->h * 0.4;

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

    float text_w_ratio = get_Text_W_ratio(common_ui->menu_Font, options[i]);
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
  float text_w_ratio = get_Text_W_ratio(common_ui->menu_Font, "Music");

  ui->settings_Title_Text_Coords.w = 0.3 * ui->settings_Title_Coords.w;
  ui->settings_Title_Text_Coords.h = ui->settings_Title_Text_Coords.w * text_w_ratio;
  ui->settings_Title_Text_Coords.x = ui->settings_Title_Coords.x + (ui->settings_Title_Coords.w - ui->settings_Title_Text_Coords.w) / 2;
  ui->settings_Title_Text_Coords.y = ui->settings_Title_Coords.y + (ui->settings_Title_Coords.h * 0.97 - ui->settings_Title_Text_Coords.h) / 2;

  ui->row_Margin = 95 * window->win_width_ratio;
  ui->column_Margin = 100 * window->win_width_ratio;

  // --- music row ---
  // music title
  ui->music_Title_Coords.w = 300 * window->win_width_ratio;
  ui->music_Title_Coords.h = 70 * window->win_width_ratio;
  ui->music_Title_Coords.x = ui->settings_Backgournd_Coords.x + ui->column_Margin;
  ui->music_Title_Coords.y = ui->settings_Backgournd_Coords.y + ui->row_Margin * 1.3;

  // music text
  text_w_ratio = get_Text_W_ratio(common_ui->menu_Font, "Music");

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
  text_w_ratio = get_Text_W_ratio(common_ui->menu_Font, "SFX");

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

  // --- resolutions row ---
  for (int i = 0; i < 3; i++)
  {
    ui->resolution_Controllers[i].button_Coords.w = 450 * window->win_width_ratio;
    ui->resolution_Controllers[i].button_Coords.h = 70 * window->win_width_ratio;
    ui->resolution_Controllers[i].button_Coords.x = ui->SFX_Title_Coords.x + ((ui->resolution_Controllers[i].button_Coords.w + ui->column_Margin) * i);
    ui->resolution_Controllers[i].button_Coords.y = ui->SFX_Title_Coords.y + ui->SFX_Title_Coords.h + ui->row_Margin;

    text_w_ratio = get_Text_W_ratio(common_ui->menu_Font, ui->resolution_Controllers[i].name);
    ui->resolution_Controllers[i].text_Coords.w = ui->resolution_Controllers[i].button_Coords.w * 0.5;
    ui->resolution_Controllers[i].text_Coords.h = ui->resolution_Controllers[i].text_Coords.w * text_w_ratio;
    ui->resolution_Controllers[i].text_Coords.x = ui->resolution_Controllers[i].button_Coords.x + (ui->resolution_Controllers[i].button_Coords.w - ui->resolution_Controllers[i].text_Coords.w) / 2;
    ui->resolution_Controllers[i].text_Coords.y = ui->resolution_Controllers[i].button_Coords.y + (ui->resolution_Controllers[i].button_Coords.h - ui->resolution_Controllers[i].text_Coords.h) / 2;
  }

  // --- FPS row ---
  for (int i = 0; i < 3; i++)
  {
    ui->fps_Controllers[i].button_Coords.w = 450 * window->win_width_ratio;
    ui->fps_Controllers[i].button_Coords.h = 70 * window->win_width_ratio;
    ui->fps_Controllers[i].button_Coords.x = ui->resolution_Controllers[0].button_Coords.x + ((ui->fps_Controllers[i].button_Coords.w + ui->column_Margin) * i);
    ui->fps_Controllers[i].button_Coords.y = ui->resolution_Controllers[0].button_Coords.y + ui->resolution_Controllers[0].button_Coords.h + ui->row_Margin;

    text_w_ratio = get_Text_W_ratio(common_ui->menu_Font, ui->fps_Controllers[i].name);
    int num_letter = strlen(ui->fps_Controllers[i].name);
    ui->fps_Controllers[i].text_Coords.w = ui->fps_Controllers[i].button_Coords.w * 0.06 * num_letter;
    ui->fps_Controllers[i].text_Coords.h = ui->fps_Controllers[i].text_Coords.w * text_w_ratio;
    ui->fps_Controllers[i].text_Coords.x = ui->fps_Controllers[i].button_Coords.x + (ui->fps_Controllers[i].button_Coords.w - ui->fps_Controllers[i].text_Coords.w) / 2;
    ui->fps_Controllers[i].text_Coords.y = ui->fps_Controllers[i].button_Coords.y + (ui->fps_Controllers[i].button_Coords.h - ui->fps_Controllers[i].text_Coords.h) / 2;
  }

  // --- credits ---
  ui->credits[0].button_Coords.w = 250 * window->win_width_ratio;
  ui->credits[0].button_Coords.h = 60 * window->win_width_ratio;
  ui->credits[0].button_Coords.x = ui->fps_Controllers[0].button_Coords.x;
  ui->credits[0].button_Coords.y = ui->fps_Controllers[0].button_Coords.y + ui->fps_Controllers[0].button_Coords.h + ui->row_Margin;

  text_w_ratio = get_Text_W_ratio(common_ui->menu_Font, ui->credits[0].name);
  ui->credits[0].text_Coords.w = ui->credits[0].button_Coords.w * 0.5;
  ui->credits[0].text_Coords.h = ui->credits[0].text_Coords.w * text_w_ratio;
  ui->credits[0].text_Coords.x = ui->credits[0].button_Coords.x + (ui->credits[0].button_Coords.w - ui->credits[0].text_Coords.w) / 2;
  ui->credits[0].text_Coords.y = ui->credits[0].button_Coords.y + (ui->credits[0].button_Coords.h - ui->credits[0].text_Coords.h) / 2;
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
  float text_w_ratio = get_Text_W_ratio(common_ui->menu_Font, "Tutorial");

  ui->tutorial_Title_Text_Coords.w = 0.3 * ui->tutorial_Title_Coords.w;
  ui->tutorial_Title_Text_Coords.h = ui->tutorial_Title_Text_Coords.w * text_w_ratio;
  ui->tutorial_Title_Text_Coords.x = ui->tutorial_Title_Coords.x + (ui->tutorial_Title_Coords.w - ui->tutorial_Title_Text_Coords.w) / 2;
  ui->tutorial_Title_Text_Coords.y = ui->tutorial_Title_Coords.y + (ui->tutorial_Title_Coords.h * 0.97 - ui->tutorial_Title_Text_Coords.h) / 2;

  ///TODO: finish this
}

void update_Quit_PopUp_Coords(Quit_PopUp *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  // background
  ui->pop_Background_Coords.w = window->w * 0.5;
  ui->pop_Background_Coords.h = window->h * 0.4;
  ui->pop_Background_Coords.x = (window->w - ui->pop_Background_Coords.w) / 2;
  ui->pop_Background_Coords.y = (window->h - ui->pop_Background_Coords.h) / 2;

  // title background
  ui->title_Background_Coords.w = 360 * window->win_width_ratio;
  ui->title_Background_Coords.h = 60 * window->win_width_ratio;
  ui->title_Background_Coords.x = ui->pop_Background_Coords.x + (ui->pop_Background_Coords.w - ui->title_Background_Coords.w) / 2;
  ui->title_Background_Coords.y = ui->pop_Background_Coords.y - (ui->title_Background_Coords.h / 2);

  // title text
  float text_ratio = get_Text_W_ratio(common_ui->menu_Font, "Confirm Quit");
  ui->title_Text_Coords.w = ui->title_Background_Coords.w * 0.45;
  ui->title_Text_Coords.h = ui->title_Text_Coords.w * text_ratio;
  ui->title_Text_Coords.x = ui->title_Background_Coords.x + (ui->title_Background_Coords.w - ui->title_Text_Coords.w) / 2;
  ui->title_Text_Coords.y = ui->title_Background_Coords.y + (ui->title_Background_Coords.h - ui->title_Text_Coords.h) / 2;

  // buttons
  ui->column_Margin = ui->pop_Background_Coords.w * 0.2;
  char text[2][10] = {"Yes", "No"};

  for (int i = 0; i < 2; i++)
  {
    // background
    ui->confirm[i].button_Coords.w = 250 * window->win_width_ratio;
    ui->confirm[i].button_Coords.h = 70 * window->win_width_ratio;
    ui->confirm[i].button_Coords.x = ui->pop_Background_Coords.x + pow(-1, i) * ui->column_Margin + (ui->pop_Background_Coords.w - ui->confirm[i].button_Coords.w) * i;
    ui->confirm[i].button_Coords.y = ui->pop_Background_Coords.y + (ui->pop_Background_Coords.h * 0.45);

    // text
    text_ratio = get_Text_W_ratio(common_ui->menu_Font, text[i]);
    int num_letters = strlen(text[i]);
    ui->confirm[i].text_Coords.w = ui->confirm[i].button_Coords.w * 0.1 * num_letters;
    ui->confirm[i].text_Coords.h = ui->confirm[i].text_Coords.w * text_ratio;
    ui->confirm[i].text_Coords.x = ui->confirm[i].button_Coords.x + (ui->confirm[i].button_Coords.w - ui->confirm[i].text_Coords.w) / 2;
    ui->confirm[i].text_Coords.y = ui->confirm[i].button_Coords.y + (ui->confirm[i].button_Coords.h - ui->confirm[i].text_Coords.h) / 2;
  }
}

void bird_Animation(Menu_Common_UI *ui, GameWindow *window, GameSound *sound, GameDev *dev)
{
  static int delay = 0;
  static Uint32 startCount = 0;
  static int init_anim = 0;
  static int count = 0;
  static float real_x = 0;
  static float real_y = 0;
  static float w = 0, h = 0;
  static float speed = 0;
  static int last_annim = 0;

  if (ui->bird_animation_play != 0)
  {
    if (init_anim != 0)
    {
      ui->bird_speed = speed * window->win_width_ratio * dev->deltaTime;
      if (ui->bird_speed == 0)
        ui->bird_speed = 1;

      ui->birdCoords.w = w * window->win_width_ratio;
      ui->birdCoords.h = h * window->win_width_ratio;

      float d = sqrt(pow(real_x - ui->dst_birdCoords.x, 2) + pow(real_y - ui->dst_birdCoords.y, 2));
      float new_d = d - ui->bird_speed;
      if (ui->bird_animation_play < 0)
      {
        real_x = ((fabs(ui->dst_birdCoords.x - real_x) * new_d) / d) + ui->dst_birdCoords.x;
      }
      else
      {
        real_x = ui->dst_birdCoords.x - ((fabs(ui->dst_birdCoords.x - real_x) * new_d) / d);
      }

      if (real_y > ui->dst_birdCoords.y)
      {
        real_y = ui->dst_birdCoords.y + ((fabs(ui->dst_birdCoords.y - real_y) * new_d) / d);
      }
      else
      {
        real_y = ui->dst_birdCoords.y - ((fabs(ui->dst_birdCoords.y - real_y) * new_d) / d);
      }

      ui->birdCoords.x = (int)real_x;
      ui->birdCoords.y = (int)real_y;

      if (new_d <= 0)
      {
        init_anim = 0;
        ui->bird_animation_play = 0;
        sound->bird_play = 0;
      }
    }
    else if (init_anim == 0)
    {
      speed = get_Random_Number(&(window->r), 100, 200);

      w = 200 * ((float)get_Random_Number(&(window->r), 50, 100) / 100) * window->win_width_ratio;
      h = 200 * ((float)get_Random_Number(&(window->r), 50, 100) / 100) * window->win_width_ratio;
      ui->birdCoords.w = w;
      ui->birdCoords.h = h;

      // dst coords
      if (ui->bird_animation_play < 0)
        ui->dst_birdCoords.x = -ui->birdCoords.w;
      else
        ui->dst_birdCoords.x = window->w;
      ui->dst_birdCoords.y = get_Random_Number(&(window->r), 10, window->h * 0.7);

      // starting coords

      if (ui->bird_animation_play < 0)
        real_x = window->w;
      else
        real_x = -ui->birdCoords.w;
      real_y = get_Random_Number(&(window->r), 10, window->h * 0.7);

      ui->birdCoords.x = real_x;
      ui->birdCoords.y = real_y;

      sound->bird_play = 1;

      init_anim = 1;
    }
  }
  else if (ui->bird_animation_play == 0)
  {
    if (count == 1)
    {
      if (SDL_GetTicks() - startCount > delay)
      {
        do
        {
          ui->bird_animation_play = get_Random_Number(&(window->r), -3, 3);
        } while (ui->bird_animation_play == last_annim || ui->bird_animation_play == 0);

        last_annim = ui->bird_animation_play;
        count = 0;
      }
    }
    else if (count == 0)
    {
      startCount = SDL_GetTicks();
      delay = get_Random_Number(&(window->r), 2000, 5000);
      count = 1;
    }
  }
}

void wind_Animation(Menu_Common_UI *ui, GameWindow *window, GameSound *sound, GameDev *dev)
{
  static int delay = 0;
  static Uint32 startCount = 0;
  static int init_anim = 0;
  static int count = 0;
  static float real_x = 0;
  static float real_y = 0;
  static float w = 0, h = 0;
  static float speed = 0;
  static int wind_part = 0;
  /// TODO: finish wind animation
  if (ui->wind_animation_play != 0)
  {
    if (init_anim == 1)
    {
      ui->wind_speed = speed * window->win_width_ratio * dev->deltaTime;
      ui->windCoords.w = w * window->win_width_ratio;
      ui->windCoords.h = h * window->win_width_ratio;

      if (ui->wind_animation_play < 0)
      {
        ui->wind_speed = ui->wind_speed * -1;
      }
      real_x += ui->wind_speed;
      real_y += ui->windCoords.h * (wind_part % 2);

      ui->windCoords.x = (int)real_x;
      ui->windCoords.y = (int)real_y;
    }
    else if (init_anim == 0)
    {
      speed = get_Random_Number(&(window->r), 100, 200);
      w = get_Random_Number(&(window->r), 100, 200) * window->win_width_ratio;
      h = get_Random_Number(&(window->r), 100, 200) * window->win_width_ratio;
      real_x = get_Random_Number(&(window->r), w * 3, window->w - (w * 3));
      real_y = get_Random_Number(&(window->r), window->h * 0.1, window->h * 0.65);

      wind_part = 0;

      sound->wind_play = 1;
      init_anim = 1;
    }
  }
  else if (ui->wind_animation_play == 0)
  {
    if (count == 1)
    {
      if (SDL_GetTicks() - startCount > delay)
      {
        do
        {
          ui->wind_animation_play = get_Random_Number(&(window->r), -3, 3);
        } while (ui->wind_animation_play == 0);

        count = 0;
      }
    }
    else if (count == 0)
    {
      startCount = SDL_GetTicks();
      delay = 0; //get_Random_Number(&(window->r), 3000, 7000);
      count = 1;
    }
  }
}

void menu_Intro_Animation(Menu_Common_UI *ui, GameWindow *window, GameDev *dev)
{
  static float w_mod = 1;
  static float h_mod = 1;

  if (w_mod > 0 || h_mod > 0)
  {
    ui->main_Background_Coords.w = window->w * (1 + 0.25 * w_mod);
    ui->main_Background_Coords.h = window->h * (1 + 0.25 * h_mod);
    ui->main_Background_Coords.x = -fabs(ui->main_Background_Coords.w - window->w) / 2;
    ui->main_Background_Coords.y = -fabs(ui->main_Background_Coords.h - window->h) / 2;

    w_mod -= 1 * dev->deltaTime;
    h_mod -= 1 * dev->deltaTime;
  }
}
