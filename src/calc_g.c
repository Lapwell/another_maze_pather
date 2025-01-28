#include "calc_g.h"
#include "global_defines.h"
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void calc_g(Rectangle start, Tile grid[TILE_COUNT][TILE_COUNT]) {
  int start_pos[2] = {abs((int)round(start.x / (TILE_SIZE + TILE_PAD))),
                      abs((int)round(start.y / (TILE_SIZE + TILE_PAD)))};
  for (int row = 0; row < TILE_COUNT; row++) {
    for (int col = 0; col < TILE_COUNT; col++) {
      Tile *tile = &grid[row][col];
      int x = col - start_pos[0];
      int y = row - start_pos[1];
      int g = abs(x) + abs(y);

      if (start.x == tile->rect.x && start.y == tile->rect.y) {
        tile->g = 0;
      } else {
        tile->g = g;
      }
    }
  }
}

