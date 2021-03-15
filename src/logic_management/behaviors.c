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

    ///TODO: check for player

    max_spawn++;
    if (max_spawn == 10000)
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
  float distance = get_distance(src, dst);

  if (distance == 0)
  {
    return 0;
  }

  float a_sin = asin((dst.y - src.y) / distance);
  float a_cos = acos((dst.x - src.x) / distance);

  if (isnan(a_sin))
    a_sin = 0;

  if (isnan(a_cos))
    a_cos = 0;

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
