#include "../headers/renderer.h"
#include "../headers/dev.h"

void renderer_manager(GameObject *G)
{
  update_renderer(&(G->window));

  if (G->window.game_scene == 0)
  {
    switch (G->window.menu_scene)
    {
    case 0:
      render_main_menu(&(G->menuUI), &(G->window));
      break;

    default:
      break;
    }
  }

  if (G->dev.show_FPS)
    render_FPS(&(G->window), &(G->devUI), G->dev);

  SDL_RenderPresent(G->window.mainRenderer);
}