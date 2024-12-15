#include "mouse_input.h"
#include "raylib.h"
#include <stdio.h>

/* Params: Vec2 ptr int ptr
 * Desc: Determines what mouse buttons are being pressed.
 */
void getMouseInput(Vector2 *pos, int *button) {
  *pos = GetMousePosition();
  if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
    printf("BUTTON LEFT");
    *button = MOUSE_BUTTON_LEFT;
  } else if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
    printf("BUTTON RIGHTT");
    *button = MOUSE_BUTTON_RIGHT;
  } else if (IsMouseButtonReleased(MOUSE_BUTTON_MIDDLE)) {
    printf("BUTTON MIDDLE");
    *button = MOUSE_BUTTON_MIDDLE;
  } else {
    *button = -1;
  }
}

