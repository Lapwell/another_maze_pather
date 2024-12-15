#include "find_neighbours.h"
#include "global_defines.h"
#include <stdlib.h>

Tile* find_neighbours(Tile *tile, Tile grid[TILE_COUNT][TILE_COUNT]) {
  Vector2 grid_pos = {tile->rect.x / (TILE_SIZE + TILE_PAD),
                      tile->rect.y / (TILE_SIZE + TILE_PAD)};
  Tile *neighbours = (Tile*)malloc(sizeof(Tile) * 4);
  neighbours[0] = grid[(int)grid_pos.x - 1][(int)grid_pos.y];
  neighbours[1] = grid[(int)grid_pos.x + 1][(int)grid_pos.y];
  neighbours[2] = grid[(int)grid_pos.x][(int)grid_pos.y + 1];
  neighbours[3] = grid[(int)grid_pos.x][(int)grid_pos.y - 1];
  return neighbours;
}

