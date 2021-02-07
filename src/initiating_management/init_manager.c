#include "../headers/init.h"

void init_manager(GameObject *G)
{
  init_lib();
  init_gameWindow(&(G->window));
  init_gameDev(&(G->dev));
  init_UI(&(G->ui));
}