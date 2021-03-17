#ifndef DEV_H_DEFINED
#define DEV_H_DEFINED

#include "./common.h"

void dev_manager(int *argc, char *argv[], GameObject *G);
void dev_loop(GameObject *G);

// flags
void set_fullScreen(char flag[], GameWindow *window);
void set_FPS(char flag[], GameDev *dev);
void set_FPS_cap(char flag[], GameDev *dev);
void set_mute(char flag[], GameSound *sound);
void set_sprites(char flag[]);
void set_boxes(char flag[], GameDev *dev);
void set_ranges(char flag[], GameDev *dev);
void set_directions(char flag[], GameDev *dev);
void set_spawn(char flag[], GameDev *dev);
void set_character(char flag[], GameDev *dev);
void set_enemy(char flag[], GameDev *dev);
void set_full_dev(char flag[], GameDev *dev);

// scenarios
void proto1(char scn[], GameObject *G);
void lvl_simulation(char scn[]);
void responsive_UI(char scn[]);
void projectile_test(char scn[]);

//main loop
void calcFPS(GameDev *dev);
void set_DeltaTime(GameDev *dev);
void change_character(GameLogic *logic, GameInput *input);
void spawn_enemie(GameLogic *logic, GameInput *input, GameWindow *window, GameDev *dev);
void set_Boxes_Coords(GameLogic *logic, DevUI *ui);
void set_Ranges_Coords(GameLogic *logic, DevUI *ui);
void set_Directions_Coords(GameLogic *logic, DevUI *ui);
void set_Distances_Coords(GameLogic *logic, DevUI *ui);

//direct call functions
void cap_FPS(GameDev dev);

#endif
