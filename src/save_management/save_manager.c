#include "../headers/save.h"

void save_manager(GameObject *G, int save_load)
{
  if (save_load == 1)
  {
    load_Settings(&(G->sound), &(G->window));
    load_Dev(&(G->dev));
  }
  else if (save_load == 0)
  {
    save_Settings(&(G->sound), &(G->window));
    save_Dev(&(G->dev));
  }
}