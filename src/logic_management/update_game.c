#include "../headers/logic.h"

void spawn_Players(GameLogic *logic, GameWindow *window)
{

  // main player spawn coords
  logic->players[0].coords.w = 100;
  logic->players[0].coords.h = 100;
  logic->players[0].coords.x = get_Random_Number(&(window->r), -(logic->MAP_Map_Coords.w) / 3, (logic->MAP_Map_Coords.w) / 3);
  logic->players[0].coords.y = get_Random_Number(&(window->r), -(logic->MAP_Map_Coords.h) / 3, (logic->MAP_Map_Coords.h) / 3);

  // secondary player spawn coords
  logic->players[1].coords.w = 100;
  logic->players[1].coords.h = 100;
  logic->players[1].coords.x = logic->players[0].coords.x + logic->players[0].coords.w + 20;
  logic->players[1].coords.y = logic->players[0].coords.y;
}

void spawn_Bird(GameLogic *logic, GameWindow *window)
{
  ///TODO: spawn_Bird
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

void update_Cam_Coords(GameLogic *logic, GameWindow *window, In_Game_UI *ui)
{
  // REAL system
  logic->cam_Coords.w = 2560;
  logic->cam_Coords.h = logic->cam_Coords.w * (float)9 / 16;
  logic->cam_Coords.x = logic->players[0].coords.x - logic->cam_Coords.w / 2;
  logic->cam_Coords.y = logic->players[0].coords.y + logic->cam_Coords.h / 2;

  if (logic->cam_Coords.x + logic->cam_Coords.w > logic->MAP_Map_Coords.w / 2)
  {
    logic->cam_Coords.x = (logic->MAP_Map_Coords.w / 2) - logic->cam_Coords.w;
  }
  else if (logic->cam_Coords.x < -logic->MAP_Map_Coords.w / 2)
  {
    logic->cam_Coords.x = -logic->MAP_Map_Coords.w / 2;
  }

  if (logic->cam_Coords.y - logic->cam_Coords.h < -logic->MAP_Map_Coords.h / 2)
  {
    logic->cam_Coords.y = (-logic->MAP_Map_Coords.h / 2) + logic->cam_Coords.h;
  }
  else if (logic->cam_Coords.y > logic->MAP_Map_Coords.h / 2)
  {
    logic->cam_Coords.y = logic->MAP_Map_Coords.h / 2;
  }

  // MAP system
  logic->MAP_Cam_Coords.w = logic->cam_Coords.w;
  logic->MAP_Cam_Coords.h = logic->cam_Coords.h;
  logic->MAP_Cam_Coords.x = logic->MAP_Origin_Coords.x + logic->cam_Coords.x;
  logic->MAP_Cam_Coords.y = logic->MAP_Origin_Coords.y - logic->cam_Coords.y;

  // SDL system
  ui->src_Map_Coords.x = logic->MAP_Cam_Coords.x;
  ui->src_Map_Coords.y = logic->MAP_Cam_Coords.y;
  ui->src_Map_Coords.w = logic->MAP_Cam_Coords.w;
  ui->src_Map_Coords.h = logic->MAP_Cam_Coords.h;

  // cam ratio
  logic->CAM_REAL_Cam_w_Ratio = (float)window->w / logic->cam_Coords.w;
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
  ///TODO: test this in the real coords
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
