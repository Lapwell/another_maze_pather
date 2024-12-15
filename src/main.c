#include "global_defines.h"
#include "grid_manipulator.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Params
 * Rectangle open[]: the grid to display and traverse.
 * Desc: Initializes open_list, entities, any such
 */
void initialize(int *window_width, int *window_height, Tile grid[TILE_COUNT][TILE_COUNT],
                Tile *start_end[2], TileArray open) {
  int start_rand_r, start_rand_c, end_rand_r, end_rand_c; // Used to setting random tiles to start/end
  srand(time(NULL)); // Only called once. Sets the seed for rand() using the time
  start_rand_r = rand() % TILE_COUNT;
  start_rand_c = rand() % TILE_COUNT;
  // Init the open grid array
  for (int r = 0; r < TILE_COUNT; r++) {
    for (int c = 0; c < TILE_COUNT; c++) {
      // Reason for the adding TILE_PAD is to shift everything over a little
      // For the left side pad colour to be visible. If not, tiles are flush
      grid[r][c] = (Tile) {.rect = {(TILE_SIZE * c) + TILE_PAD, (TILE_SIZE * r) + TILE_PAD,
                           TILE_SIZE, TILE_SIZE}, .type = FLOOR, .colour = WHITE, .g=0};
    }
  }
  // Set a random tile to be the start.
  grid[start_rand_r][start_rand_c].type = START;
  grid[start_rand_r][start_rand_c].colour = GREEN;
  start_end[START_INDEX] = &grid[start_rand_r][start_rand_c];

  // Set a random tile to be the end. Make sure it's not the start.
  end_rand_r = rand() % TILE_COUNT;
  end_rand_c = rand() % TILE_COUNT;
  while (start_rand_r == end_rand_r || start_rand_c == end_rand_c) {
    end_rand_r = rand() % TILE_COUNT;
    end_rand_c = rand() % TILE_COUNT;
  }
  grid[end_rand_r][end_rand_c].type = END;
  grid[end_rand_r][end_rand_c].colour = RED;
  start_end[END_INDEX] = &grid[end_rand_r][end_rand_c];

  // Start the open list at the start tile
  open.array[0] = *start_end[START_INDEX];

  // Reason for the extra parenthesis: add a little extra space for the right side
  // outline colour. If not, the tiles are flush with the window.
  *window_width = *window_height = ((TILE_SIZE + TILE_PAD) * TILE_COUNT) + TILE_PAD;
}

/* Params:
 *   Tile grid: the grid to draw
 * Desc: Draws a grid. What else?
 */
void drawGrid(Tile grid[TILE_COUNT][TILE_COUNT]) {
  for (int r = 0; r < TILE_COUNT; r++) {
    for (int c = 0; c < TILE_COUNT; c++) {
      Tile grid_tile = grid[r][c]; // For rendering the tile
      // Values for the size and pos of the tile
      Vector2 grid_pos = {grid_tile.rect.x + (TILE_PAD * c),
                          grid_tile.rect.y + (TILE_PAD * r)};
      // Draw the tile
      DrawRectangleRec((Rectangle) {grid_pos.x, grid_pos.y,
                                    grid_tile.rect.width, grid_tile.rect.height},
                                    grid_tile.colour);
    }
  }
}

int main() {
  Tile grid_list[TILE_COUNT][TILE_COUNT];
  TileArray open_list = {.array = (Tile*)malloc(sizeof(Tile)) , .length = 1};
  TileArray closed_list = {.array = (Tile*)malloc(sizeof(Tile)), .length = 1};
  Tile *start_end[2];
  int window_width, window_height;
  // This sets some initial data for open_list, creates entities, and loads necassary data
  initialize(&window_width, &window_height, grid_list, start_end, open_list);
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(window_width, window_height, "Maze Pather");
  SetTargetFPS(60);
  while(!WindowShouldClose()) {
    manipulateGrid(grid_list, start_end);
    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    drawGrid(grid_list);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

