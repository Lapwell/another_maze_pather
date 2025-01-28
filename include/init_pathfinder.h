#ifndef INIT_PATHFINDER_
#define INIT_PATHFINDER_

#include "global_defines.h"

/* Params:
 *  TileArray open_list: Traversable tiles
 *  Tile Array closed_list: Non-Traversable tiles
 * Desc:
 */
void init_pathfinder(TileArray open_list, TileArray closed_list,
                     Tile start_end[2], Tile grid[TILE_COUNT][TILE_COUNT]);

#endif // !INIT_PATHFINDER_
