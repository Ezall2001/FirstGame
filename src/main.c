#include "./headers/dev.h"
#include "./headers/init.h"
#include "./headers/event.h"
#include "./headers/renderer.h"

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

    //hundling dev loop functionalities
    dev_loop(&G);

    renderer_manager(&G);

    cap_FPS(G.dev);
  }

  ///TODO: free game objects
  quit_lib();
  return 0;
}