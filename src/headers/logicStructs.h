#ifndef LOGICSTRUCTS_H_DEFINED
#define LOGICSTRUCTS_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "mtwister.h"

typedef struct
{
  float x;
  float y;
  float h;
  float w;
} real_Rect;

typedef struct
{
  ///TODO: redo this
} Ability;

typedef struct
{
  float damage;
  float fire_damage;
  float poison_damage;
  real_Rect coords;
} Obstacle;

typedef struct
{
  ///TODO: init all of this
  char name[50];
  float hp, mp, speed;
  float damage, burn_damage, poison_damage;
  float crit_chance, crit_damage;
  float exp;
  int lvl;
  int reload_Time, magazine;
  Ability active_a;
  Ability passive_a;
  real_Rect coords;

  // states
  int moving;
  float moving_ang;

} Character;

#endif