#ifndef GAME_COMPONENTS_H
#define GAME_COMPONENTS_H
#define length(arr) sizeof(arr) / sizeof(*arr)
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
    pixel elems[2];
    char style;
} block;

bool is_rocket(rocket* rocket, int x, int y);
bool is_ball(ball* ball, int x, int y);
bool is_block(block* block, int x, int y);

#endif
