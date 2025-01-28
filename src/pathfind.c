#include "pathfind.h"
#include "global_defines.h"
#include "find_neighbours.h"
#include "edit_tile_array.h"
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

// Look for the lowest F cost tile in open_list.
//    This is current working tile. Add to closed_list.
// Check neighbours:
//    If not valid for pathing, ignore.
//    Not in open_list? Add it. Record G, H, F values.
//    Is in open_list? Check G value

/* Params:
 *  List open_list: Currently traversable tiles.
 *  List closed_list: Non-traersable or already traversed.
 *  Tile *start_end[]: Ptrs to start and target tiles.
 *  Tile grid[][]: The global grid.
 * Desc: Uses the A* algorithm to find a path from a start tile to target tile.
 */
void pathfind(TileArray *open_list, TileArray *closed_list, Tile start_end[2],
              Tile grid[TILE_COUNT][TILE_COUNT]) {

  printf("STARTING PATHFIND...\n");
  // Init needed things here
  Tile *neighbours[MAX_NEIGHBOURS];
  Tile start_tile = start_end[0]; // 0 is the start_tile
  open_list->array[0] = start_tile;
  int lowest_f;

  // The start tile is the first one to be checked. Get its neighbours and start from there
  find_neighbours(&start_tile, grid, neighbours);
  for (int count = 0; count < MAX_NEIGHBOURS; count++) {
    Tile *working_tile = neighbours[count];
  }
}
