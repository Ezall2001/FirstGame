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
  ///TODO: refactor this
  ui->outline_num = 0;

  // --- active characters ---
  for (int i = 0; i < 2; i++)
  {
    // coords
    ui->outlines[ui->outline_num].coords.w = logic->players[i].coords.w * logic->CAM_REAL_Cam_w_Ratio;
    ui->outlines[ui->outline_num].coords.h = logic->players[i].coords.h * logic->CAM_REAL_Cam_w_Ratio;
    ui->outlines[ui->outline_num].coords.x = (logic->players[i].coords.x - logic->cam_Coords.x - logic->players[i].coords.w / 2) * logic->CAM_REAL_Cam_w_Ratio;
    ui->outlines[ui->outline_num].coords.y = (logic->cam_Coords.y - logic->players[i].coords.y - logic->players[i].coords.h / 2) * logic->CAM_REAL_Cam_w_Ratio;

    // color
    ui->outlines[ui->outline_num].color.r = 52;
    ui->outlines[ui->outline_num].color.g = 235;
    ui->outlines[ui->outline_num].color.b = 140 + (100 * i);
    ui->outlines[ui->outline_num].color.a = 255;

    (ui->outline_num)++;
  }

  // --- enmies ---
  for (int i = 0; i < logic->enemy_num; i++)
  {
    // coords
    ui->outlines[ui->outline_num].coords.w = logic->enemies[i].coords.w * logic->CAM_REAL_Cam_w_Ratio;
    ui->outlines[ui->outline_num].coords.h = logic->enemies[i].coords.h * logic->CAM_REAL_Cam_w_Ratio;
    ui->outlines[ui->outline_num].coords.x = (logic->enemies[i].coords.x - logic->cam_Coords.x - logic->enemies[i].coords.w / 2) * logic->CAM_REAL_Cam_w_Ratio;
    ui->outlines[ui->outline_num].coords.y = (logic->cam_Coords.y - logic->enemies[i].coords.y - logic->enemies[i].coords.h / 2) * logic->CAM_REAL_Cam_w_Ratio;

    // color
    ui->outlines[ui->outline_num].color.r = 235;
    ui->outlines[ui->outline_num].color.g = 52;
    ui->outlines[ui->outline_num].color.b = 52;
    ui->outlines[ui->outline_num].color.a = 255;

    (ui->outline_num)++;
  }

  // --- obstacles ---
  for (int i = 0; i < logic->obstacle_num; i++)
  {
    // coords
    ui->outlines[ui->outline_num].coords.w = logic->obstacles[i].coords.w * logic->CAM_REAL_Cam_w_Ratio;
    ui->outlines[ui->outline_num].coords.h = logic->obstacles[i].coords.h * logic->CAM_REAL_Cam_w_Ratio;
    ui->outlines[ui->outline_num].coords.x = (logic->obstacles[i].coords.x - logic->cam_Coords.x - logic->obstacles[i].coords.w / 2) * logic->CAM_REAL_Cam_w_Ratio;
    ui->outlines[ui->outline_num].coords.y = (logic->cam_Coords.y - logic->obstacles[i].coords.y - logic->obstacles[i].coords.h / 2) * logic->CAM_REAL_Cam_w_Ratio;

    // color
    ui->outlines[ui->outline_num].color.r = 235;
    ui->outlines[ui->outline_num].color.g = 153;
    ui->outlines[ui->outline_num].color.b = 52;
    ui->outlines[ui->outline_num].color.a = 255;
    (ui->outline_num)++;
  }
}