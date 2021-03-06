#include "../headers/dev.h"

void dev_manager(int *argc, char *argv[], GameObject *G)
{
  // seperating scenarios and dev flags
  int devIndex = -1;
  int scnIndex = -1;
  int charIndex = 0;

  while (argv[1][charIndex] != '\0')
  {
    if (argv[1][charIndex] == '/')
    {

      strncpy(argv[2], argv[1] + charIndex + 1, strlen(argv[1]) - charIndex);
      argv[1][charIndex] = '\0';

      devIndex = 2;
      scnIndex = 1;
      break;
    }
    charIndex++;
  }

  if (devIndex != -1)
  {
    // flags extraction
    char flags[20][30];
    int flagCount = 1;
    int charCount = 0;
    int charIndex = 4;
    while (argv[devIndex][charIndex] != '\0')
    {
      if (argv[devIndex][charIndex] == '-')
      {
        flags[flagCount - 1][charCount] = '\0';
        flagCount++;
        charCount = 0;
      }
      else
      {
        flags[flagCount - 1][charCount] = argv[devIndex][charIndex];
        charCount++;
      }

      charIndex++;
    }
    flags[flagCount - 1][charCount] = '\0';

    // flags redirection
    for (int i = 0; i < flagCount; i++)
    {
      set_fullScreen(flags[i], &(G->window));
      set_FPS(flags[i], &(G->dev));
      set_FPS_cap(flags[i], &(G->dev));
      set_mute(flags[i], &(G->sound));
      set_outlines(flags[i], &(G->dev));
    }
  }

  // scenarios redirection
  if (scnIndex != -1)
  {

    if (strcmp(argv[scnIndex], "game") == 0)
      (*argc)--;
    else
    {

      proto1(argv[scnIndex], G);
      lvl_simulation(argv[scnIndex]);
      responsive_UI(argv[scnIndex]);
    }
  }
}