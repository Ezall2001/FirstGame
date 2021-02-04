#include "./headers/common.h"
#include "./headers/init.h"

int main(int argc, char *argv[])
{
  init_lib();

  int running = 1;
  while (running)
  {
    if (argc > 1)
      dev_manager(argv);
    running = 0;
  }

  quit_lib();
  return 0;
}