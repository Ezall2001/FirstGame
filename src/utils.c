#include "./headers/common.h"

void load_Texture_Img(SDL_Texture **texture, char path[], SDL_Renderer **renderer)
{
  SDL_Surface *tempSurface = NULL;
  SDL_RWops *tempPath = NULL;

  tempPath = tempPath = SDL_RWFromFile(path, "rb");
  if (tempPath == NULL)
    lib_errorLog("failed at getting img path", SDL_GetError());

  tempSurface = IMG_LoadPNG_RW(tempPath);
  if (tempSurface == NULL)
    lib_errorLog("failed at loading img from path", IMG_GetError());

  SDL_DestroyTexture(*texture);
  *texture = SDL_CreateTextureFromSurface(*renderer, tempSurface);

  SDL_FreeSurface(tempSurface);
  SDL_FreeRW(tempPath);
}

void load_Sprite(SDL_Texture *texture[], int num, char path[], SDL_Renderer **renderer)
{
  char complete_Path[100];
  for (int i = 0; i < num; i++)
  {
    char img_num[3];
    itoa(i, img_num, 10);

    strcpy(complete_Path, path);
    strcat(complete_Path, img_num);
    strcat(complete_Path, ".png\0");

    texture[i] = NULL;
    load_Texture_Img(&(texture[i]), complete_Path, renderer);
  }
}

void load_Texture_Text(SDL_Texture **texture, TTF_Font **font, char text[], SDL_Color color, SDL_Renderer **renderer)
{
  SDL_Surface *tempSurface = NULL;

  tempSurface = TTF_RenderUTF8_Blended(*font, text, color);
  if (tempSurface == NULL)
    lib_errorLog("failed at rendering font", TTF_GetError());

  SDL_DestroyTexture(*texture);
  *texture = SDL_CreateTextureFromSurface(*renderer, tempSurface);

  if (*texture == NULL)
  {
    lib_errorLog("failed at creating texture from font", SDL_GetError());
  }

  SDL_FreeSurface(tempSurface);
}

float get_Text_W_ratio(TTF_Font *font, char text[])
{
  int text_w = 0, text_h = 0;
  float text_w_ratio = 1;

  int mesure = TTF_SizeUTF8(font, text, &text_w, &text_h);
  if (mesure != 0)
    lib_errorLog("failed at calculating the text mesures", TTF_GetError());

  text_w_ratio = (float)text_h / text_w;
  return text_w_ratio;
}

SDL_Color set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  SDL_Color color = {0, 0, 0, 0};
  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;

  return color;
}

void lib_errorLog(char msg[], const char *error)
{
  printf("%s: %s\n", msg, error);
}

void coords_log(float x, float y, float w, float h)
{
  printf("x: %.3f   y: %.3f   w: %.3f   h: %.3f\n", x, y, w, h);
}

int get_Random_Number(MTRand *r, int min, int max)
{
  int rd = (genRandLong(r) % (max - min + 1)) + min;
  return rd;
}

float convert_Radiant_Degree(float r)
{
  float d = 0;

  if (r < 0)
    r += 2 * M_PI;

  d = r * (float)180 / M_PI;

  return d;
}

float convert_Degree_Radiant(float d)
{
  float r = 0;

  r = d * M_PI / 180;

  return r;
}

void convert_REAL_SDL(SDL_Rect *s_coords, real_Rect r_coords, real_Rect cam_coords, float w_ratio, float w, float h)
{
  s_coords->w = w * w_ratio;
  s_coords->h = h * w_ratio;
  s_coords->x = (r_coords.x - cam_coords.x - (w / 2)) * w_ratio;
  s_coords->y = (cam_coords.y - r_coords.y - (h / 2)) * w_ratio;
}

void set_Texture_Opacity(SDL_Texture *texture, int opacity)
{
  int set_opacity = SDL_SetTextureAlphaMod(texture, opacity);
  if (set_opacity != 0)
    lib_errorLog("failed at setting opacity", SDL_GetError());
}

int DrawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
  int outline = 0;
  const int32_t diameter = (radius * 2);
  centreX += radius / 2;
  centreY += radius / 2;

  int32_t x = (radius - 1);
  int32_t y = 0;
  int32_t tx = 1;
  int32_t ty = 1;
  int32_t error = (tx - diameter);

  while (x >= y)
  {
    //  Each of the following renders an octant of the circle
    outline += SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
    outline += SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
    outline += SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
    outline += SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
    outline += SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
    outline += SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
    outline += SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
    outline += SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

    if (error <= 0)
    {
      ++y;
      error += ty;
      ty += 2;
    }

    if (error > 0)
    {
      --x;
      tx += 2;
      error += (tx - diameter);
    }
  }
  return outline;
}

float get_distance(real_Rect p1, real_Rect p2)
{
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float get_point_line_distance(real_Rect p, real_Rect l1, real_Rect l2)
{
  real_Rect l1_p_l2 = {p.x, p.y, 0, 0};
  if (fabs(l1.x - l2.x) < 1)
  {
    l1_p_l2.x = l1.x;
  }
  else if (fabs(l1.y - l2.y) < 1)
  {
    l1_p_l2.y = l1.y;
  }

  return get_distance(p, l1_p_l2);
}

void sort_array(float nums[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = i; j < size; j++)
    {
      if (nums[j] < nums[i])
      {
        float temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
  }
}

void get_min_max(float nums[], int size, int *min_index, int *max_index)
{
  float max_val = 0, min_val = 0;
  min_val = nums[0];
  max_val = nums[0];

  for (int i = 1; i < size; i++)
  {
    if (nums[i] < min_val)
    {
      min_val = nums[i];
      if (min_index != NULL)
        *min_index = i;
    }

    if (nums[i] > max_val)
    {
      max_val = nums[i];
      if (max_index != NULL)
        *max_index = i;
    }
  }
}

void deMask(int demask[], int mask)
{
  int index = 0;
  while (mask > 0)
  {
    demask[index] = mask % 10;

    mask /= 10;
    index++;
  }
}
