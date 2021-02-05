#include "./headers/dev.h"
#include "./headers/init.h"

int main(int argc, char *argv[])
{
  GameObject G;

  // initiating the game
  init_manager(&G);

  // hundling dev flags
  if (argc > 0)
    dev_manager(argc, argv, &G);

  int running = 1;
  while (running)
  {

    // running -= 0.1;
    SDL_Delay(100);
  }

  SDL_DestroyWindow(G.window.mainWindow);
  quit_lib();
  return 0;
}