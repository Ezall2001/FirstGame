#include "./headers/dev.h"
#include "./headers/init.h"
#include "./headers/event.h"
#include "./headers/logic.h"
#include "./headers/renderer.h"
#include "./headers/sound.h"

///NOTE: change the game scene to 0 default
///TODO: make a set color util function and use it

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
      logic_manager(&G);

      // render everything
      renderer_manager(&G);

      // mix sound
      sound_manager(&G);

      cap_FPS(G.dev);
    }
  }
  destroy_GameObject(&G);
  quit_lib();
  return 0;
}
