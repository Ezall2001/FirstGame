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
  SDL_FillRect(window->mainSurface, NULL, firstLayer);
}

void render_FPS(GameWindow *window, UI *ui, GameDev dev)
{
  char displayFPS[5];
  itoa(dev.FPS, displayFPS, 10);
  ui->FPS_surface = TTF_RenderUTF8_Solid(ui->dev_Font, displayFPS, ui->FPS_Color);
  SDL_BlitSurface(ui->FPS_surface, NULL, window->mainSurface, NULL);
}