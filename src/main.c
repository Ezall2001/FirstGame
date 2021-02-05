#include "./headers/dev.h"
#include "./headers/init.h"
#include "./headers/event.h"

int main(int argc, char *argv[])
{
  GameObject G;

  // initiating the game
  init_manager(&G);

  // hundling dev flags
  if (argc > 1)
    dev_manager(argc, argv, &G);

  while (G.running)
  {
    // hundling all game events
    event_manager(&G);

    SDL_Delay(100);
  }

  SDL_DestroyWindow(G.window.mainWindow);
  quit_lib();
  return 0;
}