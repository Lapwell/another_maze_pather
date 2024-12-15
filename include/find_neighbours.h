#ifndef FIND_NEIGHBOURS_
#define FIND_NEIGHBOURS_

#include "global_defines.h"

/*Params:
 *  Tile *tile: Find this tile's neighbours.
 *  Tile grid[][]: The global grid of tiles.
 *Desc: Finds the neighbours in the cardinal directions of the given tile
 *      and returns a ptr array storing the tiles.
 */
Tile* find_neighbours(Tile *tile, Tile grid[TILE_COUNT][TILE_COUNT]);

#endif // !FIND_NEIGHBOURS_

