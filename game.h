#ifndef GAME_H
#define GAME_H




#include <stdio.h>
#include <stdlib.h>
#include "game_components.h"

void render(char field[WIDTH][HEIGHT]);
void game();
void init_field(char field[WIDTH][HEIGHT], rocket* rocket, ball* ball, block** blocks);
void init_rocket(rocket* rocket);
void init_ball(ball* ball, int start_x, int start_y);
void init_blocks(block** blocks, int n, int m);
void move_rocket(rocket* rocket, int step);
void ball_behavior(ball* ball, rocket* rocket, invertion* invert, block** blocks);
void movement_ball(ball* ball, rocket* rocket, invertion* invert, block** blocks);
void control_rocket(rocket* rocket, char ch);
block** allocete_memory(int n, int m, bool* error);
void free_memory(block** blocks, int n);


#endif