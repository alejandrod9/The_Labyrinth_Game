#include "lab.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int uint;

typedef struct Labyrinth_s {
  uint *init;
  uint *game;
  uint size;

} Labyrinth_s;

Labyrinth Create_Labyrinth(uint size) {
  if (size <= 0) {
    fprintf(stderr, "Invalid size. Size must be greater than 0./n");
    exit(EXIT_FAILURE);
  }

  Labyrinth maze = (Labyrinth)malloc(sizeof(Labyrinth));
  if (maze == NULL) {
    fprintf(stderr, "Wrong malloc, not enough memory\n");
    exit(EXIT_FAILURE);
  }

  maze->game = malloc(size * sizeof(Labyrinth));
  if (maze == NULL) {
    fprintf(stderr, "Wrong malloc, not enough memory\n");
    exit(EXIT_FAILURE);
  }
  maze->size = size;

  return maze;
  free(maze);
  maze = NULL;
}

void Free_Labyrinth(Labyrinth maze) {
  if (maze == NULL) {
    fprintf(stderr, "There is nothing to free.\n");
    exit(EXIT_FAILURE);
  }

  if (maze->game == NULL) {
    free(maze);
  }
  free(maze->game);
  maze->game = NULL;
  free(maze);
  maze = NULL;

  // return EXIT_SUCCESS;  // ?
}

Labyrinth Print_Random_Labyrinth(Labyrinth maze) {
  srand(time(NULL));
  if (maze == NULL || maze->game == NULL) {
    fprintf(stderr, "Wrong malloc, not enough memory\n");
    exit(EXIT_FAILURE);
  }
  // uint main_path = 0;
  uint starting_or_exiting_point = rand() % SIZE;
  for (uint x = 0; x < SIZE; x++) {
    for (uint y = 0; y < SIZE; y++) {
      if (x == SIZE - 1 && y == starting_or_exiting_point) {
        printf("S");
      }  // Starting Point
      if (x == starting_or_exiting_point && y == SIZE - 1) {
        printf("E");
      } else if (x == 0 || x == SIZE - 1 || y == 0 ||
                 y == SIZE - 1) {  // Borders
        printf("x");               // Exiting Point
      } else {
        uint cells = rand() % 2;
        printf("%u", cells);
      }
    }
    printf("\n");
  }
  return maze;
}
/*
Labyrinth Swap(Labyrinth maze) {
  for (uint x = 0; x < SIZE; x++) {
    for (uint y = 0; y < SIZE; y++) {
      if (== 0) {
        (x, y) = 5;
      }
    }
  }
}
*/
void Game_Delete(Labyrinth maze) {
  if (maze != NULL) {
    if (maze->game != NULL) {
      free(maze->game);
      maze->game = NULL;
    }
    if (maze->init != NULL) {
      free(maze->init);
      maze->init = NULL;
    }
    free(maze);
    maze = NULL;
  }
}
