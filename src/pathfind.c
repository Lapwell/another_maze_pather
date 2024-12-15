#include "pathfind.h"
#include "global_defines.h"
#include "find_neighbours.h"
#include "edit_tile_array.h"
#include "calc_g.h"
#include "calc_h.h"
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

// Look for the lowest F cost tile in open_list.
//    This is current working tile. Add to closed_list.
// Check neighbours:
//    If not valid for pathing, ignore.
//    Not in open_list? Add it. Record G, H, F values.
//    Is in open_list? Check G value

/*Params:
 *  List open_list: Currently traversable tiles.
 *  List closed_list: Non-traersable or already traversed.
 *  Tile *start_end[]: Ptrs to start and target tiles.
 *  Tile grid[][]: The global grid.
 *Desc: Uses the A* algorithm to find a path from a start tile to target tile.
 */
void pathfind(TileArray open_list, TileArray closed_list, Tile *start_end[2],
              Tile grid[TILE_COUNT][TILE_COUNT]) {
  Tile *working_tile;
  Tile *primary_tile;
  int lowest_f;
  // Find the tile with the lowest F cost, set as primary_tile.
  for (int count = 0; count < open_list.length; count++) {
    working_tile = &open_list.array[count];
    int g = calc_g(working_tile->rect, start_end[START_INDEX]->rect);
    int h = calc_h(working_tile->rect, start_end[END_INDEX]->rect);
    int f = g + h;
    if (f < lowest_f) {
      lowest_f = f;
      primary_tile = working_tile;
    }
  }
  // Check that a tile was actually found.
  if (!primary_tile) printf("\nError finding primary_tile in pathfind()\n"); CloseWindow(); exit(1);
  TileArray neighbours;
  neighbours.array = find_neighbours(primary_tile, grid);
  neighbours.length = MAX_NEIGHBOURS;
  for (int n_count = 0; n_count < neighbours.length; n_count++) {
    working_tile = &neighbours.array[n_count];
    // See if tile is in closed_list, if so, ignore.
    if (working_tile->closed) continue;
    // If tile is not traversable, ignore.
    if (working_tile->type != FLOOR) {
      closed_list.array = edit_tile_array(working_tile, closed_list.length, 1);
      closed_list.length++;
      working_tile->closed = true;
      continue;
    }

  }
}

