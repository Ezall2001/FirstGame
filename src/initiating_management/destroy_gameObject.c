#include "../headers/init.h"

void destroy_GameObject(GameObject *G)
{
  // GameWindow
  SDL_FreeSurface(G->window.mainSurface);
  SDL_DestroyWindow(G->window.mainWindow);

  // FPS UI
  TTF_CloseFont(G->ui.dev_Font);
  SDL_FreeSurface(G->ui.FPS_surface);
}