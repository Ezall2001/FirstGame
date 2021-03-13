#include "./headers/dev.h"
#include "./headers/init.h"
#include "./headers/event.h"
#include "./headers/logic.h"
#include "./headers/renderer.h"
#include "./headers/sound.h"
#include "./headers/save.h"

///NOTE: change the game scene to 0 default
///TODO: update comments

int main(int argc, char *argv[])
{
  GameObject G;

  // initiating the game
  init_manager(&G);

  // laoding data
  save_manager(&G, 1);
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

  // save data
  save_manager(&G, 0);

  // free memory
  destroy_GameObject(&G);
  quit_lib();

  return 0;
}
