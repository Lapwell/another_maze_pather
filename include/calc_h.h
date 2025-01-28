#ifndef CALC_H_
#define CALC_H_

#include "raylib.h"
#include "global_defines.h"

/* Params:
 *  Rectangle *tile: The tile to find h for.
 *  Rectangle : The tile to find h from the *tile.
 * Desc: Finds the h value of a given tile
 */
void calc_h(Rectangle end, Tile grid[TILE_COUNT][TILE_COUNT]);

#endif // !CALC_H_

