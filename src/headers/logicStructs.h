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
  ///TODO: redo ability struct
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
  // misc
  char name[50];
  int xp, lvl, coins;

  // stats
  float hp, shield, mp, speed;
  float dmg, burn_dmg, poison_dmg;
  float poison_applied, fire_applied;
  int poison_duration, fire_duration, stun_duration;
  float crit_chance, crit_damage;
  int reload_Time, magazine;

  // equipement
  int headset_tier;
  int footwear_tier;
  int armor_tier;

  // abilities
  Ability active_a;
  Ability passive_a;

  // coords
  real_Rect coords;
  real_Rect checkpoints[4];
  real_Rect AI_anchor;
  float action_ang;
  float attack_ang_offset[2];

  // ranges
  float attack_range;

  // states
  int is_spawned;
  int is_moving;
  int is_attacking;
  int is_dead;

} Character;

typedef struct
{
  // misc
  char name[50];
  int herd_id;
  int give_xp;
  int give_coin;

  // states
  float hp, shield, speed;
  float dmg, burn_dmg, poison_dmg;
  float poison_applied, fire_applied;
  int poison_duration, fire_duration;

  // coords
  real_Rect coords;
  real_Rect checkpoints[4];
  float attack_ang_offset[2];
  float action_ang;

  // ranges
  float obstacle_range;
  float attack_range;
  float dmg_range;
  float run_from_range;
  float roam_range;
  float detection_range;

  // states
  int is_attacking;
  int is_moving;
  int is_dead;
  int is_aiming;
  int is_alerted;

} Enemie;

#endif