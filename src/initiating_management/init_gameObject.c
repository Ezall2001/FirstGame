#include "../headers/init.h"
#include "../headers/dev.h"

void init_GameWindow(GameWindow *window)
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

  window->r = seedRand(time(NULL));
  window->fullScreen = 0;
  window->running = 1;
  window->win_width_ratio = (float)window->w / window->default_w;
  window->game_scene = 0;
  window->menu_scene = 0;
  window->popUp = 0;

  window->mainWindow = NULL;
  window->mainWindow = SDL_CreateWindow("Surrounded By Water", window->x, window->y, window->w, window->h, SDL_WINDOW_RESIZABLE);
  if (window->mainWindow == NULL)
    lib_errorLog("failed at creating a window", SDL_GetError());

  SDL_SetWindowSize(window->mainWindow, window->w, window->h); // to avoid initin all the coords and then update them on resize

  // game icon
  SDL_RWops *icon_Path = SDL_RWFromFile("./assets/icons/game_icon.ico", "rb");
  if (icon_Path == NULL)
    lib_errorLog("failed at getting icon path", SDL_GetError());

  SDL_Surface *game_Icon = IMG_LoadICO_RW(icon_Path);
  if (game_Icon == NULL)
    lib_errorLog("failed at loading icon", SDL_GetError());

  SDL_SetWindowIcon(window->mainWindow, game_Icon);

  SDL_FreeRW(icon_Path);
  SDL_FreeSurface(game_Icon);

  // main renderer
  window->mainRenderer = SDL_CreateRenderer(window->mainWindow, -1, SDL_RENDERER_ACCELERATED);
  if (window->mainRenderer == NULL)
    lib_errorLog("failed at creating renderer form window", SDL_GetError());
}

void init_GameDev(GameDev *dev)
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

void init_GameInput(GameInput *input)
{
  input->mouse_x = 0;
  input->mouse_y = 0;
  input->num_keys = 0;
}

void init_GameSound(GameSound *sound)
{

  int open_Audio = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  if (open_Audio != 0)
    lib_errorLog("Failed at opnening Audio", Mix_GetError());

  sound->menu_music = Mix_LoadMUS("./assets/music/menu_music.mp3");
  if (sound->menu_music == NULL)
    lib_errorLog("Failed at load music File", Mix_GetError());

  sound->bird_SFX = Mix_LoadWAV("./assets/SFX/menu/birds_SFX.wav");
  if (sound->bird_SFX == NULL)
    lib_errorLog("Failed at load music File1", Mix_GetError());

  sound->wind_SFX = Mix_LoadWAV("./assets/SFX/menu/wind_SFX.wav");
  if (sound->wind_SFX == NULL)
    lib_errorLog("Failed at load music File2", Mix_GetError());

  sound->waves_SFX = Mix_LoadWAV("./assets/SFX/menu/waves_SFX.wav");
  if (sound->waves_SFX == NULL)
    lib_errorLog("Failed at load music File3", Mix_GetError());

  sound->click_SFX = Mix_LoadWAV("./assets/SFX/menu/click_SFX.wav");
  if (sound->click_SFX == NULL)
    lib_errorLog("Failed at load music File4", Mix_GetError());

  Mix_VolumeChunk(sound->click_SFX, 40);
  Mix_VolumeChunk(sound->wind_SFX, 25);
  Mix_VolumeChunk(sound->waves_SFX, 20);

  sound->mute = 0;
  sound->music_volume = 100;
  sound->SFX_volume = 100;

  sound->wind_play = 0;
  sound->button_click_play = 0;
  sound->bird_play = 0;
  sound->wave_play = 1;
}

void init_GameUI(GameUI *ui, GameWindow *window)
{
  init_DevUI(&(ui->dev_UI));
  init_Common_Menu(&(ui->common_UI), window);
  init_Scene0_Menu(&(ui->scene0_UI), &(ui->common_UI), window);
  init_Scene1_Menu(&(ui->scene1_UI), &(ui->common_UI), window);
  init_Scene2_Menu(&(ui->scene2_UI), &(ui->common_UI), window);
  init_Scene3_Menu(&(ui->scene3_UI), &(ui->common_UI), window);
  init_Quit_PopUp(&(ui->quit_PopUp), &(ui->common_UI), window);
}
