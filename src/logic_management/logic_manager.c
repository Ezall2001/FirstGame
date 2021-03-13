#include "../headers/logic.h"

void logic_manager(GameObject *G)
{
  if (G->window.game_scene == 0)
  {
    menu_Intro_Animation(&(G->UI.common_UI), &(G->window), &(G->dev));
    scene0_Intro_Animation(&(G->UI.scene0_UI), &(G->window), &(G->dev));
    wind_Animation(&(G->UI.common_UI), &(G->window), &(G->sound), &(G->dev));
    bird_Animation(&(G->UI.common_UI), &(G->window), &(G->sound), &(G->dev));
    shortcut_Input(&(G->input), &(G->sound), &(G->window), &(G->UI), &(G->dev));
  }
  else if (G->window.game_scene == 1)
  {
    ///////////////////////////////
    ///////// init game
    ///////////////////////////////
    static int game_init = 0;
    if (game_init == 0)
    {
    }
    ///////////////////////////////
    ///////// behaviors
    ///////////////////////////////
    main_player_Behavior(&(G->logic), &(G->window), &(G->dev), &(G->input));

    bird_Behavior(&(G->logic), &(G->window), &(G->dev));

    ///////////////////////////////
    ///////// converting systems
    ///////////////////////////////
    update_Cam_Coords(&(G->logic), &(G->window), &(G->UI.in_game_UI));
  }
  G->input.num_keys = 0;
}