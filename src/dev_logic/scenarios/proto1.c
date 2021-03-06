#include "../../headers/dev.h"
#include "../../headers/renderer.h"
#include "../../headers/event.h"

void map_collision(GameWindow *window, SDL_Rect *coords, float *rx, float *ry)
{

  if (coords->x >= window->w - coords->w)
  {
    coords->x = window->w - coords->w;
    *rx = coords->x;
  }
  else if (coords->x <= 0)
  {
    coords->x = 0;
    *rx = coords->x;
  }

  if (coords->y >= window->h - coords->h)
  {
    coords->y = window->h - coords->h;
    *ry = coords->y;
  }
  else if (coords->y <= 0)
  {
    coords->y = 0;
    *ry = coords->y;
  }
}

void proto1(char scn[], GameObject *G)
{
  if (strcmp(scn, "proto1") == 0)
  {
    // --- init ---
    SDL_Texture *map = NULL;
    SDL_Texture *character_S[12];
    SDL_Texture *character_SE[12];
    SDL_Texture *character_E[12];
    SDL_Texture *character_NE[12];
    SDL_Texture *character_N[12];
    SDL_Texture *character_NW[12];
    SDL_Texture *character_W[12];
    SDL_Texture *character_SW[12];
    int animation_img = 0;
    int player_direction = 20; // 10:North 20:South 1:East 2:West 11:NorthEast 12:NorthWest 21:SouthEast 22:SouthWest
    int player_moving = 0;     // 0:not-moving 1:moving
    SDL_Rect player_Coords = {
        G->window.w / 2,
        0,
        75,
        75};

    // mochup character
    load_Sprite(character_S, 12, "./assets/sprites/mochup_character/moving_S/", &(G->window.mainRenderer));
    load_Sprite(character_SE, 12, "./assets/sprites/mochup_character/moving_SE/", &(G->window.mainRenderer));
    load_Sprite(character_E, 12, "./assets/sprites/mochup_character/moving_E/", &(G->window.mainRenderer));
    load_Sprite(character_NE, 12, "./assets/sprites/mochup_character/moving_NE/", &(G->window.mainRenderer));
    load_Sprite(character_N, 12, "./assets/sprites/mochup_character/moving_N/", &(G->window.mainRenderer));
    load_Sprite(character_NW, 12, "./assets/sprites/mochup_character/moving_NW/", &(G->window.mainRenderer));
    load_Sprite(character_W, 12, "./assets/sprites/mochup_character/moving_W/", &(G->window.mainRenderer));
    load_Sprite(character_SW, 12, "./assets/sprites/mochup_character/moving_SW/", &(G->window.mainRenderer));

    // bird

    load_Texture_Img(&map, "./assets/imgs/proto1/map_4K.png", &(G->window.mainRenderer));

    //   --- main loop ---
    SDL_Event event;
    while (G->window.running == 1)
    {

      ///////////////////////////////////
      //events
      ///////////////////////////////////
      while (SDL_PollEvent(&event))
      {
        switch (event.type)
        {
        case SDL_QUIT:
        {
          G->window.running = 0;
          break;
        }

        default:
          break;
        }
      }
      const Uint8 *state = SDL_GetKeyboardState(NULL);

      ///////////////////////////////////
      // logic
      ///////////////////////////////////
      dev_loop(G);

      static float ry = 0;
      static float rx = 0;
      float v = 250 * G->dev.deltaTime * G->window.win_width_ratio;
      float vd = 170 * G->dev.deltaTime * G->window.win_width_ratio;

      if (state[SDL_SCANCODE_UP] == 1 && state[SDL_SCANCODE_RIGHT] == 1)
      {
        rx += vd;
        ry -= vd;
        player_direction = 11;
        player_moving = 1;
      }
      else if (state[SDL_SCANCODE_UP] == 1 && state[SDL_SCANCODE_LEFT] == 1)
      {
        rx -= vd;
        ry -= vd;
        player_direction = 12;
        player_moving = 1;
      }
      else if (state[SDL_SCANCODE_DOWN] == 1 && state[SDL_SCANCODE_RIGHT] == 1)
      {
        rx += vd;
        ry += vd;
        player_direction = 21;
        player_moving = 1;
      }
      else if (state[SDL_SCANCODE_DOWN] == 1 && state[SDL_SCANCODE_LEFT] == 1)
      {
        rx -= vd;
        ry += vd;
        player_direction = 22;
        player_moving = 1;
      }
      else if (state[SDL_SCANCODE_DOWN] == 1)
      {
        ry += v;
        player_direction = 20;
        player_moving = 1;
      }
      else if (state[SDL_SCANCODE_UP] == 1)
      {
        ry -= v;
        player_direction = 10;
        player_moving = 1;
      }
      else if (state[SDL_SCANCODE_RIGHT] == 1)
      {
        rx += v;
        player_direction = 1;
        player_moving = 1;
      }
      else if (state[SDL_SCANCODE_LEFT] == 1)
      {
        rx -= v;
        player_direction = 2;
        player_moving = 1;
      }
      else
      {
        player_moving = 0;
      }

      player_Coords.x = rx;
      player_Coords.y = ry;

      map_collision(&(G->window), &player_Coords, &rx, &ry);
      ///////////////////////////////////
      // rendering
      ///////////////////////////////////
      update_renderer(&(G->window));

      // MAP
      SDL_RenderCopy(G->window.mainRenderer, map, NULL, NULL);

      // PLAYER
      static float delta_player = 0;

      if (player_moving == 1)
      {
        delta_player += G->dev.deltaTime;
        if (delta_player > 0.5 / 12)
        {
          animation_img = (animation_img + 1) % 12;
          delta_player = 0;
        }
      }
      else
      {
        animation_img = 0;
        delta_player = 0;
      }

      if (player_direction == 10)
        SDL_RenderCopy(G->window.mainRenderer, character_N[animation_img], NULL, &player_Coords);
      else if (player_direction == 20)
        SDL_RenderCopy(G->window.mainRenderer, character_S[animation_img], NULL, &player_Coords);
      else if (player_direction == 1)
        SDL_RenderCopy(G->window.mainRenderer, character_E[animation_img], NULL, &player_Coords);
      else if (player_direction == 2)
        SDL_RenderCopy(G->window.mainRenderer, character_W[animation_img], NULL, &player_Coords);
      else if (player_direction == 11)
        SDL_RenderCopy(G->window.mainRenderer, character_NE[animation_img], NULL, &player_Coords);
      else if (player_direction == 12)
        SDL_RenderCopy(G->window.mainRenderer, character_NW[animation_img], NULL, &player_Coords);
      else if (player_direction == 21)
        SDL_RenderCopy(G->window.mainRenderer, character_SE[animation_img], NULL, &player_Coords);
      else if (player_direction == 22)
        SDL_RenderCopy(G->window.mainRenderer, character_SW[animation_img], NULL, &player_Coords);

      // FPS
      if (G->dev.show_FPS == 1)
        render_FPS(&(G->window), &(G->UI.dev_UI), G->dev);

      SDL_RenderPresent(G->window.mainRenderer);

      cap_FPS(G->dev);
    }
  }
}