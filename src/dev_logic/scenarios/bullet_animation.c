#include "../../headers/dev.h"

float get_SDL_ang(real_Rect src, real_Rect dst)
{
  float r_ang = 0;
  float distance = sqrt(pow(dst.x - src.x, 2) + pow(dst.y - src.y, 2));
  float a_sin = asin((src.y - dst.y) / distance);
  float a_cos = acos((dst.x - src.x) / distance);
  if (a_sin >= 0)
  {
    r_ang = a_cos;
  }
  else
  {
    r_ang = (M_PI * 2) - a_cos;
  }

  return convert_Radiant_Degree(r_ang);
}

void projectile_test(char scn[])
{
  ////////////////////////////////
  /////// window and renderer
  ////////////////////////////////
  SDL_Window *window = SDL_CreateWindow("projectile test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  ////////////////////////////////
  /////// loading texture
  ////////////////////////////////
  SDL_Texture *bullet = NULL;

  load_Texture_Img(&bullet, "./assets/imgs/in_game/HULI_arrow.png", &renderer);

  ////////////////////////////////
  /////// coords
  ////////////////////////////////
  real_Rect r_bullet_coords;
  SDL_Rect s_bullet_coords;
  r_bullet_coords.w = 75;
  r_bullet_coords.h = 10;
  r_bullet_coords.x = 500;
  r_bullet_coords.y = 500;

  float bullet_d_ang = 0;
  float bullet_r_ang = 0;

  float bullet_speed = 10;

  ////////////////////////////////
  /////// main loop
  ////////////////////////////////
  int running = 1;
  int fire = 0;
  int set = 0;
  int moving = 0;
  SDL_Event event;
  real_Rect mouse;
  while (running == 1)
  {
    ////////////////////////////////
    /////// events
    ////////////////////////////////
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
        running = 0;

      if (event.type == SDL_MOUSEMOTION)
      {
        mouse.x = event.motion.x;
        mouse.y = event.motion.y;
      }
      if (event.type == SDL_MOUSEBUTTONDOWN)
        set = 1;
    }

    ////////////////////////////////
    /////// logic
    ////////////////////////////////

    if (set == 1)
    {
      r_bullet_coords.w = 75;
      r_bullet_coords.h = 10;
      r_bullet_coords.x = 500;
      r_bullet_coords.y = 500;
      set = 0;
      fire = 1;
    }

    if (fire == 1)
    {

      bullet_d_ang = get_SDL_ang(r_bullet_coords, mouse);
      bullet_r_ang = convert_Degree_Radiant(bullet_d_ang);
      fire = 0;
      moving = 1;
    }

    if (moving == 1)
    {

      r_bullet_coords.x += cos(bullet_r_ang) * bullet_speed;
      r_bullet_coords.y -= sin(bullet_r_ang) * bullet_speed;

      if (r_bullet_coords.x > 1100 || r_bullet_coords.x < -100 || r_bullet_coords.y > 1100 || r_bullet_coords.y < -100)
        moving = 0;
    }

    s_bullet_coords.w = r_bullet_coords.w;
    s_bullet_coords.h = r_bullet_coords.h;
    s_bullet_coords.x = r_bullet_coords.x - r_bullet_coords.w / 2;
    s_bullet_coords.y = r_bullet_coords.y - r_bullet_coords.h / 2;
    ////////////////////////////////
    /////// rendering
    ////////////////////////////////
    SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderCopyEx(renderer, bullet, NULL, &s_bullet_coords, -bullet_d_ang, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(renderer);

    SDL_Delay(16.7);
  }
}