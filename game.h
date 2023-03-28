#ifndef GAME_H
#define GAME_H




#include <stdio.h>
#include <stdlib.h>
#include "game_components.h"

void render(char field[WIDTH][HEIGHT]);
void game();
void init_field(char field[WIDTH][HEIGHT], rocket* rocket, ball* ball, char block);
void init_rocket(rocket* rocket);
void ball_behavior(char field[WIDTH][HEIGHT], ball* ball, rocket* rocket, invertion* invert, char block);
void movement_ball(char field[WIDTH][HEIGHT], ball* ball, rocket* rocket, invertion* invert, char block);
void init_ball(ball* ball, int start_x, int start_y);
void control_rocket(rocket* rocket, char ch);
void move_rocket(rocket* rocket, int step);

#endif