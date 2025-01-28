#include "init_pathfinder.h"
#include "global_defines.h"
#include "find_neighbours.h"
#include "edit_tile_array.h"
#include <stdlib.h>
#include <stdio.h>

void init_pathfinder(TileArray open_list, TileArray closed_list,
                     Tile start_end[2], Tile grid[TILE_COUNT][TILE_COUNT]) {
    if (open_list.array[0].type == START) {
      Tile *working_tile = &open_list.array[0];
      TileArray neighbours = {.array = find_neighbours(working_tile, grid), .length = MAX_NEIGHBOURS};
      // Start from the end of the list. We do this because shrinking the arrays
      // shrinking is right to left.
      for (int count = neighbours.length; count >= 0 ; count--) {
        working_tile = &neighbours.array[count];
        // If not a valid tile, add to the ignore
        if (working_tile->type != FLOOR) {
          Tile *new_closed = edit_tile_array(closed_list.array, closed_list.length, 1);
          if (!new_closed) {
            printf("ERROR SETTING NEW_CLOSED IN INIT_PATHFINDER()...\n");
            exit(1);
          }
        } else if (working_tile->type == FLOOR) {
          // If it's a valid tile, add it to the open_list
          Tile *new_open = edit_tile_array(open_list.array, open_list.length, 1);
          if (!new_open) {
            printf("ERROR SETTING NEW_OPEN IN INIT_PATHFINDER()...\n");
            exit(1);
          }
          open_list.array = new_open;
        }
      }
    }
}

