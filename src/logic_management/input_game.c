#include "../headers/logic.h"

void keyboard_Player_Input(GameLogic *logic, GameWindow *window, GameInput *input)
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
}