#include "./headers/dev.h"
#include "./headers/init.h"
#include "./headers/event.h"
#include "./headers/renderer.h"

int main(int argc, char *argv[])
{
  GameObject G;

  // initiating the game
  init_manager(&G);

  // hundling dev flags and scenarios
  if (argc > 1)
    dev_manager(&argc, argv, &G);

  if (argc < 3)
  {
    while (G.window.running)
    {
      // hundling all game events
      event_manager(&G);

      // hundling dev loop functionalities
      dev_loop(&G);

      // logic

      // render everything
      renderer_manager(&G);

      cap_FPS(G.dev);
    }
  }
  destroy_GameObject(&G);
  quit_lib();
  return 0;
}
