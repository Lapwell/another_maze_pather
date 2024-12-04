#ifndef GRID_OBJECTS_
#define GRID_OBJECTS_

#include <raylib.h>

typedef struct Tile {
  Rectangle rect;
  Color colour;
  char type;
} Tile;

#endif // !GRID_OBJECTS_
