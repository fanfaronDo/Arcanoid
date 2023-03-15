#include "game_components.h"


bool is_rocket(rocket* rocket, int x, int y){
    int len = length(rocket->elems);
    for(int i = 0; i < len; i++){
        if (rocket->elems[i].x == x && rocket->elems[i].y == y) 
            return true;
    }
    return false;
}

bool is_ball(ball* ball, int x, int y){
    return true ? ball->pixel.x == x && ball->pixel.y == y : false;
}

bool is_block(block* block, int x, int y){
    int len = length(block->elems);
    for (int i = 0; i < len; ++i){
        if (block->elems[i].x == x && block->elems[i].y == y) 
            return true;
    }
    return false;
}