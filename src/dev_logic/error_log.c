#include "../headers/dev.h"

void lib_errorLog(char msg[], const char *error)
{
  printf("%s: %s\n", msg, error);
}