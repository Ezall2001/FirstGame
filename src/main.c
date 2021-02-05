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

    //hundling dev loop functionalities
    dev_loop(&G);

    // hundling all game events
    event_manager(&G);

    ///TODO: temp to not burn the CPU
    cap_FPS(G.dev);
    // SDL_Delay(32);
  }

  ///TODO: refactor this
  SDL_DestroyWindow(G.window.mainWindow);
  quit_lib();
  return 0;
}