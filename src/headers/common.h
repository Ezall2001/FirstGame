#ifndef COMMON_H_DEFINED
#define COMMON_H_DEFINED

#include "./GameStructs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

typedef struct
{
  GameWindow window;
  GameDev dev;
  GameInput input;
  GameSound sound;
  GameLogic logic;
  GameUI UI;

} GameObject;

// utils
void lib_errorLog(char msg[], const char *error);
void coords_log(float x, float y, float w, float h);
void load_Texture_Img(SDL_Texture **texture, char path[], SDL_Renderer **renderer);
void load_Texture_Text(SDL_Texture **texture, TTF_Font **font, char text[], SDL_Color color, SDL_Renderer **renderer);
void load_Sprite(SDL_Texture **texture, int num, char path[], SDL_Renderer **renderer);
float get_Text_W_ratio(TTF_Font *font, char text[]);
SDL_Color set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void set_Texture_Opacity(SDL_Texture *texture, int opacity);
int get_Random_Number(MTRand *r, int min, int max);
float convert_Radiant_Degree(float r);
float convert_Degree_Radiant(float d);
void convert_REAL_SDL(SDL_Rect *s_coords, real_Rect r_coords, real_Rect cam_coords, float w_ratio, float w, float h);
int DrawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius);

#endif