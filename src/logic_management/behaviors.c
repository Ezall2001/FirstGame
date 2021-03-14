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

  int exclude_side = 0; // 0: none 1:top 2:right 3:bottom 4:left
  int side = 0;
  float side_offset = logic->MAP_Map_Coords.h * 0.1;

  coords_log(logic->players[0].coords.x, logic->players[0].coords.y, logic->players[0].coords.w, logic->players[0].coords.h);
  if (logic->players[0].coords.y > (logic->MAP_Map_Coords.h / 2) - side_offset)
  {
    exclude_side = 1;
    printf("top");
  }
  else if (logic->players[0].coords.y < (-logic->MAP_Map_Coords.h / 2) + side_offset)
  {
    exclude_side = 3;
    printf("bottom");
  }
  else if (logic->players[0].coords.x > logic->MAP_Map_Coords.w - side_offset)
  {
    exclude_side = 2;
    printf("right");
  }
  else if (logic->players[0].coords.x < -logic->MAP_Map_Coords.h + side_offset)
  {
    exclude_side = 4;
    printf("left");
  }
  do
  {
    side = get_Random_Number(&(window->r), 1, 4);
  } while (side == exclude_side);

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
  int x_limit1 = -logic->MAP_Map_Coords.w / 2 + logic->enemy_types[enemy_type].roam_range.w;
  int x_limit2 = logic->MAP_Map_Coords.w / 2 - logic->enemy_types[enemy_type].roam_range.w;
  int x_herd = get_Random_Number(&(window->r), x_limit1, x_limit2);

  int y_limit1 = -logic->MAP_Map_Coords.h / 2 + logic->enemy_types[enemy_type].roam_range.w;
  int y_limit2 = logic->MAP_Map_Coords.h / 2 - logic->enemy_types[enemy_type].roam_range.w;
  int y_herd = get_Random_Number(&(window->r), y_limit1, y_limit2);

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

void spawn_Obstacle(GameLogic *logic, GameWindow *window)
{

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
