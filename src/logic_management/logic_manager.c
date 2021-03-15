#include "../headers/logic.h"
#include "../headers/init.h"

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
    if (G->window.in_game_init == 0)
    {
      init_survivors(&(G->logic));
      init_bird(&(G->logic), G->window.game_stage);
      init_sheep(&(G->logic), 1);

      G->window.in_game_init = 1;
    }

    ///////////////////////////////
    ///////// behaviors
    ///////////////////////////////
    main_player_Behavior(&(G->logic), &(G->window), &(G->dev), &(G->input));

    bird_Behavior(&(G->logic), &(G->window), &(G->dev));
    sheep_Behavior(&(G->logic), &(G->window), &(G->dev));
    melee_skeleton_Behavior(&(G->logic), &(G->window), &(G->dev));
    archer_skeleton_Behavior(&(G->logic), &(G->window), &(G->dev));

    ///////////////////////////////
    ///////// converting systems
    ///////////////////////////////
    update_Cam_Coords(&(G->logic), &(G->window), &(G->UI.in_game_UI));
    update_Minimap_Coords(&(G->logic), &(G->window), &(G->UI.in_game_UI));
  }
  G->input.num_keys = 0;
}