#include "../headers/renderer.h"
#include "../headers/dev.h"

void renderer_manager(GameObject *G)
{
  update_renderer(&(G->window));

  if (G->window.game_scene == 0)
  {
    render_Common_Menu(&(G->menuUI.common_UI), &(G->window));
    switch (G->window.menu_scene)
    {
    case 0:
      render_Scene0_Menu(&(G->menuUI.scene0_UI), &(G->menuUI.common_UI), &(G->window));
      break;

    case 1:
      render_Scene1_Menu(&(G->menuUI.scene1_UI), &(G->menuUI.common_UI), &(G->window));
      break;

    case 2:
      render_Scene2_Menu(&(G->menuUI.scene2_UI), &(G->menuUI.common_UI), &(G->window));
      break;

    case 3:
      render_Scene3_Menu(&(G->menuUI.scene3_UI), &(G->menuUI.common_UI), &(G->window));
      break;

    default:
      break;
    }
  }

  if (G->dev.show_FPS)
    render_FPS(&(G->window), &(G->devUI), G->dev);

  SDL_RenderPresent(G->window.mainRenderer);
}