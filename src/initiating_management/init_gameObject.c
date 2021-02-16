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
  window->running = 1;
  window->game_scene = 0;
  window->menu_scene = 0;

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
  ui->dev_Font = TTF_OpenFont("./assets/fonts/BalooChettan2-Regular.ttf", 32);
  if (ui->dev_Font == NULL)
    lib_errorLog("failed at loaing font", TTF_GetError());
  ui->FPS_Text = NULL;
  ui->FPS_Color.r = 255;
  ui->FPS_Color.g = 255;
  ui->FPS_Color.b = 0;
}

void init_menuUI(MenuUI *ui, GameWindow *window)
{
  SDL_Surface *tempSurface = NULL;
  SDL_RWops *tempPath = NULL;

  // font and colors
  ui->menu_Font = NULL;
  ui->menu_Font = TTF_OpenFont("./assets/fonts/menu's font.ttf", 16);
  if (ui->menu_Font == NULL)
    lib_errorLog("failed at loading font", TTF_GetError());

  ui->title_Color.r = 247;
  ui->title_Color.g = 147;
  ui->title_Color.b = 30;
  ui->title_Color.a = 1;

  ui->text_Color.r = 255;
  ui->text_Color.g = 255;
  ui->text_Color.b = 255;
  ui->text_Color.a = 1;

  // title text
  tempSurface = TTF_RenderUTF8_Blended(ui->menu_Font, "Surrounded By Water", ui->title_Color);
  if (tempSurface == NULL)
    lib_errorLog("failed at rendering font", TTF_GetError());

  ui->title_Text = SDL_CreateTextureFromSurface(window->mainRenderer, tempSurface);

  // start text
  tempSurface = TTF_RenderUTF8_Blended(ui->menu_Font, "Start", ui->text_Color);
  if (tempSurface == NULL)
    lib_errorLog("failed at rendering font", TTF_GetError());

  ui->start_Text = SDL_CreateTextureFromSurface(window->mainRenderer, tempSurface);

  // settings text
  tempSurface = TTF_RenderUTF8_Blended(ui->menu_Font, "Settings", ui->text_Color);
  if (tempSurface == NULL)
    lib_errorLog("failed at rendering font", TTF_GetError());

  ui->settings_Text = SDL_CreateTextureFromSurface(window->mainRenderer, tempSurface);

  // tutorial text
  tempSurface = TTF_RenderUTF8_Blended(ui->menu_Font, "Tutorial", ui->text_Color);
  if (tempSurface == NULL)
    lib_errorLog("failed at rendering font", TTF_GetError());

  ui->tutorial_Text = SDL_CreateTextureFromSurface(window->mainRenderer, tempSurface);

  // quit text
  tempSurface = TTF_RenderUTF8_Blended(ui->menu_Font, "Quit", ui->text_Color);
  if (tempSurface == NULL)
    lib_errorLog("failed at rendering font", TTF_GetError());

  ui->quit_Text = SDL_CreateTextureFromSurface(window->mainRenderer, tempSurface);

  // static button
  tempPath = SDL_RWFromFile("./assets/imgs/menu/static button.png", "rb");
  if (tempPath == NULL)
    lib_errorLog("failed at getting button img path", SDL_GetError());

  tempSurface = IMG_LoadPNG_RW(tempPath);
  if (tempSurface == NULL)
    lib_errorLog("failed at loading button img", IMG_GetError());

  ui->static_Button = SDL_CreateTextureFromSurface(window->mainRenderer, tempSurface);
  if (ui->static_Button == NULL)
    lib_errorLog("failed at converting button surface to texture", SDL_GetError());

  // hover button
  ///TODO: change the path of the hover button
  tempPath = SDL_RWFromFile("./assets/imgs/menu/static button.png", "rb");
  if (tempPath == NULL)
    lib_errorLog("failed at getting button img path", SDL_GetError());

  tempSurface = IMG_LoadPNG_RW(tempPath);
  if (tempSurface == NULL)
    lib_errorLog("failed at loading button img", IMG_GetError());

  ui->hover_Button = SDL_CreateTextureFromSurface(window->mainRenderer, tempSurface);
  if (ui->hover_Button == NULL)
    lib_errorLog("failed at converting button surface to texture", SDL_GetError());

  // main background
  tempPath = SDL_RWFromFile("./assets/imgs/menu/menu's-background.png", "rb");
  if (tempPath == NULL)
    lib_errorLog("failed at getting button img path", SDL_GetError());

  tempSurface = IMG_LoadPNG_RW(tempPath);
  if (tempSurface == NULL)
    lib_errorLog("failed at loading button img", IMG_GetError());

  ui->main_Background = SDL_CreateTextureFromSurface(window->mainRenderer, tempSurface);
  if (ui->main_Background == NULL)
    lib_errorLog("failed at converting button surface to texture", SDL_GetError());

  // menu background
  tempPath = SDL_RWFromFile("./assets/imgs/menu/menu's-second-background.png", "rb");
  if (tempPath == NULL)
    lib_errorLog("failed at getting button img path", SDL_GetError());

  tempSurface = IMG_LoadPNG_RW(tempPath);
  if (tempSurface == NULL)
    lib_errorLog("failed at loading button img", IMG_GetError());

  ui->menu_Background = SDL_CreateTextureFromSurface(window->mainRenderer, tempSurface);
  if (ui->menu_Background == NULL)
    lib_errorLog("failed at converting button surface to texture", SDL_GetError());

  SDL_FreeSurface(tempSurface);
  SDL_FreeRW(tempPath);
}