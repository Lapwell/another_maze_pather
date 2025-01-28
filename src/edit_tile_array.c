#include "edit_tile_array.h"
#include "global_defines.h"
#include <stdlib.h>
#include <stdio.h>

Tile *edit_tile_array(Tile old_array[], int length, int new_length) {
  Tile *new_array = realloc(old_array, (length + new_length) * sizeof(Tile));
  if (!new_array) {
    printf("\nError changing array in edit_array()\n");
    return NULL;
  } else {
    return new_array;
  }
}

