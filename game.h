#ifndef GAME_H
#define GAME_H
#define WIDTH 24
#define HEIGHT 10
#define range_width_blocks (WIDTH - 4) / 2
#define range_height_blocks (HEIGHT / 2) - 2


#include <stdio.h>
#include <stdlib.h>
#include "game_components.h"

void default_state(char field[WIDTH][HEIGHT], rocket* rocket, ball* ball);
void build_start_blocks(block* blocks, int cnt_blocks);
void set_start_blocks(char field[WIDTH][HEIGHT], block* blocks, int cnt_blocks);
void render(char field[WIDTH][HEIGHT]);
void game();

#endif