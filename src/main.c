#include "global_defines.h"
#include "grid_manipulator.h"
#include "pathfind.h"
#include "calc_g.h"
#include "calc_h.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TILE_FLOOR (Tile) {.rect = {(TILE_SIZE * c) + TILE_PAD, (TILE_SIZE * r) + TILE_PAD, TILE_SIZE, TILE_SIZE}, .type = FLOOR, .colour = WHITE}

/* Params
 * Rectangle open[]: the grid to display and traverse.
 * Desc: Initializes open_list, entities, any such
 */
void initialize(int *window_width, int *window_height, Tile grid[TILE_COUNT][TILE_COUNT],
                Tile *start_end[2], TileArray *open) {

  // Move onto creating the grid, start tile, and end tile
  int start_rand_r, start_rand_c, end_rand_r, end_rand_c; // Used to setting random tiles to start/end
  srand(time(NULL)); // Only called once. Sets the seed for rand() using the time
  start_rand_r = rand() % TILE_COUNT;
  start_rand_c = rand() % TILE_COUNT;
  // Init the open grid array
  for (int r = 0; r < TILE_COUNT; r++) {
    for (int c = 0; c < TILE_COUNT; c++) {
      grid[r][c] = TILE_FLOOR;
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
  open->array[0] = *start_end[START_INDEX];

  // Calc the G and H values of the grid.
  calc_g(start_end[START_INDEX]->rect, grid);
  calc_h(start_end[END_INDEX]->rect, grid);

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
      DrawText(TextFormat("%i", grid_tile.g), TILE_PAD + grid_pos.x, grid_pos.y, 24, RED); // Distance from START
//      DrawText(TextFormat("%i", grid_tile.h), grid_pos.x + (int)(TILE_SIZE / 1.75), grid_pos.y, 24, BLUE); // H is the distance from END
//      DrawText(TextFormat("%i", grid_tile.f), grid_pos.x + (int)(TILE_SIZE / 3), grid_pos.y + (int)(TILE_SIZE / 2), 24, PURPLE); // F = G + H
    }
  }
}

int main() {
  Tile grid_list[TILE_COUNT][TILE_COUNT];

  // Init the open_list and closed_lists, check if they init.
  Tile *open_init_array = (Tile*)malloc(sizeof(Tile));
  Tile *closed_init_array = (Tile*)malloc(sizeof(Tile));
  if (!open_init_array) {
    printf("Failure initializing 'open_init_array'...");
    exit(1);
  }

  if (!closed_init_array) {
    printf("Failure initializing 'closed_init_array");
    exit(1);
  }

  TileArray open_list = {.array = open_init_array, .length = 1};
  TileArray closed_list = {.array = closed_init_array, .length = 1};
  Tile *start_end[2];
  int window_width, window_height;
  // This sets some initial data for open_list, creates entities, and loads necassary data
  initialize(&window_width, &window_height, grid_list, start_end, &open_list);
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

