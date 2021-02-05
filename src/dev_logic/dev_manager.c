#include "../headers/dev.h"

void dev_manager(int argc, char *argv[], GameObject *G)
{
  // flags extraction
  char flags[20][30];
  int flagCount = 1;
  int charCount = 0;
  int charIndex = 4;
  while (argv[1][charIndex] != '\0')
  {
    if (argv[1][charIndex] == '-')
    {
      flags[flagCount - 1][charCount] = '\0';
      flagCount++;
      charCount = 0;
    }
    else
    {
      flags[flagCount - 1][charCount] = argv[1][charIndex];
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