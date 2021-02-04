#include "../headers/common.h"

void lib_errorLog(char msg[], char *error)
{
  printf("%s: %s\n", msg, error);
}