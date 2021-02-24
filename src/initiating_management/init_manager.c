#include "../headers/init.h"

void init_manager(GameObject *G)
{
  init_lib();
  init_GameWindow(&(G->window));
  init_GameDev(&(G->dev));
  init_GameInput(&(G->input));
  init_GameUI(&(G->UI), &(G->window));
}