#include "../headers/renderer.h"
#include "../headers/dev.h"

void update_window(GameWindow *window)
{
  int update_Window = SDL_UpdateWindowSurface(window->mainWindow);
  if (update_Window != 0)
    lib_errorLog("failed at updating window", SDL_GetError());
}

void render_firstLayer(GameWindow *window)
{
  Uint32 firstLayer = SDL_MapRGB(window->mainSurface->format, 0, 0, 0);
  int filled_fristLayer = SDL_FillRect(window->mainSurface, NULL, firstLayer);
  if (filled_fristLayer != 0)
    lib_errorLog("failed at filling first layer", SDL_GetError());
}

void render_FPS(GameWindow *window, UI *ui, GameDev dev)
{

  char displayFPS[5];
  itoa(dev.FPS, displayFPS, 10);
  ui->FPS_surface = TTF_RenderUTF8_Solid(ui->dev_Font, displayFPS, ui->FPS_Color);
  if (ui->FPS_surface == NULL)
    lib_errorLog("failed at rendring text surface", TTF_GetError());
  int blit_FPS = SDL_BlitSurface(ui->FPS_surface, NULL, window->mainSurface, NULL);
  if (blit_FPS != 0)
    lib_errorLog("failed at blit surface", SDL_GetError());
}