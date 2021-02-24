#include "../headers/logic.h"

void logic_manager(GameObject *G)
{
  if (G->window.game_scene == 0)
  {
    shortcut_Input(&(G->input), &(G->sound), &(G->window));
  }
  else if (G->window.game_scene == 1)
  {
  }
  G->input.num_keys = 0;
}