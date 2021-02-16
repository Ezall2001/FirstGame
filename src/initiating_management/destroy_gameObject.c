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
  TTF_CloseFont(G->menuUI.menu_Font);
  SDL_DestroyTexture(G->menuUI.static_Button);
  SDL_DestroyTexture(G->menuUI.hover_Button);
  SDL_DestroyTexture(G->menuUI.main_Background);
  SDL_DestroyTexture(G->menuUI.menu_Background);
  SDL_DestroyTexture(G->menuUI.title_Text);
  SDL_DestroyTexture(G->menuUI.start_Text);
  SDL_DestroyTexture(G->menuUI.settings_Text);
  SDL_DestroyTexture(G->menuUI.tutorial_Text);
  SDL_DestroyTexture(G->menuUI.quit_Text);
}