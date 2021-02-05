#include "../headers/renderer.h"
#include "../headers/dev.h"

void renderer_manager(GameObject *G)
{

  render_firstLayer(&(G->window));

  if (G->dev.show_FPS)
    render_FPS(&(G->window), &(G->ui), G->dev);

  update_window(&(G->window));
}