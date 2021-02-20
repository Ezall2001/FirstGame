#ifndef EVENT_H_DEFINED
#define EVENT_H_DEFINED

#include "./common.h"

void event_manager(GameObject *G);

void window_events(SDL_Event *event, GameObject *G);
void mouse_motion_events(SDL_Event *event, GameObject *G);
void keyboard_Input(SDL_Event *event, GameInput *input);
void mouse_Input(SDL_Event *event, GameObject *G);

#endif