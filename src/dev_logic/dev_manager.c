#include "../headers/common.h"

void dev_manager(char *argv[])
{
  // flags extraction
  char flags[20][30];
  int flagCount = 0;
  int charCount = 0;
  int charIndex = 3;
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

  // flags redirection
  for (int i = 0; i < flagCount; i++)
  {
    if (strcmp(flags[i], "fps") == 0)
      displayFPS();
  }
}