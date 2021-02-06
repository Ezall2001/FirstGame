#include "../headers/dev.h"

void dev_manager(int argc, char *argv[], GameObject *G)
{
  // checking for scenarios or dev flags
  int devIndex = -1;
  int scnIndex = -1;
  char prefix[4];
  for (int i = 1; i < argc; i++)
  {
    strncpy(prefix, argv[i], 3);
    prefix[3] = '\0';
    if (strcmp(prefix, "dev") == 0)
      devIndex = 1;
    if (strcmp(prefix, "scn") == 0)
    {
      if (devIndex == 1)
        scnIndex = 2;
      else
        scnIndex = 1;
    }
  }

  printf("scnIndex: %d  devInxed: %d", scnIndex, devIndex);
  printf("hello");

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
    }
  }
}