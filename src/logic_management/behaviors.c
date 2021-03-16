#include "../headers/logic.h"

void spawn_Players(GameLogic *logic, GameWindow *window)
{

  // main player spawn coords
  logic->players[0].coords.x = get_Random_Number(&(window->r), -(logic->MAP_Map_Coords.w) / 3, (logic->MAP_Map_Coords.w) / 3);
  logic->players[0].coords.y = get_Random_Number(&(window->r), -(logic->MAP_Map_Coords.h) / 3, (logic->MAP_Map_Coords.h) / 3);

  // secondary player spawn coords
  logic->players[1].coords.x = logic->players[0].coords.x + logic->players[0].coords.w + 20;
  logic->players[1].coords.y = logic->players[0].coords.y;
}

void spawn_on_edge(GameLogic *logic, GameWindow *window, int enemy_type)
{
  logic->enemies[logic->enemy_num] = logic->enemy_types[enemy_type];

  int exclude_side_vertical = 0;   // 0: none 1:top 3:bottom
  int exclude_side_horizontal = 0; // 0: none 2:right 4:left
  int side = 0;
  float side_offset = logic->MAP_Map_Coords.h * 0.15;

  if (logic->players[0].coords.y > (logic->MAP_Map_Coords.h / 2) - side_offset)
    exclude_side_vertical = 1;
  else if (logic->players[0].coords.y < (-logic->MAP_Map_Coords.h / 2) + side_offset)
    exclude_side_vertical = 3;

  if (logic->players[0].coords.x > (logic->MAP_Map_Coords.w / 2) - side_offset)
    exclude_side_horizontal = 2;
  else if (logic->players[0].coords.x < (-logic->MAP_Map_Coords.h / 2) + side_offset)
    exclude_side_horizontal = 4;

  do
  {
    side = get_Random_Number(&(window->r), 1, 4);
  } while (side == exclude_side_horizontal || side == exclude_side_vertical);

  if (side == 1)
  {
    logic->enemies[logic->enemy_num].coords.x = get_Random_Number(&(window->r), -logic->MAP_Map_Coords.w / 2, logic->MAP_Map_Coords.w / 2);
    logic->enemies[logic->enemy_num].coords.y = logic->MAP_Map_Coords.h / 2 + logic->enemies[logic->enemy_num].coords.h / 2;
  }
  else if (side == 3)
  {
    logic->enemies[logic->enemy_num].coords.x = get_Random_Number(&(window->r), -logic->MAP_Map_Coords.w / 2, logic->MAP_Map_Coords.w / 2);
    logic->enemies[logic->enemy_num].coords.y = -logic->MAP_Map_Coords.h / 2 - logic->enemies[logic->enemy_num].coords.h / 2;
  }
  else if (side == 2)
  {
    logic->enemies[logic->enemy_num].coords.x = logic->MAP_Map_Coords.w / 2 + logic->enemies[logic->enemy_num].coords.w / 2;
    logic->enemies[logic->enemy_num].coords.y = get_Random_Number(&(window->r), -logic->MAP_Map_Coords.h / 2, logic->MAP_Map_Coords.h / 2);
  }
  else if (side == 4)
  {
    logic->enemies[logic->enemy_num].coords.x = -logic->MAP_Map_Coords.w / 2 - logic->enemies[logic->enemy_num].coords.w / 2;
    logic->enemies[logic->enemy_num].coords.y = get_Random_Number(&(window->r), -logic->MAP_Map_Coords.h / 2, logic->MAP_Map_Coords.h / 2);
  }

  (logic->enemy_types[0].num_spawned)++;
  (logic->enemy_num)++;
}

void spawn_herd(GameLogic *logic, GameWindow *window, int enemy_type, int enemy_num)
{
  // herd coords
  float y_herd = 0, x_herd = 0;

  float x_limit1 = -logic->MAP_Map_Coords.w / 2 + logic->enemy_types[enemy_type].roam_range.w;
  float x_limit2 = logic->MAP_Map_Coords.w / 2 - logic->enemy_types[enemy_type].roam_range.w;

  float y_limit1 = -logic->MAP_Map_Coords.h / 2 + logic->enemy_types[enemy_type].roam_range.w;
  float y_limit2 = logic->MAP_Map_Coords.h / 2 - logic->enemy_types[enemy_type].roam_range.w;

  int collision = 0;
  float herd_offset = logic->enemy_types[enemy_type].roam_range.w;
  int max_spawn = 0;
  do
  {
    collision = 0;

    x_herd = get_Random_Number(&(window->r), x_limit1, x_limit2);
    y_herd = get_Random_Number(&(window->r), y_limit1, y_limit2);
    real_Rect herd_coords = {x_herd, y_herd, 0, 0};

    // check for other herds
    for (int i = 0; i < logic->enemy_num; i++)
    {
      if (strcmp(logic->enemies[i].name, "SHEEP") == 0)
      {
        float distance = get_distance(herd_coords, logic->enemies[i].roam_range);
        if (distance < logic->enemies[i].roam_range.w * 2 + herd_offset)
        {
          collision = 1;
          i = logic->enemy_num;
        }
      }
    }

    for (int i = 0; i < 2; i++)
    {
      float distance = get_distance(herd_coords, logic->players[i].coords);
      if (distance < logic->enemies[i].roam_range.w * 2 + herd_offset)
      {
        collision = 1;
        i = 2;
      }
    }

    max_spawn++;
    if (max_spawn == 100000)
      break;

  } while (collision == 1);

  if (max_spawn < 10000)
  {
    logic->enemy_types[enemy_type].roam_range.x = x_herd;
    logic->enemy_types[enemy_type].roam_range.y = y_herd;

    (logic->enemy_types[enemy_type].num_spawned)++;
    logic->enemy_types[enemy_type].herd_id = logic->enemy_types[enemy_type].num_spawned;

    // indiv coords
    for (int i = 0; i < enemy_num; i++)
    {
      float ang_herd = get_Random_Number(&(window->r), 0, 360);
      int distance_herd = get_Random_Number(&(window->r), 0, logic->enemy_types[enemy_type].roam_range.w);

      logic->enemy_types[enemy_type].coords.x = x_herd + cos(ang_herd) * distance_herd;
      logic->enemy_types[enemy_type].coords.y = y_herd + sin(ang_herd) * distance_herd;

      logic->enemies[logic->enemy_num] = logic->enemy_types[enemy_type];
      (logic->enemy_num)++;
    }
  }
}
void spawn_Obstacle(GameLogic *logic, GameWindow *window)
{

  (logic->obstacle_num)++;
}

void roam(Enemie *enemy, GameWindow *window, GameDev *dev)
{
  if (enemy->is_moving == 1)
  {
    if (enemy->init_action == 1)
    {
      // move
      move(enemy->speed, enemy->action_ang, &(enemy->coords), enemy->checkpoints, dev->deltaTime);

      if (get_distance(enemy->coords, enemy->roam_range) > enemy->roam_range.w)
      {
        float range_ang = get_ang(enemy->roam_range, enemy->coords);
        move(enemy->speed, range_ang + 180, &(enemy->coords), enemy->checkpoints, dev->deltaTime);
        enemy->action_ang = get_Random_Number(&(window->r), range_ang + 180 - 45, enemy->action_ang + 180 + 45);

        enemy->delay -= 1000;
      }

      if (SDL_GetTicks() - enemy->start_count > enemy->delay)
      {
        enemy->delay = 0;
        enemy->start_count = 0;
        enemy->init_action = 0;
        enemy->is_moving = 0;
      }
    }
    else if (enemy->init_action == 0)
    {
      enemy->action_ang = get_Random_Number(&(window->r), 0, 360);
      enemy->start_count = SDL_GetTicks();
      enemy->delay = get_Random_Number(&(window->r), 5000, 7000);
      enemy->init_action = 1;
    }
  }
  else if (enemy->is_moving == 0)
  {
    // wait
    if (enemy->start_count != 0)
    {
      if (SDL_GetTicks() - enemy->start_count > enemy->delay)
      {
        enemy->is_moving = 1;
        enemy->delay = 0;
        enemy->start_count = 0;
      }
    }
    else if (enemy->start_count == 0)
    {
      enemy->start_count = SDL_GetTicks();
      enemy->delay = get_Random_Number(&(window->r), 5000, 15000);
    }
  }
}

void alert_herd(GameLogic *logic, Enemie *enemy, float new_speed)
{
  // detection of the first enemy
  if ((get_distance(enemy->coords, logic->players[0].coords) < enemy->detection_range && enemy->is_alerted == 0) || enemy->is_alerted == 2)
  {

    // detection of the other enemies of the same herd
    if (enemy->is_alerted == 0)
    {
      for (int i = 0; i < logic->enemy_num; i++)
      {
        if (strcmp(logic->enemies[i].name, enemy->name) == 0 && logic->enemies[i].herd_id == enemy->herd_id)
        {
          logic->enemies[i].is_alerted = 2;
          logic->enemies[i].is_moving = 0;
          logic->enemies[i].speed = new_speed;
        }
      }

      enemy->start_count = 0;
    }

    // delay for animation
    if (enemy->start_count != 0)
    {
      if (SDL_GetTicks() - enemy->start_count > enemy->delay)
      {
        for (int i = 0; i < logic->enemy_num; i++)
        {
          if (strcmp(logic->enemies[i].name, enemy->name) == 0 && logic->enemies[i].herd_id == enemy->herd_id)
          {
            logic->enemies[i].is_moving = 1;
            logic->enemies[i].is_alerted = 1;
          }
        }
      }
      else
      {
        // aiming
        for (int i = 0; i < logic->enemy_num; i++)
        {
          if (strcmp(logic->enemies[i].name, enemy->name) == 0 && logic->enemies[i].herd_id == enemy->herd_id)
          {
            logic->enemies[i].action_ang = get_ang(logic->enemies[i].coords, logic->players[0].coords);
          }
        }
      }
    }
    else if (enemy->start_count == 0)
    {
      enemy->delay = 1000;
      enemy->start_count = SDL_GetTicks();
    }
  }
}

void move(float speed, float d, real_Rect *main_coords, real_Rect checkpoints[], float deltaTime)
{
  // main coords
  float r = convert_Degree_Radiant(d);
  main_coords->x += cos(r) * speed * deltaTime;
  main_coords->y += sin(r) * speed * deltaTime;

  // checkpoints
  real_Rect checkpoint = {0, 0, 10, 10};
  for (int i = 0; i < 4; i++)
  {
    checkpoint.x = main_coords->x + ((main_coords->w / 2) - 1) * pow(-1, i + 1);
    checkpoint.y = main_coords->y + ((main_coords->h / 2) - 1) * pow(-1, i / 2);
    checkpoints[i] = checkpoint;
  }
}

float get_ang(real_Rect src, real_Rect dst)
{
  float r_ang = 0;
  float distance = get_distance(src, dst);

  if (distance == 0)
  {
    return 0;
  }

  float a_sin = asin((dst.y - src.y) / distance);
  float a_cos = acos((dst.x - src.x) / distance);

  if (isnan(a_sin))
    a_sin = M_PI / 4;

  if (isnan(a_cos))
    a_cos = M_PI / 4;

  if (a_sin >= 0)
  {
    r_ang = a_cos;
  }
  else
  {
    r_ang = (M_PI * 2) - a_cos;
  }

  return convert_Radiant_Degree(r_ang);
}
