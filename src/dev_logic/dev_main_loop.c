#include "../headers/dev.h"

void dev_loop(GameObject *G)
{
  calcFPS(&(G->dev));
  set_DeltaTime(&(G->dev));

  if (G->dev.show_outlines == 1)
    set_Outlines_Coords(&(G->logic), &(G->UI.dev_UI), &(G->window));
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

void set_Outlines_Coords(GameLogic *logic, DevUI *ui, GameWindow *window)
{
  ui->outline_num = 0;

  // --- main character ---
  // coords
  ui->outlines[ui->outline_num].coords.w = logic->James.coords.w * window->win_width_ratio;
  ui->outlines[ui->outline_num].coords.h = logic->James.coords.h * window->win_width_ratio;
  ui->outlines[ui->outline_num].coords.x = (logic->James.coords.x - logic->cam_Coords.x) * logic->CAM_REAL_Cam_w_Ratio - ui->outlines[ui->outline_num].coords.w / 2;
  ui->outlines[ui->outline_num].coords.y = (logic->cam_Coords.y - logic->James.coords.y) * logic->CAM_REAL_Cam_w_Ratio - ui->outlines[ui->outline_num].coords.h / 2;

  // color
  ui->outlines[ui->outline_num].color.r = 52;
  ui->outlines[ui->outline_num].color.g = 235;
  ui->outlines[ui->outline_num].color.b = 140;
  ui->outlines[ui->outline_num].color.a = 255;

  (ui->outline_num)++;

}