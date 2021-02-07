#include "../headers/init.h"
#include "../headers/dev.h"

void init_gameWindow(GameWindow *window)
{

  // calculating and creating the dimentions of the main window

  SDL_Rect max_Window;
  int getBounds = SDL_GetDisplayBounds(0, &max_Window);
  if (getBounds != 0)
    lib_errorLog("failed at getting bounds", SDL_GetError());
  window->max_w = max_Window.w;
  window->max_h = max_Window.h;
  window->w = window->max_w / 2;
  window->h = window->max_h / 2;
  window->x = (window->max_w / 2) - (window->w / 2);
  window->y = (window->max_h / 2) - (window->h / 2);

  window->fullScreen = 0;

  /// TODO: change the name of the wingdow
  window->mainWindow = NULL;
  window->mainWindow = SDL_CreateWindow("FirstGame", window->x, window->y, window->w, window->h, SDL_WINDOW_RESIZABLE);
  if (window->mainWindow == NULL)
    lib_errorLog("failed at creating a window", SDL_GetError());

  // main surface
  window->mainSurface = SDL_GetWindowSurface(window->mainWindow);
  if (window->mainSurface == NULL)
    lib_errorLog("failed at getting surface form window", SDL_GetError());

  printf("hello");
}

void init_gameDev(GameDev *dev)
{
  dev->show_FPS = 0;
  dev->FPS = 0;
  dev->FPS_cap = 60;
  dev->currTick = 0;
  dev->prevTick = 0;
  dev->frameDelayCount = 0;
  dev->frameDelayIndex = 0;
  dev->frameDelayAvg = 0;
}

void init_UI(UI *ui)
{
  ui->dev_Font = NULL;
  ui->dev_Font = TTF_OpenFont("./assets/BalooChettan2-Regular.ttf", 16);
  if (ui->dev_Font == NULL)
    lib_errorLog("failed at loaing font", TTF_GetError());
  ui->FPS_surface = NULL;
  ui->FPS_Color.r = 255;
  ui->FPS_Color.g = 255;
  ui->FPS_Color.b = 0;
}