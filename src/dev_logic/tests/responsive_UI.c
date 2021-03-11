#include "../../headers/dev.h"

void responsive_UI(char scn[])
{
  if (strcmp(scn, "responsive_UI") == 0)
  {
    SDL_Rect window_Coords = {300, 200, 800, 700};
    SDL_Rect button_dst = {0, 0, 180, 40};
    float win_width_ratio = 0;

    SDL_Window *window = SDL_CreateWindow("responsive UI", window_Coords.x, window_Coords.y, window_Coords.w, window_Coords.h, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RWops *img_Path = SDL_RWFromFile("./assets/imgs/menu/static button.png", "rb");
    SDL_Surface *button = IMG_LoadPNG_RW(img_Path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, button);

    int running = 1;
    SDL_Event event;
    while (running)
    {
      SDL_RenderClear(renderer);
      while (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT)
        {
          running = 0;
        }
        else if (event.type == SDL_WINDOWEVENT)
        {
          switch (event.window.event)
          {
          case SDL_WINDOWEVENT_SIZE_CHANGED:
          {
            int w, h;
            SDL_GetWindowSize(window, &w, &h);
            win_width_ratio = (float)w / window_Coords.w;
            window_Coords.w = w;
            window_Coords.h = h;

            button_dst.w *= win_width_ratio;
            button_dst.h *= win_width_ratio;
            button_dst.x = window_Coords.w * 0.95 - button_dst.w;
            button_dst.y = window_Coords.h * 0.5;
            break;
          }
          default:
            break;
          }
        }
      }

      SDL_RenderCopy(renderer, texture, NULL, &button_dst);
      SDL_RenderPresent(renderer);
      SDL_Delay(20);
    }
  }
}