#include "global_defines.h"
#include "grid_objects.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Params
 * Desc: Initializes open_list, entities, any such
 * Rectangle open[]: the grid to display and traverse.
 */
void initialize(int *window_width, int *window_height, Tile open[TILE_COUNT][TILE_COUNT], Tile start_end[2]) {
  int start_rand_r, start_rand_c, end_rand_r, end_rand_c; // Used to setting random tiles to start/end
  start_rand_r = start_rand_c = rand() % TILE_COUNT + 1;
  srand(time(NULL)); // Only called once. Sets the seed for rand() using the time
  // Init the open grid array
  for (int r = 0; r < TILE_COUNT; r++) {
    for (int c = 0; c < TILE_COUNT; c++) {
      // Reason for the adding TILE_PAD is to shift everything over a little
      // For the left side pad colour to be visible. If not, tiles are flush
      open[r][c] = (Tile) {.rect = {(TILE_SIZE * c) + TILE_PAD, (TILE_SIZE * r) + TILE_PAD,
                            TILE_SIZE, TILE_SIZE}, .type = FLOOR, .colour = WHITE};
    }
  }
  // Set a random tile to be the start.
  open[start_rand_r][start_rand_c].type = START;
  open[start_rand_r][start_rand_c].colour = GREEN;
  start_end[0] = open[start_rand_r][start_rand_r];

  // Set a random tile to be the end. Make sure it's not the start.
  end_rand_r = end_rand_c = rand() % TILE_COUNT + 1;
  while (start_rand_r == end_rand_r || start_rand_c == end_rand_c) {
    end_rand_r = end_rand_c = rand() % TILE_COUNT + 1;
  }
  open[end_rand_r][end_rand_c].type = END;
  open[end_rand_r][end_rand_c].colour = RED;
  start_end[1] = open[end_rand_r][end_rand_c];

  // Reason for the extra parenthesis: add a little extra space for the right side
  // outline colour. If not, the tiles are flush with the window.
  *window_width = *window_height = ((TILE_SIZE + TILE_PAD) * TILE_COUNT) + TILE_PAD;
}

void drawGrid(Tile grid[TILE_COUNT][TILE_COUNT]) {
  for (int r = 0; r < TILE_COUNT; r++) {
    for (int c = 0; c < TILE_COUNT; c++) {
      Tile tile = grid[r][c];
      DrawRectangleRec((Rectangle) {tile.rect.x + (TILE_PAD * c), tile.rect.y + (TILE_PAD * r),
                                              tile.rect.width, tile.rect.height}, tile.colour);
    }
  }
}

int main() {
  Tile open_list[TILE_COUNT][TILE_COUNT];
  Tile closed_list[TILE_COUNT][TILE_COUNT];
  Tile start_end[2];
  int window_width, window_height;
  initialize(&window_width, &window_height, open_list, start_end); // This sets some initial data for open_list, creates entities, and loads necassary data
  printf("\n\nw: %i || h: %i\n\n", window_width, window_height);
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(window_width, window_height, "Maze Pather");
  SetTargetFPS(60);
  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    drawGrid(open_list);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

