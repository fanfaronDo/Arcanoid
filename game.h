#ifndef GAME_H
#define GAME_H
#define WIDTH 25
#define HEIGHT 20

#include <stdio.h>

void default_state(char field[WIDTH][HEIGHT]);
void render(char field[WIDTH][HEIGHT]);
void game();

#endif