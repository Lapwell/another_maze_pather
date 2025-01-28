#include "find_neighbours.h"
#include "global_defines.h"
#include <raylib.h>

void find_neighbours(Tile *tile, Tile grid[TILE_COUNT][TILE_COUNT], Tile *neighbours[MAX_NEIGHBOURS]) {
  // Get ROW and COL of the target tile
  int target_col = (int)(tile->rect.x / TILE_SIZE);
  int target_row = (int)(tile->rect.y / TILE_SIZE);

  // Get the address of the neighbouring tiles to the target
  neighbours[0] = &grid[target_row - 1][target_col]; // North
  grid[target_row - 1][target_col].colour = BROWN;
  neighbours[1] = &grid[target_row + 1][target_col]; // South
  grid[target_row + 1][target_col].colour = PURPLE;
  neighbours[2] = &grid[target_row][target_col + 1]; // East
  grid[target_row][target_col + 1].colour = PINK;
  neighbours[3] = &grid[target_row][target_col - 1]; // West
  grid[target_row][target_col - 1].colour = YELLOW;
}

