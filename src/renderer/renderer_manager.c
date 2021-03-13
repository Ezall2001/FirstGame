#include "../headers/renderer.h"

void renderer_manager(GameObject *G)
{
  update_renderer(&(G->window));

  if (G->window.game_scene == 0)
  {
    render_Common_Menu(&(G->UI.common_UI), &(G->window), &(G->sound), &(G->dev));

    switch (G->window.menu_scene)
    {
    case 0:
      render_Scene0_Menu(&(G->UI.scene0_UI), &(G->UI.common_UI), &(G->window));
      break;

    case 1:
      render_Scene1_Menu(&(G->UI.scene1_UI), &(G->UI.common_UI), &(G->window));
      break;

    case 2:
      render_Scene2_Menu(&(G->UI.scene2_UI), &(G->UI.common_UI), &(G->window));
      break;

    case 3:
      render_Scene3_Menu(&(G->UI.scene3_UI), &(G->UI.common_UI), &(G->window));
      break;

    default:
      break;
    }
    menu_intro(&(G->window), &(G->dev));

    if (G->window.popUp == 1)
      render_Quit_PopUp(&(G->UI.quit_PopUp), &(G->UI.common_UI), &(G->window));
  }
  else if (G->window.game_scene == 1)
  {

    render_Map(&(G->window), &(G->UI.in_game_UI));

    if (G->dev.show_boxes == 1)
      render_Boxes(&(G->window), &(G->UI.dev_UI));

    if (G->dev.show_ranges == 1)
      render_Ranges(&(G->window), &(G->UI.dev_UI));
  }

  if (G->dev.show_FPS == 1)
    render_FPS(&(G->window), &(G->UI.dev_UI), G->dev);

  SDL_RenderPresent(G->window.mainRenderer);
}