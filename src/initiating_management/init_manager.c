#include "../headers/common.h"
#include "../headers/init.h"

void init_manager(GameObject *G)
{
  init_lib();

  G->running = 1;

  init_gameWindow(&(G->window));
}