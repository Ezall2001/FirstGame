#include "../headers/dev.h"
#include "../headers/logic.h"

void dev_loop(GameObject *G)
{
  calcFPS(&(G->dev));
  set_DeltaTime(&(G->dev));

  if (G->dev.change_character == 1)
    change_character(&(G->logic), &(G->input));

  if (G->dev.spawn_enemy == 1)
    spawn_enemie(&(G->logic), &(G->input), &(G->window));

  if (G->dev.show_outlines == 1)
    set_Outlines_Coords(&(G->logic), &(G->UI.dev_UI));
}

void calcFPS(GameDev *dev)
{
  static int firstFrameBug = 1;
  if (firstFrameBug)
  {
    dev->prevTick = SDL_GetTicks();
    firstFrameBug = 0;
  }

  dev->currTick = SDL_GetTicks();
  dev->frameDelays[dev->frameDelayIndex] = dev->currTick - dev->prevTick;
  dev->prevTick = dev->currTick;

  if (dev->frameDelayCount < 10)
    dev->frameDelayCount++;

  (dev->frameDelayIndex)++;
  dev->frameDelayIndex %= 10;

  dev->frameDelayAvg = 0;
  for (int i = 0; i < dev->frameDelayCount; i++)
    dev->frameDelayAvg += dev->frameDelays[i];

  dev->frameDelayAvg /= (float)dev->frameDelayCount;

  if (dev->frameDelayAvg != 0)
    dev->FPS = 1000 / dev->frameDelayAvg;
  else
    dev->FPS = dev->FPS_cap;
}

void set_DeltaTime(GameDev *dev)
{
  int local_frameDelayIndex = 0;

  if (dev->frameDelayIndex == 0)
    local_frameDelayIndex = dev->frameDelayCount - 1;
  else
    local_frameDelayIndex = dev->frameDelayIndex - 1;

  dev->deltaTime = dev->frameDelays[local_frameDelayIndex] * 0.001;
}

void cap_FPS(GameDev dev)
{
  float frameTime = 1000 / (float)dev.FPS_cap;
  float currFrameDelay = SDL_GetTicks() - dev.currTick;
  if (frameTime > currFrameDelay)
    SDL_Delay(frameTime - currFrameDelay);
}

void change_character(GameLogic *logic, GameInput *input)
{
  static int default_character = 0;
  if (default_character == 0)
  {
    logic->survivors[0].coords = logic->players[0].coords;
    logic->players[0] = logic->survivors[0];

    logic->survivors[1].coords = logic->players[1].coords;
    logic->players[1] = logic->survivors[1];
    default_character = 1;
  }

  for (int i = 0; i < input->num_keys; i++)
  {
    if (input->keys[i] == SDLK_KP_1)
    {
      logic->survivors[0].coords = logic->players[0].coords;
      logic->players[0] = logic->survivors[0];
    }
    else if (input->keys[i] == SDLK_KP_2)
    {
      logic->survivors[1].coords = logic->players[0].coords;
      logic->players[0] = logic->survivors[1];
    }
    else if (input->keys[i] == SDLK_KP_3)
    {
      logic->survivors[2].coords = logic->players[0].coords;
      logic->players[0] = logic->survivors[2];
    }
    else if (input->keys[i] == SDLK_KP_4)
    {
      logic->survivors[3].coords = logic->players[0].coords;
      logic->players[0] = logic->survivors[3];
    }
  }
}

void spawn_enemie(GameLogic *logic, GameInput *input, GameWindow *window)
{
  for (int i = 0; i < input->num_keys; i++)
  {
    if (input->keys[i] == SDLK_F1)
    {
      spawn_Bird(logic, window);
    }
  }
}

void set_Outlines_Coords(GameLogic *logic, DevUI *ui)
{
  ui->outline_num = 0;

  // --- active characters ---
  for (int i = 0; i < 2; i++)
  {

    convert_REAL_SDL(&(ui->outlines[ui->outline_num].coords),
                     logic->players[i].coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     logic->players[i].coords.w,
                     logic->players[i].coords.h);

    ui->outlines[ui->outline_num].color = set_color(52, 235, 140 + (100 * i), 255);

    (ui->outline_num)++;
  }

  // --- enmies ---
  for (int i = 0; i < logic->enemy_num; i++)
  {

    convert_REAL_SDL(&(ui->outlines[ui->outline_num].coords),
                     logic->enemies[i].coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     logic->enemies[i].coords.w,
                     logic->enemies[i].coords.h);

    ui->outlines[ui->outline_num].color = set_color(235, 52, 52, 255);

    (ui->outline_num)++;
  }

  // --- obstacles ---
  for (int i = 0; i < logic->obstacle_num; i++)
  {

    convert_REAL_SDL(&(ui->outlines[ui->outline_num].coords),
                     logic->obstacles[i].coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     logic->obstacles[i].coords.w,
                     logic->obstacles[i].coords.h);

    ui->outlines[ui->outline_num].color = set_color(235, 153, 52, 255);

    (ui->outline_num)++;
  }
}