#include "../headers/logic.h"

void move_Input(GameLogic *logic, GameWindow *window, GameInput *input)
{

  if (input->keyboard_state[SDL_SCANCODE_W] == 1 && input->keyboard_state[SDL_SCANCODE_A] == 1)
  {
    logic->players[0].action_ang = 135;
    logic->players[0].is_moving = 1;
  }
  else if (input->keyboard_state[SDL_SCANCODE_W] == 1 && input->keyboard_state[SDL_SCANCODE_D] == 1)
  {
    logic->players[0].action_ang = 45;
    logic->players[0].is_moving = 1;
  }
  else if (input->keyboard_state[SDL_SCANCODE_S] == 1 && input->keyboard_state[SDL_SCANCODE_A] == 1)
  {
    logic->players[0].action_ang = 225;
    logic->players[0].is_moving = 1;
  }
  else if (input->keyboard_state[SDL_SCANCODE_S] == 1 && input->keyboard_state[SDL_SCANCODE_D] == 1)
  {
    logic->players[0].action_ang = 315;
    logic->players[0].is_moving = 1;
  }
  else if (input->keyboard_state[SDL_SCANCODE_W] == 1)
  {
    logic->players[0].action_ang = 90;
    logic->players[0].is_moving = 1;
  }
  else if (input->keyboard_state[SDL_SCANCODE_S] == 1)
  {
    logic->players[0].action_ang = 270;
    logic->players[0].is_moving = 1;
  }
  else if (input->keyboard_state[SDL_SCANCODE_A] == 1)
  {
    logic->players[0].action_ang = 180;
    logic->players[0].is_moving = 1;
  }
  else if (input->keyboard_state[SDL_SCANCODE_D] == 1)
  {
    logic->players[0].action_ang = 0;
    logic->players[0].is_moving = 1;
  }
  else
  {
    logic->players[0].is_moving = 0;
  }
}

void aim_Input(GameLogic *logic, GameWindow *window, GameInput *input)
{
  real_Rect mouse_input = {0, 0, 0, 0};
  mouse_input.x = logic->players[0].coords.x - logic->cam_Coords.w / 2 + input->mouse_x * 1 / logic->CAM_REAL_Cam_w_Ratio;
  mouse_input.y = logic->players[0].coords.y + logic->cam_Coords.h / 2 - input->mouse_y * 1 / logic->CAM_REAL_Cam_w_Ratio;

  float angle = get_ang(logic->players[0].coords, mouse_input);
  logic->players[0].action_ang = angle;
}