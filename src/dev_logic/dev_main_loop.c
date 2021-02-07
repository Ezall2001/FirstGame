#include "../headers/dev.h"

void dev_loop(GameObject *G)
{

  if (G->dev.show_FPS == 1)
    calcFPS(&(G->dev));

  set_DeltaTime(&(G->dev));
}

void calcFPS(GameDev *dev)
{
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
