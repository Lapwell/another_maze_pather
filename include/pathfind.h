#ifndef PATHFIND_
#define PATHFIND_

#include "global_defines.h"

/*Params:
 *  List open_list: Valid tiles for pathfinding.
 *  List closed_list: Non-valid tiles for pathfinding.
 *  Tile *start_end[]: Pointers to the start/end tiles.
 *  Tile grid[][]: Global tile array.
 *Desc: Will use the A* algorithm to find a way from start to end tiles.
 */
void pathfind(TileArray *open_list, TileArray *closed_list,
              Tile start_end[2], Tile grid[TILE_COUNT][TILE_COUNT]);

#endif // !PATHFIND_

