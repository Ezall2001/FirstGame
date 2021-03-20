#include "../headers/logic.h"

void spawn_Players(GameLogic *logic, GameWindow *window)
{

  // main player spawn coords
  logic->players[0].coords.x = get_Random_Number(&(window->r), -(logic->MAP_Map_Coords.w) / 3, (logic->MAP_Map_Coords.w) / 3);
  logic->players[0].coords.y = get_Random_Number(&(window->r), -(logic->MAP_Map_Coords.h) / 3, (logic->MAP_Map_Coords.h) / 3);
  logic->players[0].id = 0;
  // secondary player spawn coords
  logic->players[1].coords.x = logic->players[0].coords.x + logic->players[0].coords.w + 20;
  logic->players[1].coords.y = logic->players[0].coords.y;
  logic->players[1].id = 1;

  logic->next_id = 2;
}

void spawn_on_edge(GameLogic *logic, GameWindow *window, int enemy_type)
{

  int exclude_side_vertical = 0;   // 0: none 1:top 3:bottom
  int exclude_side_horizontal = 0; // 0: none 2:right 4:left
  int side = 0;
  float side_offset = logic->MAP_Map_Coords.h * 0.15;

  if (logic->players[0].coords.y > (logic->MAP_Map_Coords.h / 2) - side_offset)
    exclude_side_vertical = 1;
  else if (logic->players[0].coords.y < (-logic->MAP_Map_Coords.h / 2) + side_offset)
    exclude_side_vertical = 3;

  if (logic->players[0].coords.x > (logic->MAP_Map_Coords.w / 2) - side_offset)
    exclude_side_horizontal = 2;
  else if (logic->players[0].coords.x < (-logic->MAP_Map_Coords.h / 2) + side_offset)
    exclude_side_horizontal = 4;

  do
  {
    side = get_Random_Number(&(window->r), 1, 4);
  } while (side == exclude_side_horizontal || side == exclude_side_vertical);

  if (side == 1)
  {
    logic->enemy_types[enemy_type].coords.x = get_Random_Number(&(window->r), -logic->MAP_Map_Coords.w / 2, logic->MAP_Map_Coords.w / 2);
    logic->enemy_types[enemy_type].coords.y = logic->MAP_Map_Coords.h / 2 + logic->enemy_types[enemy_type].coords.h / 2;
  }
  else if (side == 3)
  {
    logic->enemy_types[enemy_type].coords.x = get_Random_Number(&(window->r), -logic->MAP_Map_Coords.w / 2, logic->MAP_Map_Coords.w / 2);
    logic->enemy_types[enemy_type].coords.y = -logic->MAP_Map_Coords.h / 2 - logic->enemy_types[enemy_type].coords.h / 2;
  }
  else if (side == 2)
  {
    logic->enemy_types[enemy_type].coords.x = logic->MAP_Map_Coords.w / 2 + logic->enemy_types[enemy_type].coords.w / 2;
    logic->enemy_types[enemy_type].coords.y = get_Random_Number(&(window->r), -logic->MAP_Map_Coords.h / 2, logic->MAP_Map_Coords.h / 2);
  }
  else if (side == 4)
  {
    logic->enemy_types[enemy_type].coords.x = -logic->MAP_Map_Coords.w / 2 - logic->enemy_types[enemy_type].coords.w / 2;
    logic->enemy_types[enemy_type].coords.y = get_Random_Number(&(window->r), -logic->MAP_Map_Coords.h / 2, logic->MAP_Map_Coords.h / 2);
  }

  logic->enemy_types[enemy_type].id = logic->next_id;

  logic->enemies[logic->enemy_num] = logic->enemy_types[enemy_type];

  (logic->enemy_types[0].num_spawned)++;
  (logic->enemy_num)++;
  (logic->next_id)++;
}

void spawn_herd(GameLogic *logic, GameWindow *window, GameDev *dev, int enemy_type, int enemy_num)
{
  // herd coords
  float y_herd = 0, x_herd = 0;

  float x_limit1 = -logic->MAP_Map_Coords.w / 2 + logic->enemy_types[enemy_type].roam_range.w;
  float x_limit2 = logic->MAP_Map_Coords.w / 2 - logic->enemy_types[enemy_type].roam_range.w;

  float y_limit1 = -logic->MAP_Map_Coords.h / 2 + logic->enemy_types[enemy_type].roam_range.w;
  float y_limit2 = logic->MAP_Map_Coords.h / 2 - logic->enemy_types[enemy_type].roam_range.w;

  int collision = 0;
  float herd_offset = logic->enemy_types[enemy_type].roam_range.w;
  int max_spawn = 0;
  do
  {
    collision = 0;

    x_herd = get_Random_Number(&(window->r), x_limit1, x_limit2);
    y_herd = get_Random_Number(&(window->r), y_limit1, y_limit2);
    real_Rect herd_coords = {x_herd, y_herd, 0, 0};

    // check for other herds
    for (int i = 0; i < logic->enemy_num; i++)
    {
      if (strcmp(logic->enemies[i].name, "SHEEP") == 0)
      {
        float distance = get_distance(herd_coords, logic->enemies[i].roam_range);
        if (distance < logic->enemies[i].roam_range.w * 2 + herd_offset)
        {
          collision = 1;
          i = logic->enemy_num;
        }
      }
    }

    for (int i = 0; i < 2; i++)
    {
      float distance = get_distance(herd_coords, logic->players[i].coords);
      if (distance < logic->enemies[i].roam_range.w * 2 + herd_offset)
      {
        collision = 1;
        i = 2;
      }
    }

    max_spawn++;
    if (max_spawn == 100000)
      break;

  } while (collision == 1);

  if (max_spawn < 10000)
  {
    logic->enemy_types[enemy_type].roam_range.x = x_herd;
    logic->enemy_types[enemy_type].roam_range.y = y_herd;

    (logic->enemy_types[enemy_type].num_spawned)++;
    logic->enemy_types[enemy_type].herd_id = logic->enemy_types[enemy_type].num_spawned;

    // indiv coords
    for (int i = 0; i < enemy_num; i++)
    {
      float ang_herd = 0;
      int distance_herd = 0;
      max_spawn = 0;

      logic->enemy_types[enemy_type].id = logic->next_id;
      logic->enemy_types[enemy_type].action_ang = get_Random_Number(&(window->r), 0, 360);

      ///TODO: spawn without collision
      // do
      // {
      //   ang_herd = get_Random_Number(&(window->r), 0, 360);
      //   distance_herd = get_Random_Number(&(window->r), 0, logic->enemy_types[enemy_type].roam_range.w);

      //   logic->enemy_types[enemy_type].coords.x = x_herd + cos(ang_herd) * distance_herd;
      //   logic->enemy_types[enemy_type].coords.y = y_herd + sin(ang_herd) * distance_herd;

      //   update_checkpoints(logic->enemy_types[enemy_type].coords, logic->enemy_types[enemy_type].checkpoints);

      //   max_spawn++;
      //   if (max_spawn == 100000)
      //     break;

      // } while (set_collision_checkpoints(logic, logic->enemy_types[enemy_type].checkpoints, logic->enemy_types[enemy_type].id) != 0);

      logic->enemies[logic->enemy_num] = logic->enemy_types[enemy_type];

      (logic->next_id)++;
      (logic->enemy_num)++;
    }
  }
}

void spawn_Obstacle(GameLogic *logic, GameWindow *window, int obstacle_type)
{

  ///TODO: redo this
  logic->obstacle_types[obstacle_type].coords.x = get_Random_Number(&(window->r), -300, 300);
  logic->obstacle_types[obstacle_type].coords.y = get_Random_Number(&(window->r), -300, 300);
  logic->obstacle_types[obstacle_type].coords.w = 200;
  logic->obstacle_types[obstacle_type].coords.h = 200;

  logic->obstacle_types[obstacle_type].id = logic->next_id;

  update_checkpoints(logic->obstacle_types[obstacle_type].coords, logic->obstacle_types[obstacle_type].checkpoints);

  logic->obstacles[logic->obstacle_num] = logic->obstacle_types[obstacle_type];

  (logic->obstacle_types[obstacle_type].num_spawned)++;
  (logic->obstacle_num)++;
  (logic->next_id)++;
}

void roam(Enemie *enemy, GameWindow *window, GameDev *dev)
{
  // if (enemy->is_moving == 1)
  // {
  //   if (enemy->init_action == 1)
  //   {
  //     // move
  //     move_enemie(&(logic->enemies[i]), logic->obstacles, logic->obstacle_num, dev->deltaTime);

  //     if (get_distance(enemy->coords, enemy->roam_range) > enemy->roam_range.w)
  //     {
  //       float range_ang = get_ang(enemy->roam_range, enemy->coords);
  //       move(enemy->speed, range_ang + 180, &(enemy->coords), enemy->checkpoints, enemy->collision_sides, dev->deltaTime);
  //       enemy->action_ang = get_Random_Number(&(window->r), range_ang + 180 - 45, enemy->action_ang + 180 + 45);

  //       enemy->delay -= 1000;
  //     }

  //     if (SDL_GetTicks() - enemy->start_count > enemy->delay)
  //     {
  //       enemy->delay = 0;
  //       enemy->start_count = 0;
  //       enemy->init_action = 0;
  //       enemy->is_moving = 0;
  //     }
  //   }
  //   else if (enemy->init_action == 0)
  //   {
  //     enemy->action_ang = get_Random_Number(&(window->r), 0, 360);
  //     enemy->start_count = SDL_GetTicks();
  //     enemy->delay = get_Random_Number(&(window->r), 5000, 7000);
  //     enemy->init_action = 1;
  //   }
  // }
  // else if (enemy->is_moving == 0)
  // {
  //   // wait
  //   if (enemy->start_count != 0)
  //   {
  //     if (SDL_GetTicks() - enemy->start_count > enemy->delay)
  //     {
  //       enemy->is_moving = 1;
  //       enemy->delay = 0;
  //       enemy->start_count = 0;
  //     }
  //   }
  //   else if (enemy->start_count == 0)
  //   {
  //     enemy->start_count = SDL_GetTicks();
  //     enemy->delay = get_Random_Number(&(window->r), 5000, 15000);
  //   }
  // }
}

void alert_herd(GameLogic *logic, Enemie *enemy, float new_speed)
{
  // detection of the first enemy
  if ((get_distance(enemy->coords, logic->players[0].coords) < enemy->detection_range && enemy->is_alerted == 0) || enemy->is_alerted == 2)
  {

    // detection of the other enemies of the same herd
    if (enemy->is_alerted == 0)
    {
      for (int i = 0; i < logic->enemy_num; i++)
      {
        if (strcmp(logic->enemies[i].name, enemy->name) == 0 && logic->enemies[i].herd_id == enemy->herd_id)
        {
          logic->enemies[i].is_alerted = 2;
          logic->enemies[i].is_moving = 0;
          logic->enemies[i].speed = new_speed;
        }
      }

      enemy->start_count = 0;
    }

    // delay for animation
    if (enemy->start_count != 0)
    {
      if (SDL_GetTicks() - enemy->start_count > enemy->delay)
      {
        for (int i = 0; i < logic->enemy_num; i++)
        {
          if (strcmp(logic->enemies[i].name, enemy->name) == 0 && logic->enemies[i].herd_id == enemy->herd_id)
          {
            logic->enemies[i].is_moving = 1;
            logic->enemies[i].is_alerted = 1;
          }
        }
      }
      else
      {
        // aiming
        for (int i = 0; i < logic->enemy_num; i++)
        {
          if (strcmp(logic->enemies[i].name, enemy->name) == 0 && logic->enemies[i].herd_id == enemy->herd_id)
          {
            logic->enemies[i].action_ang = get_ang(logic->enemies[i].coords, logic->players[0].coords);
          }
        }
      }
    }
    else if (enemy->start_count == 0)
    {
      enemy->delay = 1500;
      enemy->start_count = SDL_GetTicks();
    }
  }
}

void move_enemie(Enemie *enemie, Character player, Obstacle obstacles[], int obstacles_num, float deltaTime)
{
  ///TODO: fix bug "one enemie gets attached"
  ///TODO: fix bug "enemies stop moving"

  float vx = 1, vy = 1;

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < enemie->collision_sides[i].collision_num; j++)
    {

      if (enemie->collision_sides[i].collision_type[j] == 3)
      {
        for (int k = 0; k < obstacles_num; k++)
        {
          if (obstacles[k].id == enemie->collision_sides[i].collider_id[j])
          {

            float ang = get_ang(obstacles[k].coords, player.coords);

            for (int blocked_side = 0; blocked_side < 4; blocked_side++)
            {
              int ang_offset1 = (90 * blocked_side + (180 * (blocked_side % 2))) % 360;
              int ang_offset2 = (90 * (blocked_side + 1) + (180 * (blocked_side % 2))) % 360;

              if (i == blocked_side && ang > ang_offset1 && ang < ((int)(ang_offset1 + 90) % 361))
                enemie->action_ang = ang_offset1;

              else if (i == blocked_side && ang >= ang_offset2 && ang < ((int)(ang_offset2 + 90) % 361))
                enemie->action_ang = (ang_offset1 + 180) % 360;
            }
          }
        }
      }

      if (enemie->collision_sides[i].collision_type[j] != 0)
      {
        if (i == 1 && (enemie->action_ang > 270 || enemie->action_ang < 90))
          vx = 0;

        if (i == 3 && (enemie->action_ang > 90 && enemie->action_ang < 270))
          vx = 0;

        if (i == 0 && (enemie->action_ang > 0 && enemie->action_ang < 180))
          vy = 0;

        if (i == 2 && (enemie->action_ang > 180 && enemie->action_ang < 360))
          vy = 0;
      }
    }
  }

  float r = convert_Degree_Radiant(enemie->action_ang);
  if (vx != 0)
    vx = cos(r) * enemie->speed * deltaTime;
  if (vy != 0)
    vy = sin(r) * enemie->speed * deltaTime;

  enemie->coords.x += vx;
  enemie->coords.y += vy;

  update_checkpoints(enemie->coords, enemie->checkpoints);
}

void move_player(Character *player, Obstacle obstacles[], int obstacles_num, float deltaTime)
{
  ///TODO: add map collision
  float vx = 1, vy = 1;

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < player->collision_sides[i].collision_num; j++)
    {

      if (player->collision_sides[i].collision_type[j] == 3)
      {
        for (int k = 0; k < obstacles_num; k++)
        {

          if (obstacles[k].id == player->collision_sides[i].collider_id[j] && strcmp(obstacles[k].name, "BOX") == 0)
          {
            // slide off the box
            float ang = get_ang(player->coords, obstacles[k].coords);

            for (int action_ang = 0; action_ang <= 270; action_ang += 90)
            {
              float angle_offset_1 = (action_ang + 360 - 90) % 360;
              float angle_offset_2 = action_ang;

              if (player->action_ang == action_ang)
              {
                if (ang > angle_offset_1 && ang < angle_offset_1 + 90)
                  player->action_ang = (action_ang + 360 + 10) % 360;

                else if (ang > angle_offset_2 && ang < angle_offset_2 + 90)
                  player->action_ang = (action_ang + 360 - 10) % 360;
              }
            }

            // vx vy block
            if (i == 1 && (player->action_ang > 270 || player->action_ang < 90))
              vx = 0;

            if (i == 3 && (player->action_ang > 90 && player->action_ang < 270))
              vx = 0;

            if (i == 0 && (player->action_ang > 0 && player->action_ang < 180))
              vy = 0;

            if (i == 2 && (player->action_ang > 180 && player->action_ang < 360))
              vy = 0;
          }
        }
      }
    }
  }

  // calculating vx and vy
  float r = convert_Degree_Radiant(player->action_ang);

  if (vx != 0)
    vx = cos(r) * player->speed * deltaTime;
  if (vy != 0)
    vy = sin(r) * player->speed * deltaTime;

  player->coords.x += vx;
  player->coords.y += vy;
  player->distance_walked += player->speed * deltaTime;

  update_checkpoints(player->coords, player->checkpoints);
}

void update_checkpoints(real_Rect main_coords, real_Rect checkpoints[])
{
  for (int i = 0; i < 4; i++)
  {
    checkpoints[i].x = main_coords.x + ((main_coords.w / 2) - 1) * pow(-1, (i + 3) / 2);
    checkpoints[i].y = main_coords.y + ((main_coords.h / 2) - 1) * pow(-1, i / 2);
  }
}

float get_ang(real_Rect src, real_Rect dst)
{
  float r_ang = 0;
  float distance = get_distance(src, dst);

  if (distance == 0)
  {
    return 0;
  }

  ///TODO: deal with vertical/horizontal line edge case

  float a_sin = asin((dst.y - src.y) / distance);
  float a_cos = acos((dst.x - src.x) / distance);

  if (isnan(a_sin))
    a_sin = M_PI / 4;

  if (isnan(a_cos))
    a_cos = M_PI / 4;

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

int check_collision(real_Rect checkpoints_1[], real_Rect checkpoints_2[], real_Rect coords_1, real_Rect coords_2) // 0:noCollision - 1's:obstacle - 10's:enemy - 100's:player
{
  float checkpoint_distances[4]; // from 0:top 1:right 2:bottom 3:left

  for (int j = 0; j < 4; j++)
  {
    checkpoint_distances[0] = get_point_line_distance(checkpoints_1[j], checkpoints_2[0], checkpoints_2[1]);
    checkpoint_distances[1] = get_point_line_distance(checkpoints_1[j], checkpoints_2[1], checkpoints_2[2]);
    checkpoint_distances[2] = get_point_line_distance(checkpoints_1[j], checkpoints_2[2], checkpoints_2[3]);
    checkpoint_distances[3] = get_point_line_distance(checkpoints_1[j], checkpoints_2[3], checkpoints_2[0]);

    if (checkpoint_distances[0] + checkpoint_distances[2] < coords_2.h + 20)
    {
      if (checkpoint_distances[1] + checkpoint_distances[3] < coords_2.w + 20)
      {
        int collision_side = 0;

        get_min_max(checkpoint_distances, 4, NULL, &collision_side);

        if (collision_side == (j + 4 - 1) % 4 || collision_side == j)
          return collision_side;
      }
    }
  }

  return -1;
}
