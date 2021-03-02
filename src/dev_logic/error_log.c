#include "../headers/dev.h"

void lib_errorLog(char msg[], const char *error)
{
  printf("%s: %s\n", msg, error);
}

void coords_log(int x, int y, int w, int h)
{
  printf("x: %d   y: %d   w: %d   h: %d\n", x, y, w, h);
}