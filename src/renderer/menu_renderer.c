#include "../headers/renderer.h"
#include "../headers/dev.h"

void render_Scene0_Menu(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{
  int rendered = -1;

  // button's background
  rendered = SDL_RenderCopy(window->mainRenderer, ui->buttons_Background, NULL, &(ui->buttons_Background_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());

  // buttons
  for (int i = 0; i < 4; i++)
  {
    if (ui->scene_buttons[i].hover == 0)
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->static_Button, NULL, &(ui->scene_buttons[i].button_Coords));
    else
      rendered = SDL_RenderCopy(window->mainRenderer, common_ui->hover_Button, NULL, &(ui->scene_buttons[i].button_Coords));

    if (rendered != 0)
      lib_errorLog("failed at rendering menu UI", SDL_GetError());
  }
}

void render_Common_Menu(Menu_Common_UI *ui, GameWindow *window)
{
  int rendered = -1;
  // main background
  rendered = SDL_RenderCopy(window->mainRenderer, ui->main_Background, NULL, &(ui->main_Background_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());
  rendered = -1;

  // title
  rendered = -1;
  rendered = SDL_RenderCopy(window->mainRenderer, ui->title_Text, NULL, &(ui->title_Coords));
  if (rendered != 0)
    lib_errorLog("failed at rendering menu UI", SDL_GetError());
}