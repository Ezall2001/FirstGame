#include "../headers/renderer.h"

void render_Map(GameWindow *window, In_Game_UI *ui)
{
  int rendered = SDL_RenderCopy(window->mainRenderer, ui->map, &(ui->src_Map_Coords), NULL);
  if (rendered != 0)
    lib_errorLog("failed at rendering texture", SDL_GetError());
}

void render_minimap(GameWindow *window, In_Game_UI *ui)
{
  int setColor = 0;
  int fillRect = 0;
  int render = 0;

  // minimap background
  int setBlend = SDL_SetRenderDrawBlendMode(window->mainRenderer, SDL_BLENDMODE_BLEND);
  if (setBlend != 0)
    lib_errorLog("failed at setting blend mode", SDL_GetError());

  setColor = SDL_SetRenderDrawColor(window->mainRenderer, 0, 0, 0, 200);
  if (setColor != 0)
    lib_errorLog("failed at setting renderer color", SDL_GetError());

  fillRect = SDL_RenderFillRect(window->mainRenderer, &(ui->minimap_coords));
  if (fillRect != 0)
    lib_errorLog("failed at fill rect", SDL_GetError());

  // camera
  setColor = SDL_SetRenderDrawColor(window->mainRenderer, 255, 255, 255, 200);
  if (setColor != 0)
    lib_errorLog("failed at setting renderer color", SDL_GetError());

  fillRect = SDL_RenderDrawRect(window->mainRenderer, &(ui->minimap_camera_coords));
  if (fillRect != 0)
    lib_errorLog("failed at fill rect", SDL_GetError());

  // minimap frame
  render = SDL_RenderCopy(window->mainRenderer, ui->minimap_frame, NULL, &(ui->minimap_frame_coords));
  if (render != 0)
    lib_errorLog("failed at rendering texture", SDL_GetError());

  // players
  setColor = SDL_SetRenderDrawColor(window->mainRenderer, 38, 235, 93, 200);
  if (setColor != 0)
    lib_errorLog("failed at setting renderer color", SDL_GetError());

  for (int i = 0; i < 2; i++)
  {
    fillRect = SDL_RenderFillRect(window->mainRenderer, &(ui->minimap_players_coords[i]));
    if (fillRect != 0)
      lib_errorLog("failed at fill rect", SDL_GetError());
  }

  // enemies
  setColor = SDL_SetRenderDrawColor(window->mainRenderer, 235, 38, 47, 200);
  if (setColor != 0)
    lib_errorLog("failed at setting renderer color", SDL_GetError());

  for (int i = 0; i < ui->enemies_num; i++)
  {
    fillRect = SDL_RenderFillRect(window->mainRenderer, &(ui->minimap_enemies_coords[i]));
    if (fillRect != 0)
      lib_errorLog("failed at fill rect", SDL_GetError());
  }
}