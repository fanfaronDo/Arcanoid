#ifndef GAME_COMPONENTS_H
#define GAME_COMPONENTS_H
#define length(arr) sizeof(arr) / sizeof(*arr)
#define WIDTH 24
#define HEIGHT 10
#define len_blocks_n (HEIGHT / 3)
#define len_blocks_m (WIDTH - 2)
#include <stdbool.h>

typedef struct 
{
    int x, y;
}pixel;

typedef struct  
{
    pixel elems[3];
    char style;

} rocket;

typedef struct
{
    pixel pixel;
    char style;

} ball;

typedef struct
{
    pixel pixel;
    char style;
} block;

typedef struct 
{
    int x_inversion;
    int y_inversion;
} invertion;

bool is_rocket(rocket* rocket, int x, int y);
bool is_ball(ball* ball, int x, int y);
bool is_wall(pixel pixel);
bool is_block_range(int x, int y);
//bool is_block(block** blocks, int x, int y);
bool is_gates(pixel pix);
bool is_barrier(pixel neighbor, rocket* rocket, block** blocks);
bool is_game_over(int* health);
#endif
