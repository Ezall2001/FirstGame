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
  window->default_w = 1920;
  window->default_h = 1080;

  window->fullScreen = 0;
  window->running = 1;
  window->win_width_ratio = (float)window->w / window->default_w;
  window->game_scene = 0;
  window->menu_scene = 0;
  window->mute = 0;
  window->music_volume = 100;
  window->SFX_volume = 100;

  window->mainWindow = NULL;
  window->mainWindow = SDL_CreateWindow("Surrounded By Water", window->x, window->y, window->w, window->h, SDL_WINDOW_RESIZABLE);
  if (window->mainWindow == NULL)
    lib_errorLog("failed at creating a window", SDL_GetError());

  // main renderer
  window->mainRenderer = SDL_CreateRenderer(window->mainWindow, -1, SDL_RENDERER_ACCELERATED);
  if (window->mainRenderer == NULL)
    lib_errorLog("failed at creating renderer form window", SDL_GetError());
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

void init_devUI(DevUI *ui)
{
  ui->dev_Font = NULL;
  ui->dev_Font = TTF_OpenFont("./assets/fonts/BalooChettan2-Regular.ttf", 255);
  if (ui->dev_Font == NULL)
    lib_errorLog("failed at loaing font", TTF_GetError());
  ui->FPS_Text = NULL;
  ui->FPS_Color.r = 255;
  ui->FPS_Color.g = 255;
  ui->FPS_Color.b = 0;
}

void init_Input(GameInput *input)
{
  input->mouse_x = 0;
  input->mouse_y = 0;
  input->num_keys = 0;
}

void init_menuUI(MenuUI *ui, GameWindow *window)
{
  init_Common_Menu(&(ui->common_UI), window);
  init_Scene0_Menu(&(ui->scene0_UI), &(ui->common_UI), window);
}
