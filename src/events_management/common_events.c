#include "../headers/event.h"
#include "../headers/logic.h"
#include "../headers/dev.h"

void window_events(SDL_Event *event, GameObject *G)
{

  switch (event->window.event)
  {
  case SDL_WINDOWEVENT_CLOSE:
  {
    G->window.running = 0;
    break;
  }
  case SDL_WINDOWEVENT_SIZE_CHANGED:
  {
    update_Window_Coords(&(G->window));
    update_Menu_Coords(&(G->menuUI), &(G->window));
    break;
  }
  case SDL_WINDOWEVENT_MOVED:
  {
    update_Window_Coords(&(G->window));
    break;
  }

  default:
    break;
  }
}

void mouse_motion_events(SDL_Event *event, GameObject *G)
{
  G->input.mouse_x = event->motion.x;
  G->input.mouse_y = event->motion.y;

  if (G->window.game_scene == 0)
  {
    switch (G->window.menu_scene)
    {
    case 0:
      mouse_Button_Collision(G->menuUI.scene0_UI.scene_buttons, 4, &(G->input));
      break;

    default:
      break;
    }
  }
}

void keyboard_Input(SDL_Event *event, GameInput *input)
{
  if (event->key.keysym.sym == SDLK_RCTRL || event->key.keysym.sym == SDLK_LCTRL)
    input->ctrl = 1;
  else
  {
    input->keys[input->num_keys] = event->key.keysym.sym;
    (input->num_keys)++;
  }
}