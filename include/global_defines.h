#ifndef GLOBAL_DEFINES_
#define GLOBAL_DEFINES_

#include "raylib.h"

#define TILE_COUNT 32
#define TILE_SIZE 32
#define TILE_COLOUR WHITE
#define TILE_PAD 4
#define MAX_NEIGHBOURS 4;

#define START 's'
#define END 'e'
#define FLOOR 'f'
#define WALL 'w'

#define START_INDEX 0
#define END_INDEX 1

#define MAX_RAND 100

typedef struct Tile {
  Rectangle rect;
  Color colour;
  char type;
  int g;
  int h;
  int f;
  bool open;
  bool closed;
} Tile;

typedef struct TileArray {
  Tile *array;
  int length;
} TileArray;

#define NULL_TILE (Tile) {.rect={-999,-999,0,0}, .colour=PINK, .type='N', .g=-999, .h=-999}

#endif // !GLOBAL_DEFINES_
