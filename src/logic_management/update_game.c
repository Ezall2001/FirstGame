#include "../headers/logic.h"
#include "../headers/dev.h"

void spawn_Player(GameLogic *logic, GameWindow *window)
{

  // main player spawn coords
  logic->James.coords.w = 100;
  logic->James.coords.h = 100;
  logic->James.coords.x = get_Random_Number(&(window->r), -(logic->MAP_Map_Coords.w) / 3, (logic->MAP_Map_Coords.w) / 3);
  logic->James.coords.y = get_Random_Number(&(window->r), -(logic->MAP_Map_Coords.h) / 3, (logic->MAP_Map_Coords.h) / 3);
}

void update_Cam_Coords(GameLogic *logic, GameWindow *window, In_Game_UI *ui)
{
  // REAL system
  logic->cam_Coords.w = 2560;
  logic->cam_Coords.h = logic->cam_Coords.w * (float)9 / 16;
  logic->cam_Coords.x = logic->James.coords.x - logic->cam_Coords.w / 2;
  logic->cam_Coords.y = logic->James.coords.y + logic->cam_Coords.h / 2;

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

void update_Player_Coords(GameLogic *logic, GameWindow *window, GameInput *input)
{
  ///TODO: make this with the angles
  if (input->keyboard_state[SDL_SCANCODE_W] == 1)
  {
    logic->James.coords.y += 5;
  }
  else if (input->keyboard_state[SDL_SCANCODE_A] == 1)
  {
    logic->James.coords.x -= 5;
  }
  else if (input->keyboard_state[SDL_SCANCODE_D] == 1)
  {
    logic->James.coords.x += 5;
  }
  else if (input->keyboard_state[SDL_SCANCODE_S] == 1)
  {
    logic->James.coords.y -= 5;
  }

  // coords_log(logic->James.coords.x, logic->James.coords.y, logic->James.coords.w, logic->James.coords.h);
  // coords_log(logic->James.coords.x, logic->James.coords.y, logic->James.coords.w, logic->James.coords.h);
}
