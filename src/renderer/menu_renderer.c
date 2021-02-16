#include "../headers/renderer.h"
#include "../headers/dev.h"

void render_main_menu(MenuUI *ui, GameWindow *window)
{
  int rendered = -1;
  SDL_Rect temp_Button_Coords;
  // main background
  rendered = SDL_RenderCopy(window->mainRenderer, ui->main_Background, NULL, &ui->main_Background_Coords);
  if (rendered != 0)
    lib_errorLog("failed at rendering menu", SDL_GetError());
  rendered = -1;

  // title
  rendered = -1;
  rendered = SDL_RenderCopy(window->mainRenderer, ui->title_Text, NULL, &ui->title_Coords);
  if (rendered != 0)
    lib_errorLog("failed at rendering menu", SDL_GetError());

  // start button
  rendered = -1;
  rendered = SDL_RenderCopy(window->mainRenderer, ui->start_Text, NULL, &ui->start_Coords);
  if (rendered != 0)
    lib_errorLog("failed at rendering menu", SDL_GetError());

  temp_Button_Coords.w = ui->start_Coords.w * 3;
  temp_Button_Coords.h = ui->start_Coords.h * 3;
  temp_Button_Coords.x = ui->start_Coords.x - (temp_Button_Coords.w - ui->start_Coords.w) * 0.5;
  temp_Button_Coords.y = ui->start_Coords.y;

  rendered = -1;
  rendered = SDL_RenderCopy(window->mainRenderer, ui->static_Button, NULL, &temp_Button_Coords);
  if (rendered != 0)
    lib_errorLog("failed at rendering menu", SDL_GetError());
}