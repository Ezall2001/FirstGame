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
  ///TODO: finish spawn
  logic->enemies[logic->enemy_num] = logic->enemy_types[enemy_type];

  logic->enemies[logic->enemy_num].coords.x = 50;
  logic->enemies[logic->enemy_num].coords.y = 50;

  (logic->enemy_types[0].num_spawned)++;
  (logic->enemy_num)++;
}

void spawn_Obstacle(GameLogic *logic, GameWindow *window)
{
  ///TODO: redo this
  logic->obstacles[logic->obstacle_num].coords.x = 0;
  logic->obstacles[logic->obstacle_num].coords.y = 0;
  logic->obstacles[logic->obstacle_num].coords.w = 200;
  logic->obstacles[logic->obstacle_num].coords.h = 200;

  (logic->obstacle_num)++;
}

void move(float speed, float d, real_Rect *coords)
{
  ///TODO: multiply speed by delta and w_ratio
  float r = convert_Degree_Radiant(d);
  coords->x += cos(r) * speed;
  coords->y += sin(r) * speed;
}

float get_ang(real_Rect src, real_Rect dst)
{
  float r_ang = 0;
  float distance = sqrt(pow(dst.x - src.x, 2) + pow(dst.y - src.y, 2));
  float a_sin = asin((dst.y - src.y) / distance);
  float a_cos = acos((dst.x - src.x) / distance);
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
