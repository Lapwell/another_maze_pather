#include "calc_g.h"
#include "raylib.h"
#include <stdlib.h>

int calc_g(Rectangle tile, Rectangle start) {
  return abs((int){start.y - tile.y}) / abs((int){start.x - tile.x});
}

