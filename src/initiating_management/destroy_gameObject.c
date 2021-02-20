#include "../headers/init.h"

void destroy_GameObject(GameObject *G)
{
  // GameWindow
  SDL_DestroyRenderer(G->window.mainRenderer);
  SDL_DestroyWindow(G->window.mainWindow);

  // devUI
  TTF_CloseFont(G->devUI.dev_Font);
  SDL_DestroyTexture(G->devUI.FPS_Text);

  // outGameUi
  ///TODO:  destroy all the menu
}