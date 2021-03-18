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
  int collision_type[5]; // 0:none 1:player 2:enemie 3:obstacle
  int collider_id[5];
  int collision_num;
} Collision_side;

typedef struct
{
  char name[50];
  int id;
  int num_spawned;
  float damage;
  float fire_damage;
  float poison_damage;
  real_Rect coords;
  real_Rect checkpoints[4];          // 0:top-left 1:top-right 2:bottom-right 3:bottom-left
  Collision_side collision_sides[4]; // 0:top 1:right 2:bottom 3:left

} Obstacle;

typedef struct
{
  // misc
  char name[50];
  int id;
  int xp, lvl, coins;
  float distance_walked;
  float dmg_delt;

  // properties
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
  real_Rect checkpoints[4]; // 0:top-left 1:top-right 2:bottom-right 3:bottom-left
  real_Rect AI_anchor;
  float action_ang;
  float attack_ang_offset[2];
  Collision_side collision_sides[4]; // 0:top 1:right 2:bottom 3:left

  // ranges
  float dmg_range;

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
  int id;
  int herd_id;
  int num_spawned;
  int give_xp;
  int give_coin;

  // properties
  float hp, shield, speed;
  float dmg, fire_dmg, poison_dmg;
  float poison_applied, fire_applied;
  int poison_duration, fire_duration;

  // coords
  real_Rect coords;
  real_Rect checkpoints[4]; // 0:top-left 1:top-right 2:bottom-right 3:bottom-left
  float attack_ang_offset[2];
  float action_ang;
  Collision_side collision_sides[4]; // 0:top 1:right 2:bottom 3:left

  // ranges
  real_Rect roam_range;
  float detection_range;
  float avoid_obstacle_range;
  float attack_range;
  float dmg_range;
  float escape_range;

  // states
  int is_alerted; // 1: alerted - 2: being alerted
  int is_moving;
  int is_attacking;
  int is_aiming;
  int is_dead;

  // timers
  int start_count;
  int delay;
  int init_action;

} Enemie;

#endif