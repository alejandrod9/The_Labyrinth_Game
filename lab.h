#ifndef __GAME_H__
#define __GAME_H__
#include <stdbool.h>

/**
 * @file lab.h
 * @brief  This file describes each function destined to code a puzzle game,
name 'Labyrinth'.
 *
 * @mainpage
 *
 * The game starts with a grid containing random filled generated cells in order
to create walls.
 * The cells of the grid are denoted by (x,y) coordinates, (0,0) corresponding
to the bottom left corner,
 * the first coordinate represents each line, the other one represents each
column.
 *
 * The goal is to find the exit of the labyrinth without touching any walls, if
not you will loose
 *
 * Here is an example of a game and its solution.
 *
 * @verbatim

  | Example of a game

11111111111111111
10000001100010001
10001110001110101
10100010101000100 <-Exit point
10111000100011111
10101111111110001
10001000010000111
10000010101010001
10101000101010111
11111000101011101
10001110000000101
10100001110111101
10111110000010001
10100011011000111
10001000001010001
11011101011011111
10000101001000001
10111111111111111
 ^
 Starting point


U = Up Arrow
D = Down Arrow
R = Right Arrow
L = Left Arrow

Solution: U R U U R U R R D R R R U U R R U U L L L U U U U L L D L L L L U U U
U U U R R D D R R D R R U U R R D D R R U R R U U R R D D R
 @endverbatim

 */

#define SIZE 17  // size with outer cells -> size (15) + 2

typedef unsigned int uint;

typedef struct Labyrinth_s *Labyrinth;

/**
 * @brief The structure constant pointer that stores the game
 * That means that it is not possible to modify the game using this pointer.
 **/

Labyrinth Create_Labyrinth(uint size);

void Free_Labyrinth(Labyrinth maze);

Labyrinth Print_Random_Labyrinth(Labyrinth maze);

Labyrinth Swap(Labyrinth maze);

void Game_Delete(Labyrinth maze);

#endif  // __GAME_H__