#include "../headers/common.h"
#include "../headers/init.h"

void init_manager(GameObject *G)
{
  init_lib();
  init_gameWindow(&(G->window));
}