#include "../headers/init.h"

//////////////////////////////////////////////////
//////////////// --- survivors ---
//////////////////////////////////////////////////
void init_common_survivors(GameLogic *logic)
{
  static int first_time = 1;
  for (int i = 0; i < 4; i++)
  {
    if (first_time == 1)
    {
      logic->survivors[i].xp = 0;
      logic->survivors[i].lvl = 0;
      first_time = 0;
    }

    for (int j = 0; j < 4; j++)
    {
      logic->survivors[i].checkpoints[j].w = 10;
      logic->survivors[i].checkpoints[j].h = 10;
      logic->survivors[i].checkpoints[j].x = logic->MAP_Map_Coords.w;
      logic->survivors[i].checkpoints[j].y = logic->MAP_Map_Coords.h;

      logic->players[i].collision_sides[j].collision_num = 0;
    }

    logic->survivors[i].id = 0;
    logic->survivors[i].action_ang = 0;
    logic->survivors[i].distance_walked = 0;
    logic->survivors[i].is_spawned = 0;
  }
}

void init_James(GameLogic *logic)
{
  // misc
  strcpy(logic->survivors[0].name, "JAMES");

  // properties
  logic->survivors[0].speed = 300;

  // ranges
  logic->survivors[0].dmg_range = 700;

  // coords
  logic->survivors[0].coords.w = 70;
  logic->survivors[0].coords.h = 100;
  logic->survivors[0].coords.x = 0;
  logic->survivors[0].coords.y = 0;
}

void init_Marie(GameLogic *logic)
{
  // misc
  strcpy(logic->survivors[1].name, "MARIE");

  // ranges
  logic->survivors[1].dmg_range = 500;

  // coords
  logic->survivors[1].coords.w = 60;
  logic->survivors[1].coords.h = 80;
  logic->survivors[1].coords.x = 0;
  logic->survivors[1].coords.y = 0;

  // properties
  logic->survivors[1].speed = 6;
}

//////////////////////////////////////////////////
//////////////// --- enemies ---
//////////////////////////////////////////////////

void init_common_enemies(GameLogic *logic, int stage)
{
  for (int i = 0; i < 10; i++)
  {
    // misc
    logic->enemy_types[i].id = 0;
    logic->enemy_types[i].herd_id = 0;
    logic->enemy_types[i].num_spawned = 0;

    // propeties
    logic->enemy_types[i].shield = 0;
    logic->enemy_types[i].poison_dmg = 0;
    logic->enemy_types[i].fire_dmg = 0;
    logic->enemy_types[i].poison_applied = 0;
    logic->enemy_types[i].fire_applied = 0;
    logic->enemy_types[i].poison_duration = 0;
    logic->enemy_types[i].fire_duration = 0;

    // coords
    logic->enemy_types[i].coords.x = 0;
    logic->enemy_types[i].coords.y = 0;

    for (int j = 0; j < 4; j++)
    {
      logic->enemy_types[i].checkpoints[j].w = 10;
      logic->enemy_types[i].checkpoints[j].h = 10;
      logic->enemy_types[i].checkpoints[j].x = logic->MAP_Map_Coords.w;
      logic->enemy_types[i].checkpoints[j].y = logic->MAP_Map_Coords.h;

      logic->enemies[i].collision_sides[j].collision_num = 0;
    }

    for (int j = 0; j < 2; j++)
      logic->enemy_types[i].attack_ang_offset[j] = 0;

    logic->enemy_types[i].action_ang = 0;

    // ranges
    logic->enemy_types[i].roam_range.w = 0;
    logic->enemy_types[i].detection_range = 0;
    logic->enemy_types[i].escape_range = 0;

    // states
    logic->enemy_types[i].is_alerted = 1;
    logic->enemy_types[i].is_moving = 1;
    logic->enemy_types[i].is_attacking = 0;
    logic->enemy_types[i].is_aiming = 0;
    logic->enemy_types[i].is_dead = 0;

    // timers
    logic->enemy_types[i].start_count = 0;
    logic->enemy_types[i].delay = 0;
    logic->enemy_types[i].init_action = 0;
  }
}

void init_bird(GameLogic *logic, int stage)
{
  ///TODO: finish init bird

  // misc
  strcpy(logic->enemy_types[0].name, "BIRD");
  logic->enemy_types[0].give_xp = 70;
  logic->enemy_types[0].give_coin = 2;

  // properties
  logic->enemy_types[0].hp = 30;
  logic->enemy_types[0].speed = 600;
  logic->enemy_types[0].dmg = 15;

  // coords
  logic->enemy_types[0].coords.w = 50;
  logic->enemy_types[0].coords.h = 50;
  logic->enemy_types[0].attack_ang_offset[0] = 70;
  logic->enemy_types[0].attack_ang_offset[1] = 70;

  // ranges
  logic->enemy_types[0].avoid_obstacle_range = 500;
  logic->enemy_types[0].attack_range = 100;
  logic->enemy_types[0].dmg_range = 150;
}

void init_sheep(GameLogic *logic, int stage)
{
  ///TODO: finish init sheep

  // misc
  strcpy(logic->enemy_types[1].name, "SHEEP");
  logic->enemy_types[1].give_xp = 150;
  logic->enemy_types[1].give_coin = 5;

  // properties
  logic->enemy_types[1].hp = 200;
  logic->enemy_types[1].speed = 130;
  logic->enemy_types[1].dmg = 60;

  // coords
  logic->enemy_types[1].coords.w = 150;
  logic->enemy_types[1].coords.h = 130;

  // ranges
  logic->enemy_types[1].roam_range.w = 700;
  logic->enemy_types[1].detection_range = 400;
  logic->enemy_types[1].avoid_obstacle_range = 750;
  logic->enemy_types[1].attack_range = 600;
  logic->enemy_types[1].dmg_range = 700;

  // states
  logic->enemy_types[1].is_alerted = 0;

  // timers
  logic->enemy_types[1].start_count = SDL_GetTicks();
  logic->enemy_types[1].delay = 4500;
  logic->enemy_types[1].init_action = 1;
}

void init_common_obstacles(GameLogic *logic, int stage)
{
  ///TODO: finish initiating obstacles
  for (int j = 0; j < 4; j++)
  {
    logic->obstacle_types[0].checkpoints[j].w = 10;
    logic->obstacle_types[0].checkpoints[j].h = 10;
    logic->obstacle_types[0].checkpoints[j].x = logic->MAP_Map_Coords.w;
    logic->obstacle_types[0].checkpoints[j].y = logic->MAP_Map_Coords.h;

    logic->obstacle_types[0].collision_sides[j].collision_num = 0;
  }

  strcpy(logic->obstacle_types[0].name, "BOX");
  logic->obstacle_types[0].id = 0;
  logic->obstacle_types[0].num_spawned = 0;
}