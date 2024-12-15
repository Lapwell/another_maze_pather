#include "set_tile.h"
#include "global_defines.h"
#include "raylib.h"

void setTile(Tile *tile, char type) {
  switch (type) {
    case FLOOR:
      tile->type = FLOOR;
      tile->colour = WHITE;
      break;
    case WALL:
      tile->type = WALL;
      tile->colour = GRAY;
      break;
    case START:
      tile->type = START;
      tile->colour = GREEN;
      break;
    case END:
      tile->type = END;
      tile->colour = RED;
      break;
  }
}

