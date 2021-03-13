#include "../headers/logic.h"

void main_player_Behavior(GameLogic *logic, GameWindow *window, GameDev *dev, GameInput *input)
{
  if (logic->players[0].is_spawned == 0)
  {
    spawn_Players(logic, window);
    logic->players[0].is_spawned = 1;
  }

  keyboard_Player_Input(logic, window, input);

  if (logic->players[0].is_moving == 1)
  {
    move(logic->players[0].speed, logic->players[0].action_ang, &(logic->players[0].coords));
    logic->players[0].distance_walked += logic->players[0].speed * dev->deltaTime;
    logic->players[1].distance_walked += logic->players[1].speed * dev->deltaTime;
    logic->players[0].is_moving = 0;
  }
}

void bird_Behavior(GameLogic *logic, GameWindow *window, GameDev *dev)
{
  float target_distance_walked = 150; ///TODO: make it dependent on stage

  if (logic->players[0].distance_walked - (logic->enemy_types[0].num_spawned * target_distance_walked) > target_distance_walked)
  {
    spawn_on_edge(logic, window, 0);
  }

  for (int i = 0; i < logic->enemy_num; i++)
  {
    if (strcmp(logic->enemies[i].name, "BIRD") == 0)
    {
      logic->enemies[i].action_ang = get_ang(logic->enemies[i].coords, logic->players[0].coords);
      move(logic->enemies[i].speed, logic->enemies[i].action_ang, &(logic->enemies[i].coords));
    }
  }
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