#include "../headers/renderer.h"
#include "../headers/dev.h"

void update_renderer(GameWindow *window)
{
  int update_Renderer = SDL_RenderClear(window->mainRenderer);

  if (update_Renderer != 0)
    lib_errorLog("failed at updating window", SDL_GetError());
}

void render_FPS(GameWindow *window, DevUI *ui, GameDev dev)
{
  // converting FPS from int to string
  char displayFPS[5];
  itoa(dev.FPS, displayFPS, 10);

  // create the texture
  SDL_Surface *FPS_surface = TTF_RenderUTF8_Solid(ui->dev_Font, displayFPS, ui->FPS_Color);
  if (FPS_surface == NULL)
    lib_errorLog("failed at rendering text surface", TTF_GetError());

  ui->FPS_Text = SDL_CreateTextureFromSurface(window->mainRenderer, FPS_surface);
  if (ui->FPS_Text == NULL)
    lib_errorLog("failed at converting text surface to texture", SDL_GetError());

  // copy to renderer
  SDL_Rect dstFPS = {0, 0, 20, 26};
  if (((float)dev.FPS / 100) > 1)
    dstFPS.w = 30;

  int rendered = SDL_RenderCopy(window->mainRenderer, ui->FPS_Text, NULL, &dstFPS);
  if (rendered != 0)
    lib_errorLog("failed at blit surface", SDL_GetError());

  SDL_FreeSurface(FPS_surface);
}