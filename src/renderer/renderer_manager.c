#include "../headers/renderer.h"
#include "../headers/dev.h"

void renderer_manager(GameObject *G)
{

  render_firstLayer(&(G->window));

  render_FPS(&(G->window), &(G->ui), G->dev);

  update_window(&(G->window));
}