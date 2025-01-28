#include "calc_h.h"
#include "global_defines.h"
#include "raylib.h"
#include "stdlib.h"

void calc_h(Rectangle end, Tile grid[TILE_COUNT][TILE_COUNT]) {
  for (int row = 0; row < TILE_COUNT; row++) {
    for (int col = 0; col < TILE_COUNT; col++) {
      Tile *tile = &grid[row][col];
      //if (tile->rect.x == end.x && tile->rect.y == end.y) tile->h = 0;
      int a = abs((int)(tile->rect.x / (TILE_SIZE + TILE_PAD)) - (int)(end.x / (TILE_SIZE + TILE_PAD)));
      int b = abs((int)(tile->rect.y / (TILE_SIZE + TILE_PAD)) - (int)(end.y / (TILE_SIZE + TILE_PAD)));
      tile->h = a + b;
    }
  }
}

