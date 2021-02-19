#include "../headers/renderer.h"
#include "../headers/dev.h"

void render_Scene0_Menu(MenuUI *ui, GameWindow *window)
{
  render_Common_Menu(&(ui->common_UI), window);
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