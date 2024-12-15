#include "grid_manipulator.h"
#include "raylib.h"
#include "global_defines.h"
#include "mouse_input.h"
#include "set_tile.h"

void manipulateGrid(Tile grid[TILE_COUNT][TILE_COUNT], Tile *start_end[2]) {
  Vector2 mouse_pos;
  int button_pressed;
  getMouseInput(&mouse_pos, &button_pressed);
  // Check if user actually clicked -999 is used as no input
  if (mouse_pos.x && mouse_pos.y) {
    int row, col;
    //Find the row (and col below it) of the tile clicked
    row = mouse_pos.y / (TILE_COUNT + TILE_PAD);
    col = mouse_pos.x / (TILE_COUNT + TILE_PAD);
    Tile *clicked = &grid[row][col];
    switch (button_pressed) {
      case MOUSE_BUTTON_LEFT:
        // Check if clicked is start/end. if we dont do this, it can cause
        // start/end (now walls) to disappear when setting new start/ends.
        if (clicked->type == START) {
          start_end[START_INDEX] = &NULL_TILE;
        } else if (clicked->type == END) {
          start_end[END_INDEX] = &NULL_TILE;
        }
        // Set tile takes a ptr to a tile and updates its values to the passed type
        setTile(clicked, WALL);
        break;
      case MOUSE_BUTTON_RIGHT:
        if (clicked->type == FLOOR) break;
        // Same as walls above, just for floors (though, probably redundant).
        if (clicked->type == START) {
          start_end[START_INDEX] = &NULL_TILE;
        } else if (clicked->type == END) {
          start_end[END_INDEX] = &NULL_TILE;
        }
        setTile(clicked, FLOOR);
        break;
      case MOUSE_BUTTON_MIDDLE:
        // Each middle click cycles the tile: FLOOR > START> END > FLOOR
        if (clicked->type == FLOOR) {
          setTile(clicked, START);
          setTile(start_end[START_INDEX], FLOOR);
          // start_end is used for the algo, so we need to update it too
          start_end[START_INDEX] = clicked;
        } else if (clicked->type == START) {
          setTile(clicked, END);
          setTile(start_end[END_INDEX], FLOOR);
          // If not cleared, both START_INDEX & END_INDEX point to the same tile.
          // So, we trying to move START around will clear END each time. Not good.
          start_end[START_INDEX] = &NULL_TILE;
          start_end[END_INDEX] = clicked;
        } else if (clicked->type == END) {
          setTile(clicked, FLOOR);
          start_end[END_INDEX] = &NULL_TILE;
        }
        break;
      default:
        break;
    }
  }
}

