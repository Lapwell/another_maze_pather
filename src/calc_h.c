#include "calc_h.h"
#include "global_defines.h"
#include "raylib.h"
#include "stdlib.h"

int calc_h(Rectangle tile, Rectangle end) {
  int a = abs((int)(tile.x / (TILE_SIZE + TILE_PAD) - end.x / (TILE_SIZE + TILE_PAD))) * 2;
  int b = abs((int)(tile.y / (TILE_SIZE + TILE_PAD) - end.y / (TILE_SIZE + TILE_PAD))) * 2;
  return a + b;
}

