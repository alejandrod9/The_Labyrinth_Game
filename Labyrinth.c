#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab.h"

int main() {
  Labyrinth lab_game = Create_Labyrinth(SIZE);
  Print_Random_Labyrinth(lab_game);
  // Swap(lab_game);
  Game_Delete(lab_game);
  return EXIT_SUCCESS;
}
//