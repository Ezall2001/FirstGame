#include "../headers/logic.h"

void logic_manager(GameObject *G)
{
  if (G->window.game_scene == 0)
  {

    bird_Animation(&(G->UI.common_UI), &(G->window), &(G->sound), &(G->dev));
    shortcut_Input(&(G->input), &(G->sound), &(G->window), &(G->UI), &(G->dev));
  }
  else if (G->window.game_scene == 1)
  {
  }
  G->input.num_keys = 0;
}