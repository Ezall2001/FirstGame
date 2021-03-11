#include "../../headers/dev.h"

int exp_lvl(int lvl)
{
  return (int)(30 * pow(lvl, lvl * 0.07) + 70);
}

int exp_stage(int stage)
{
  return (int)(60 * pow(stage, stage * 0.085) + 140);
}

void lvl_simulation(char scn[])
{
  if (strcmp(scn, "lvl_system") == 0)
  {
    int lvl_character[5] = {0, 0, 0, 0, 0};
    int max_all_exp_lvl = 0;
    int boss_stage_exp = 1500;
    int max_exp_stage = 0 + boss_stage_exp;

    ///////// max exp stage
    for (int i = 1; i <= 15; i++)
      max_exp_stage += exp_stage(i);
    max_exp_stage *= 2.75; // 1 for each character played with and .25 to passive characters

    //////// max exp all characters
    /// char 1+2
    for (int i = 1; i <= 20; i++)
    {
      lvl_character[0] += exp_lvl(i);
      lvl_character[1] += exp_lvl(i);
    }

    /// char 3+4
    for (int i = 6; i <= 20; i++)
    {
      lvl_character[2] += exp_lvl(i);
      lvl_character[3] += exp_lvl(i);
    }
    // char 5
    for (int i = 11; i <= 20; i++)
      lvl_character[4] += exp_lvl(i);

    max_all_exp_lvl = lvl_character[0] = lvl_character[1] + lvl_character[2] + lvl_character[3] + lvl_character[4];

    printf("max_exp_stage: %d\nmax_exp_lvl: %d", max_exp_stage, max_all_exp_lvl);
  }
}