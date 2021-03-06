#include "../headers/renderer.h"
#include "../headers/dev.h"

void render_Map(GameWindow *window, In_Game_UI *ui)
{
  int rendered = SDL_RenderCopy(window->mainRenderer, ui->map, &(ui->src_Map_Coords), NULL);
  if (rendered != 0)
    lib_errorLog("failed at rendering texture", SDL_GetError());
}