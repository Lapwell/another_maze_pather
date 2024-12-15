#ifndef CALC_H_
#define CALC_H_

#include "raylib.h"

/* Params:
 *  Rectangle *tile: The tile to find h for.
 *  Rectangle : The tile to find h from the *tile.
 * Desc: Finds the h value of a given tile
 */
int calc_h(Rectangle tile, Rectangle end);

#endif // !CALC_H_

