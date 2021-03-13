#include "../headers/renderer.h"

void update_renderer(GameWindow *window)
{
  int setColor = SDL_SetRenderDrawColor(window->mainRenderer, 0, 0, 0, 255);
  if (setColor != 0)
    lib_errorLog("failed at setting renderer color", SDL_GetError());

  int update_Renderer = SDL_RenderClear(window->mainRenderer);

  if (update_Renderer != 0)
    lib_errorLog("failed at updating window", SDL_GetError());
}

void render_FPS(GameWindow *window, DevUI *ui, GameDev dev)
{
  static float render_FPS_Delta = 100;
  static SDL_Rect FPS_Coords = {0, 0, 0, 0};

  render_FPS_Delta += dev.deltaTime * 1000;

  if (render_FPS_Delta / 100 >= 1)
  {
    // updating texture
    char displayFPS[5];
    itoa(dev.FPS, displayFPS, 10);

    load_Texture_Text(&(ui->FPS_Text), &(ui->dev_Font), displayFPS, ui->FPS_Color, &(window->mainRenderer));

    float text_w_ratio = get_Text_W_ratio(ui->dev_Font, displayFPS);
    FPS_Coords.x = 1;
    FPS_Coords.y = 1;
    FPS_Coords.w = 10 * strlen(displayFPS);
    FPS_Coords.h = 10 * text_w_ratio * strlen(displayFPS);

    render_FPS_Delta = 0;
  }

  int rendered = SDL_RenderCopy(window->mainRenderer, ui->FPS_Text, NULL, &FPS_Coords);
  if (rendered != 0)
    lib_errorLog("failed at blit surface", SDL_GetError());
}

void render_BlackLayer(GameWindow *window, Uint8 alpha)
{
  int setBlend = SDL_SetRenderDrawBlendMode(window->mainRenderer, SDL_BLENDMODE_BLEND);
  if (setBlend != 0)
    lib_errorLog("failed at setting blend mode", SDL_GetError());

  int setColor = SDL_SetRenderDrawColor(window->mainRenderer, 0, 0, 0, alpha);
  if (setColor != 0)
    lib_errorLog("failed at setting renderer color", SDL_GetError());

  SDL_Rect fullWindow = {0, 0, window->w, window->h};

  int fillWindow = SDL_RenderFillRect(window->mainRenderer, &fullWindow);
  if (fillWindow != 0)
    lib_errorLog("failed at fill rect", SDL_GetError());
}

void render_Boxes(GameWindow *window, DevUI *ui)
{
  int outline = 0;
  for (int i = 0; i < ui->outlines_num; i++)
  {
    int setColor = SDL_SetRenderDrawColor(window->mainRenderer, ui->outlines[i].box_color.r, ui->outlines[i].box_color.g, ui->outlines[i].box_color.b, ui->outlines[i].box_color.a);
    if (setColor != 0)
      lib_errorLog("failed at setting renderer color", SDL_GetError());

    outline = SDL_RenderDrawRect(window->mainRenderer, &(ui->outlines[i].box_coords));
    if (outline != 0)
      lib_errorLog("failed at rendering the outline", SDL_GetError());

    outline = SDL_RenderDrawPoint(window->mainRenderer, ui->outlines[i].box_coords.x + ui->outlines[i].box_coords.w / 2, ui->outlines[i].box_coords.y + ui->outlines[i].box_coords.h / 2);
    if (outline != 0)
      lib_errorLog("failed at rendering the outline", SDL_GetError());
  }
}

void render_Ranges(GameWindow *window, DevUI *ui)
{
  int outline = 0;
  int setColor = 0;
  for (int i = 0; i < ui->outlines_num; i++)
  {

    // roam range
    if (ui->outlines[i].roam_range_coords.w != 0)
    {
      setColor = SDL_SetRenderDrawColor(window->mainRenderer, ui->outlines[i].roam_range_color.r, ui->outlines[i].roam_range_color.g, ui->outlines[i].roam_range_color.b, ui->outlines[i].roam_range_color.a);
      if (setColor != 0)
        lib_errorLog("failed at setting renderer color", SDL_GetError());

      outline = DrawCircle(window->mainRenderer, ui->outlines[i].roam_range_coords.x, ui->outlines[i].roam_range_coords.y, ui->outlines[i].roam_range_coords.w);
      if (outline != 0)
        lib_errorLog("failed at rendering the outline", SDL_GetError());
    }

    // detection range
    if (ui->outlines[i].detection_range_coords.w != 0)
    {
      setColor = SDL_SetRenderDrawColor(window->mainRenderer, ui->outlines[i].detection_range_color.r, ui->outlines[i].detection_range_color.g, ui->outlines[i].detection_range_color.b, ui->outlines[i].detection_range_color.a);
      if (setColor != 0)
        lib_errorLog("failed at setting renderer color", SDL_GetError());

      outline = DrawCircle(window->mainRenderer, ui->outlines[i].detection_range_coords.x, ui->outlines[i].detection_range_coords.y, ui->outlines[i].detection_range_coords.w);
      if (outline != 0)
        lib_errorLog("failed at rendering the outline", SDL_GetError());
    }

    // obstacle range
    if (ui->outlines[i].obstacle_range_coords.w != 0)
    {
      setColor = SDL_SetRenderDrawColor(window->mainRenderer, ui->outlines[i].obstacle_range_color.r, ui->outlines[i].obstacle_range_color.g, ui->outlines[i].obstacle_range_color.b, ui->outlines[i].obstacle_range_color.a);
      if (setColor != 0)
        lib_errorLog("failed at setting renderer color", SDL_GetError());

      outline = DrawCircle(window->mainRenderer, ui->outlines[i].obstacle_range_coords.x, ui->outlines[i].obstacle_range_coords.y, ui->outlines[i].obstacle_range_coords.w);
      if (outline != 0)
        lib_errorLog("failed at rendering the outline", SDL_GetError());
    }

    // attack range
    if (ui->outlines[i].attack_range_coords.w != 0)
    {
      setColor = SDL_SetRenderDrawColor(window->mainRenderer, ui->outlines[i].attack_range_color.r, ui->outlines[i].attack_range_color.g, ui->outlines[i].attack_range_color.b, ui->outlines[i].attack_range_color.a);
      if (setColor != 0)
        lib_errorLog("failed at setting renderer color", SDL_GetError());

      outline = DrawCircle(window->mainRenderer, ui->outlines[i].attack_range_coords.x, ui->outlines[i].attack_range_coords.y, ui->outlines[i].attack_range_coords.w);
      if (outline != 0)
        lib_errorLog("failed at rendering the outline", SDL_GetError());
    }

    // dmg range
    if (ui->outlines[i].dmg_range_coords.w != 0)
    {
      setColor = SDL_SetRenderDrawColor(window->mainRenderer, ui->outlines[i].dmg_range_color.r, ui->outlines[i].dmg_range_color.g, ui->outlines[i].dmg_range_color.b, ui->outlines[i].dmg_range_color.a);
      if (setColor != 0)
        lib_errorLog("failed at setting renderer color", SDL_GetError());

      outline = DrawCircle(window->mainRenderer, ui->outlines[i].dmg_range_coords.x, ui->outlines[i].dmg_range_coords.y, ui->outlines[i].dmg_range_coords.w);
      if (outline != 0)
        lib_errorLog("failed at rendering the outline", SDL_GetError());
    }

    // escape range
    if (ui->outlines[i].escape_range_coords.w != 0)
    {
      setColor = SDL_SetRenderDrawColor(window->mainRenderer, ui->outlines[i].escape_range_color.r, ui->outlines[i].escape_range_color.g, ui->outlines[i].escape_range_color.b, ui->outlines[i].escape_range_color.a);
      if (setColor != 0)
        lib_errorLog("failed at setting renderer color", SDL_GetError());

      outline = DrawCircle(window->mainRenderer, ui->outlines[i].escape_range_coords.x, ui->outlines[i].escape_range_coords.y, ui->outlines[i].escape_range_coords.w);
      if (outline != 0)
        lib_errorLog("failed at rendering the outline", SDL_GetError());
    }
  }
}