#include "../headers/dev.h"
#include "../headers/logic.h"

void dev_loop(GameObject *G)
{
  calcFPS(&(G->dev));
  set_DeltaTime(&(G->dev));

  if (G->dev.change_character == 1)
    change_character(&(G->logic), &(G->input));

  if (G->dev.spawn_enemy == 1)
    spawn_enemie(&(G->logic), &(G->input), &(G->window));

  if (G->dev.show_boxes == 1)
    set_Boxes_Coords(&(G->logic), &(G->UI.dev_UI));

  if (G->dev.show_ranges == 1)
    set_Ranges_Coords(&(G->logic), &(G->UI.dev_UI));

  if (G->dev.show_directions == 1)
    set_Directions_Coords(&(G->logic), &(G->UI.dev_UI));
}

void calcFPS(GameDev *dev)
{
  static int firstFrameBug = 1;
  if (firstFrameBug)
  {
    dev->prevTick = SDL_GetTicks();
    firstFrameBug = 0;
  }

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

void change_character(GameLogic *logic, GameInput *input)
{
  static int default_character = 1;
  if (default_character == 1)
  {
    logic->players[0] = logic->survivors[0];
    logic->players[1] = logic->survivors[1];
    default_character = 0;
  }

  for (int i = 0; i < input->num_keys; i++)
  {
    if (input->keys[i] == SDLK_KP_1)
    {
      logic->survivors[0].coords = logic->players[0].coords;
      logic->players[0] = logic->survivors[0];
    }
    else if (input->keys[i] == SDLK_KP_2)
    {
      logic->survivors[1].coords = logic->players[0].coords;
      logic->players[0] = logic->survivors[1];
    }
    else if (input->keys[i] == SDLK_KP_3)
    {
      logic->survivors[2].coords = logic->players[0].coords;
      logic->players[0] = logic->survivors[2];
    }
    else if (input->keys[i] == SDLK_KP_4)
    {
      logic->survivors[3].coords = logic->players[0].coords;
      logic->players[0] = logic->survivors[3];
    }
  }
}

void spawn_enemie(GameLogic *logic, GameInput *input, GameWindow *window)
{
  for (int i = 0; i < input->num_keys; i++)
  {
    if (input->keys[i] == SDLK_F1)
    {
      spawn_on_edge(logic, window, 0);
    }
    else if (input->keys[i] == SDLK_F12)
    {
      logic->enemy_num = 0;
    }
  }
}

void set_Boxes_Coords(GameLogic *logic, DevUI *ui)
{
  ui->outlines_num = 0;
  real_Rect checkpoint = {0, 0, 10, 10};

  ///////////////////////////////////////
  ///////// --- players ---
  ///////////////////////////////////////
  for (int i = 0; i < 2; i++)
  {

    // main box
    convert_REAL_SDL(&(ui->outlines[ui->outlines_num].box_coords),
                     logic->players[i].coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     logic->players[i].coords.w,
                     logic->players[i].coords.h);

    ui->outlines[ui->outlines_num].box_color = set_color(52, 235, 140 + (100 * i), 255);

    // checkpoint
    for (int j = 0; j < 4; j++)
    {
      checkpoint.x = logic->players[i].coords.x + ((logic->players[i].coords.w / 2) - 1) * pow(-1, j + 1);
      checkpoint.y = logic->players[i].coords.y + ((logic->players[i].coords.h / 2) - 1) * pow(-1, (j + 2) / 2);

      convert_REAL_SDL(&(ui->outlines[ui->outlines_num].checkpoints[j]),
                       checkpoint,
                       logic->cam_Coords,
                       logic->CAM_REAL_Cam_w_Ratio,
                       checkpoint.w,
                       checkpoint.h);

      ui->outlines[ui->outlines_num].checkpoints_color = ui->outlines[ui->outlines_num].box_color;
      ui->outlines[ui->outlines_num].checkpoints_color.a = 180;
    }

    (ui->outlines_num)++;
  }

  ///////////////////////////////////////
  ///////// --- enemies ---
  ///////////////////////////////////////
  for (int i = 0; i < logic->enemy_num; i++)
  {

    // main box
    convert_REAL_SDL(&(ui->outlines[ui->outlines_num].box_coords),
                     logic->enemies[i].coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     logic->enemies[i].coords.w,
                     logic->enemies[i].coords.h);

    if (strcmp(logic->enemies[i].name, "BIRD") == 0)
      ui->outlines[ui->outlines_num].box_color = set_color(133, 91, 88, 255);

    // checkpoint
    for (int j = 0; j < 4; j++)
    {
      checkpoint.x = logic->enemies[i].coords.x + ((logic->enemies[i].coords.w / 2) - 1) * pow(-1, j + 1);
      checkpoint.y = logic->enemies[i].coords.y + ((logic->enemies[i].coords.h / 2) - 1) * pow(-1, (j + 2) / 2);

      convert_REAL_SDL(&(ui->outlines[ui->outlines_num].checkpoints[j]),
                       checkpoint,
                       logic->cam_Coords,
                       logic->CAM_REAL_Cam_w_Ratio,
                       checkpoint.w,
                       checkpoint.h);

      ui->outlines[ui->outlines_num].checkpoints_color = ui->outlines[ui->outlines_num].box_color;
      ui->outlines[ui->outlines_num].checkpoints_color.a = 100;
    }

    (ui->outlines_num)++;
  }

  ///////////////////////////////////////
  ///////// --- obstacles ---
  ///////////////////////////////////////
  for (int i = 0; i < logic->obstacle_num; i++)
  {

    convert_REAL_SDL(&(ui->outlines[ui->outlines_num].box_coords),
                     logic->obstacles[i].coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     logic->obstacles[i].coords.w,
                     logic->obstacles[i].coords.h);

    ui->outlines[ui->outlines_num].box_color = set_color(235, 153, 52, 255);

    (ui->outlines_num)++;
  }
}

void set_Ranges_Coords(GameLogic *logic, DevUI *ui)
{
  ui->outlines_num = 0;
  real_Rect range_coords;

  ///////////////////////////////////////
  ///////// --- players ---
  ///////////////////////////////////////

  for (int i = 0; i < 2; i++)
  {
    // init all ranges
    ui->outlines[ui->outlines_num].roam_range_coords.w = 0;
    ui->outlines[ui->outlines_num].detection_range_coords.w = 0;
    ui->outlines[ui->outlines_num].obstacle_range_coords.w = 0;
    ui->outlines[ui->outlines_num].attack_range_coords.w = 0;
    ui->outlines[ui->outlines_num].dmg_range_coords.w = 0;
    ui->outlines[ui->outlines_num].escape_range_coords.w = 0;

    // dmg range
    range_coords.x = logic->players[i].coords.x;
    range_coords.y = logic->players[i].coords.y;
    range_coords.w = logic->players[i].dmg_range;
    range_coords.h = logic->players[i].dmg_range;

    convert_REAL_SDL(&(ui->outlines[ui->outlines_num].dmg_range_coords),
                     range_coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     range_coords.w,
                     range_coords.h);

    ui->outlines[ui->outlines_num].dmg_range_color = set_color(255, 17, 0, 255);

    (ui->outlines_num)++;
  }

  ///////////////////////////////////////
  ///////// --- enemies ---
  ///////////////////////////////////////
  for (int i = 0; i < logic->enemy_num; i++)
  {
    // init all ranges
    ui->outlines[ui->outlines_num].roam_range_coords.w = 0;
    ui->outlines[ui->outlines_num].detection_range_coords.w = 0;
    ui->outlines[ui->outlines_num].obstacle_range_coords.w = 0;
    ui->outlines[ui->outlines_num].attack_range_coords.w = 0;
    ui->outlines[ui->outlines_num].dmg_range_coords.w = 0;
    ui->outlines[ui->outlines_num].escape_range_coords.w = 0;

    // roam range
    if (logic->enemies[i].roam_range.w != 0)
    {
      convert_REAL_SDL(&(ui->outlines[ui->outlines_num].roam_range_coords),
                       logic->enemies[i].roam_range,
                       logic->cam_Coords,
                       logic->CAM_REAL_Cam_w_Ratio,
                       logic->enemies[i].roam_range.w,
                       logic->enemies[i].roam_range.h);

      ui->outlines[ui->outlines_num].roam_range_color = set_color(0, 255, 251, 255);
    }

    // detection range
    if (logic->enemies[i].detection_range != 0)
    {
      range_coords.x = logic->enemies[i].coords.x;
      range_coords.y = logic->enemies[i].coords.y;
      range_coords.w = logic->enemies[i].detection_range;
      range_coords.h = logic->enemies[i].detection_range;

      convert_REAL_SDL(&(ui->outlines[ui->outlines_num].detection_range_coords),
                       range_coords,
                       logic->cam_Coords,
                       logic->CAM_REAL_Cam_w_Ratio,
                       range_coords.w,
                       range_coords.h);

      ui->outlines[ui->outlines_num].detection_range_color = set_color(2, 181, 178, 255);
    }

    // obstacle range
    if (logic->enemies[i].avoid_obstacle_range != 0)
    {
      range_coords.x = logic->enemies[i].coords.x;
      range_coords.y = logic->enemies[i].coords.y;
      range_coords.w = logic->enemies[i].avoid_obstacle_range;
      range_coords.h = logic->enemies[i].avoid_obstacle_range;

      convert_REAL_SDL(&(ui->outlines[ui->outlines_num].obstacle_range_coords),
                       range_coords,
                       logic->cam_Coords,
                       logic->CAM_REAL_Cam_w_Ratio,
                       range_coords.w,
                       range_coords.h);

      ui->outlines[ui->outlines_num].obstacle_range_color = set_color(255, 174, 0, 255);
    }

    // attack range
    if (logic->enemies[i].attack_range != 0)
    {
      range_coords.x = logic->enemies[i].coords.x;
      range_coords.y = logic->enemies[i].coords.y;
      range_coords.w = logic->enemies[i].attack_range;
      range_coords.h = logic->enemies[i].attack_range;

      convert_REAL_SDL(&(ui->outlines[ui->outlines_num].attack_range_coords),
                       range_coords,
                       logic->cam_Coords,
                       logic->CAM_REAL_Cam_w_Ratio,
                       range_coords.w,
                       range_coords.h);

      ui->outlines[ui->outlines_num].attack_range_color = set_color(227, 14, 92, 255);
    }

    // dmg range
    if (logic->enemies[i].dmg_range != 0)
    {
      range_coords.x = logic->enemies[i].coords.x;
      range_coords.y = logic->enemies[i].coords.y;
      range_coords.w = logic->enemies[i].dmg_range;
      range_coords.h = logic->enemies[i].dmg_range;

      convert_REAL_SDL(&(ui->outlines[ui->outlines_num].dmg_range_coords),
                       range_coords,
                       logic->cam_Coords,
                       logic->CAM_REAL_Cam_w_Ratio,
                       range_coords.w,
                       range_coords.h);

      ui->outlines[ui->outlines_num].dmg_range_color = set_color(255, 17, 0, 255);
    }

    // escape range
    if (logic->enemies[i].escape_range != 0)
    {
      range_coords.x = logic->enemies[i].coords.x;
      range_coords.y = logic->enemies[i].coords.y;
      range_coords.w = logic->enemies[i].escape_range;
      range_coords.h = logic->enemies[i].escape_range;

      convert_REAL_SDL(&(ui->outlines[ui->outlines_num].escape_range_coords),
                       range_coords,
                       logic->cam_Coords,
                       logic->CAM_REAL_Cam_w_Ratio,
                       range_coords.w,
                       range_coords.h);

      ui->outlines[ui->outlines_num].escape_range_color = set_color(255, 255, 255, 255);
    }

    (ui->outlines_num)++;
  }
}

void set_Directions_Coords(GameLogic *logic, DevUI *ui)
{
  ui->outlines_num = 0;
  float static_line_length = 25;
  real_Rect r_direction_coords;
  SDL_Rect s_direction_coords;

  ///////////////////////////////////////
  ///////// --- players ---
  ///////////////////////////////////////
  for (int i = 0; i < 2; i++)
  {
    // first point
    r_direction_coords.x = logic->players[i].coords.x;
    r_direction_coords.y = logic->players[i].coords.y;

    convert_REAL_SDL(&s_direction_coords,
                     r_direction_coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     0,
                     0);

    ui->outlines[ui->outlines_num].direction_coords.x1 = s_direction_coords.x;
    ui->outlines[ui->outlines_num].direction_coords.y1 = s_direction_coords.y;

    // second point
    float action_r_ang = convert_Degree_Radiant(logic->players[i].action_ang);
    r_direction_coords.x = logic->players[i].coords.x + (cos(action_r_ang) * static_line_length * logic->players[i].speed);
    r_direction_coords.y = logic->players[i].coords.y + (sin(action_r_ang) * static_line_length * logic->players[i].speed);

    convert_REAL_SDL(&s_direction_coords,
                     r_direction_coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     0,
                     0);

    ui->outlines[ui->outlines_num].direction_coords.x2 = s_direction_coords.x;
    ui->outlines[ui->outlines_num].direction_coords.y2 = s_direction_coords.y;

    ui->outlines[ui->outlines_num].direction_color = set_color(51, 18, 219, 255);

    (ui->outlines_num)++;
  }

  ///////////////////////////////////////
  ///////// --- enemies ---
  ///////////////////////////////////////
  for (int i = 0; i < logic->enemy_num; i++)
  {
    // first point
    r_direction_coords.x = logic->enemies[i].coords.x;
    r_direction_coords.y = logic->enemies[i].coords.y;

    convert_REAL_SDL(&s_direction_coords,
                     r_direction_coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     0,
                     0);

    ui->outlines[ui->outlines_num].direction_coords.x1 = s_direction_coords.x;
    ui->outlines[ui->outlines_num].direction_coords.y1 = s_direction_coords.y;

    // second point
    float action_r_ang = convert_Degree_Radiant(logic->enemies[i].action_ang);
    r_direction_coords.x = logic->enemies[i].coords.x + (cos(action_r_ang) * static_line_length * logic->enemies[i].speed);
    r_direction_coords.y = logic->enemies[i].coords.y + (sin(action_r_ang) * static_line_length * logic->enemies[i].speed);

    convert_REAL_SDL(&s_direction_coords,
                     r_direction_coords,
                     logic->cam_Coords,
                     logic->CAM_REAL_Cam_w_Ratio,
                     0,
                     0);

    ui->outlines[ui->outlines_num].direction_coords.x2 = s_direction_coords.x;
    ui->outlines[ui->outlines_num].direction_coords.y2 = s_direction_coords.y;

    ui->outlines[ui->outlines_num].direction_color = set_color(51, 18, 219, 255);

    (ui->outlines_num)++;
  }
}
