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

void init_menuUI(MenuUI *ui, GameWindow *window)
{
  init_Common_Menu(&(ui->common_UI), window);
  init_Scene0_Menu(&(ui->scene0_UI), &(ui->common_UI), window);
}

void init_Common_Menu(Menu_Common_UI *ui, GameWindow *window)
{
  // font and colors
  ui->menu_Font = NULL;
  ui->menu_Font = TTF_OpenFont("./assets/fonts/menu's font.ttf", 255);
  if (ui->menu_Font == NULL)
    lib_errorLog("failed at loading font", TTF_GetError());

  ui->title_Color.r = 247;
  ui->title_Color.g = 147;
  ui->title_Color.b = 30;
  ui->title_Color.a = 0;

  ui->text_Color.r = 255;
  ui->text_Color.g = 255;
  ui->text_Color.b = 255;
  ui->text_Color.a = 0;

  // text
  load_Texture_Text(&(ui->title_Text), &(ui->menu_Font), "Surrounded By Water", ui->title_Color, &(window->mainRenderer));

  // imgs
  load_Texture_Img(&(ui->static_Button), "./assets/imgs/menu/static button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->static_Blue_Button), "./assets/imgs/menu/static-blue-button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->hover_Button), "./assets/imgs/menu/hover-button.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->main_Background), "./assets/imgs/menu/menu's-background.png", &(window->mainRenderer));
  load_Texture_Img(&(ui->menu_Background), "./assets/imgs/menu/menu's-second-background.png", &(window->mainRenderer));

  // coords
  // menu background coords
  ui->main_Background_Coords.x = 0;
  ui->main_Background_Coords.y = 0;
  ui->main_Background_Coords.w = window->w;
  ui->main_Background_Coords.h = window->h;

  // title coords
  ui->title_Coords.x = window->w * 0.5;
  ui->title_Coords.y = window->h * 0.1;
  ui->title_Coords.w = 700 * window->win_width_ratio;
  ui->title_Coords.h = 85 * window->win_width_ratio;
}

void init_Scene0_Menu(Menu_Scene0_UI *ui, Menu_Common_UI *common_ui, GameWindow *window)
{

  char options[4][10] = {"Start", "Settings", "Tutorial", "Quit"};

  for (int i = 0; i < 4; i++)
  {
    // text
    load_Texture_Text(&(ui->scene_buttons[i].text), &(common_ui->menu_Font), options[i], common_ui->text_Color, &(window->mainRenderer));

    // button coords
    int static margin = 0;
    ui->scene_buttons[i].button_Coords.w = 90;
    ui->scene_buttons[i].button_Coords.h = 50;
    ui->scene_buttons[i].button_Coords.x = window->w * 0.9 - ui->scene_buttons[i].button_Coords.w;
    ui->scene_buttons[i].button_Coords.y = (window->h * 0.4) + margin;
    margin += i * (ui->scene_buttons[i].button_Coords.h + 20);

    // text coords

    // hover
    ui->scene_buttons[i].hover = 0;
  }
