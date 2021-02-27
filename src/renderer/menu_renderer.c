#include "../headers/renderer.h"
#include "../headers/dev.h"

void render_Common_Menu(Menu_Common_UI *ui, GameWindow *window, GameSound *sound)
{
  int rendered = -1;
  // main background
  rendered = SDL_RenderCopy(window->mainRenderer, ui->main_Background, NULL, &(ui->main_Background_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());
  rendered = -1;

  // shortcuts
  if (sound->mute == 0)
  {
    if (ui->scene_shortcuts[0].staged == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, ui->hover_Mute_Shortcut, NULL, &(ui->scene_shortcuts[0].button_Coords));
    else if (ui->scene_shortcuts[0].hover == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, ui->hover_Mute_Shortcut, NULL, &(ui->scene_shortcuts[0].button_Coords));
    else
      rendered = SDL_RenderCopy(window->mainRenderer, ui->mute_Shortcut, NULL, &(ui->scene_shortcuts[0].button_Coords));
  }
  else if (sound->mute == 1)
  {
    if (ui->scene_shortcuts[0].staged == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, ui->hover_Unmute_Shortcut, NULL, &(ui->scene_shortcuts[0].button_Coords));
    else if (ui->scene_shortcuts[0].hover == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, ui->hover_Unmute_Shortcut, NULL, &(ui->scene_shortcuts[0].button_Coords));
    else
      rendered = SDL_RenderCopy(window->mainRenderer, ui->unmute_Shortcut, NULL, &(ui->scene_shortcuts[0].button_Coords));
  }
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  if (window->menu_scene != 0)
  {
    if (ui->scene_shortcuts[1].staged == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, ui->hover_Back_Shortcut, NULL, &(ui->scene_shortcuts[1].button_Coords));
    else if (ui->scene_shortcuts[1].hover == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, ui->hover_Back_Shortcut, NULL, &(ui->scene_shortcuts[1].button_Coords));
    else
      rendered = SDL_RenderCopy(window->mainRenderer, ui->back_Shortcut, NULL, &(ui->scene_shortcuts[1].button_Coords));
  }

  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());
}

void render_Scene0_Menu(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  int rendered = -1;

  // button's background
  rendered = SDL_RenderCopy(window->mainRenderer, ui->buttons_Background, NULL, &(ui->buttons_Background_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  for (int i = 0; i < 4; i++)
  {

    // buttons
    if (ui->scene_buttons[i].staged == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->click_Button, NULL, &(ui->scene_buttons[i].button_Coords));
    else if (ui->scene_buttons[i].hover == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->hover_Button, NULL, &(ui->scene_buttons[i].button_Coords));
    else
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Button, NULL, &(ui->scene_buttons[i].button_Coords));

    if (rendered != 0)
      lib_errorLog("failed at rendering menu UI", SDL_GetError());

    // button's text
    rendered = SDL_RenderCopy(window->mainRenderer, ui->scene_buttons[i].text, NULL, &(ui->scene_buttons[i].text_Coords));

    if (rendered != 0)
      lib_errorLog("failed at rendering menu UI", SDL_GetError());
  }
}

void render_Scene1_Menu(Menu_Scene1_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  ///TODO: finish this
}

void render_Scene2_Menu(Menu_Scene2_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  int rendered = -1;

  // settings background
  rendered = SDL_RenderCopy(window->mainRenderer, ui->settings_Backgournd, NULL, &(ui->settings_Backgournd_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // settings title
  rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Blue_Button, NULL, &(ui->settings_Title_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // settings title
  rendered = SDL_RenderCopy(window->mainRenderer, ui->settings_Title_Text, NULL, &(ui->settings_Title_Text_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // --- music row ---
  // music title
  rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Blue_Button, NULL, &(ui->music_Title_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // music title text
  rendered = SDL_RenderCopy(window->mainRenderer, ui->music_Text, NULL, &(ui->music_Title_Text_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // music bar
  rendered = SDL_RenderCopy(window->mainRenderer, ui->sound_Bar, NULL, &(ui->music_Bar_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // --- SFX row ---
  // music title
  rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Blue_Button, NULL, &(ui->SFX_Title_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // music title text
  rendered = SDL_RenderCopy(window->mainRenderer, ui->SFX_Text, NULL, &(ui->SFX_Title_Text_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // music bar
  rendered = SDL_RenderCopy(window->mainRenderer, ui->sound_Bar, NULL, &(ui->SFX_Bar_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // minus controllers
  for (int i = 0; i < 4; i += 2)
  {
    if (ui->volume_Controllers[i].staged == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, ui->hover_Minus, NULL, &(ui->volume_Controllers[i].button_Coords));
    else if (ui->volume_Controllers[i].hover == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, ui->hover_Minus, NULL, &(ui->volume_Controllers[i].button_Coords));
    else
      rendered = SDL_RenderCopy(window->mainRenderer, ui->minus, NULL, &(ui->volume_Controllers[i].button_Coords));

    if (rendered != 0)
      lib_errorLog("failed at rendering menu UI", SDL_GetError());
  }

  // plus controllers
  for (int i = 1; i < 4; i += 2)
  {
    if (ui->volume_Controllers[i].staged == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, ui->hover_Plus, NULL, &(ui->volume_Controllers[i].button_Coords));
    else if (ui->volume_Controllers[i].hover == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, ui->hover_Plus, NULL, &(ui->volume_Controllers[i].button_Coords));
    else
      rendered = SDL_RenderCopy(window->mainRenderer, ui->plus, NULL, &(ui->volume_Controllers[i].button_Coords));

    if (rendered != 0)
      lib_errorLog("failed at rendering menu UI", SDL_GetError());
  }

  // scrollers
  for (int i = 0; i < 2; i++)
  {
    rendered = SDL_RenderCopy(window->mainRenderer, ui->sound_Scroller, NULL, &(ui->volume_Scorllers[i].button_Coords));
    if (rendered != 0)
      lib_errorLog("failed at rendering menu UI", SDL_GetError());
  }

  // --- resolution row ---
  for (int i = 0; i < 3; i++)
  {
    if (ui->resolution_Controllers[i].selected == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Blue_Button, NULL, &(ui->resolution_Controllers[i].button_Coords));
    else if (ui->resolution_Controllers[i].staged == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->click_Button, NULL, &(ui->resolution_Controllers[i].button_Coords));
    else if (ui->resolution_Controllers[i].hover == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->hover_Button, NULL, &(ui->resolution_Controllers[i].button_Coords));
    else
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Button, NULL, &(ui->resolution_Controllers[i].button_Coords));

    if (rendered != 0)
      lib_errorLog("failed at rendering menu UI", SDL_GetError());

    rendered = SDL_RenderCopy(window->mainRenderer, ui->resolution_Controllers[i].text, NULL, &(ui->resolution_Controllers[i].text_Coords));
  }

  // --- FPS row ---
  for (int i = 0; i < 3; i++)
  {
    if (ui->fps_Controllers[i].selected == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Blue_Button, NULL, &(ui->fps_Controllers[i].button_Coords));
    else if (ui->fps_Controllers[i].staged == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->click_Button, NULL, &(ui->fps_Controllers[i].button_Coords));
    else if (ui->fps_Controllers[i].hover == 1)
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->hover_Button, NULL, &(ui->fps_Controllers[i].button_Coords));
    else
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Button, NULL, &(ui->fps_Controllers[i].button_Coords));

    if (rendered != 0)
      lib_errorLog("failed at rendering menu UI", SDL_GetError());

    rendered = SDL_RenderCopy(window->mainRenderer, ui->fps_Controllers[i].text, NULL, &(ui->fps_Controllers[i].text_Coords));
  }

  /// --- credits ---
  if (ui->credits[0].staged == 1)
    rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Blue_Button, NULL, &(ui->credits[0].button_Coords));
  else if (ui->credits[0].hover == 1)
    rendered = SDL_RenderCopy(window->mainRenderer, common_ui->hover_Button, NULL, &(ui->credits[0].button_Coords));
  else
    rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Button, NULL, &(ui->credits[0].button_Coords));

  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  rendered = SDL_RenderCopy(window->mainRenderer, ui->credits[0].text, NULL, &(ui->credits[0].text_Coords));
}

void render_Scene3_Menu(Menu_Scene3_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  int rendered = -1;

  // tutorial background
  rendered = SDL_RenderCopy(window->mainRenderer, ui->tutorial_Backgournd, NULL, &(ui->tutorial_Backgournd_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // tutorial title
  rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Blue_Button, NULL, &(ui->tutorial_Title_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // tutorial text title
  rendered = SDL_RenderCopy(window->mainRenderer, ui->tutorial_Title_Text, NULL, &(ui->tutorial_Title_Text_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());
  ///TODO: finish this
}
