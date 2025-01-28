#include "raylib.h"
#include "global_defines.h"

/*Params:
 * Rectangle tile: Current working tile to find g for.
 * Rectangle start: The tile to find distance from.
 *Desc: Finds the g value used in the A* algo.
 */
void calc_g(Rectangle start, Tile grid[TILE_COUNT][TILE_COUNT]);

