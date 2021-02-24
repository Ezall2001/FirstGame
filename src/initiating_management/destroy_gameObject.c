#include "../headers/init.h"

void destroy_GameObject(GameObject *G)
{
  // GameWindow
  SDL_DestroyRenderer(G->window.mainRenderer);
  SDL_DestroyWindow(G->window.mainWindow);

  // devUI
  TTF_CloseFont(G->UI.dev_UI.dev_Font);
  SDL_DestroyTexture(G->UI.dev_UI.FPS_Text);

  // outGameUi
  ///TODO:  destroy all the menu
}