#include "game_components.h"


bool is_rocket(rocket* rocket, pixel pxl){
    int len = length(rocket->elems);
    for(int i = 0; i < len; i++){
        if (rocket->elems[i].x == pxl.x && rocket->elems[i].y == pxl.y) 
            return true;
    }
    return false;
}

bool is_ball(ball* ball, pixel pxl){
    return true ? ball->pixel.x == pxl.x && ball->pixel.y == pxl.y : false;
}
bool is_wall(pixel pixel){ 
    return pixel.x == 0 || pixel.x == WIDTH - 1 || pixel.y == 0; 
}
bool is_block(pixel pxl, block** blocks, bool kill_block){
    for (int i = 0; i < len_blocks_n; i++)
        for (int j = 0; j < len_blocks_m; j++){
            if ((pxl.x == blocks[i][j].pixel.x && pxl.y == blocks[i][j].pixel.y) && blocks[i][j].alive){
                if (kill_block)
                    blocks[i][j].alive = false;
                return true;    
            }
        }
    return false;
}
bool is_gates(pixel pix){
    return (pix.x > 0 || pix.x < WIDTH) && (pix.y == HEIGHT);
}

bool is_barrier(pixel neighbor, rocket* rocket, block** blocks, ball* ball, int* health){
    bool is_barrier_1 = false;

    if (is_block(neighbor, blocks, true)){
        is_barrier_1 = true;
    }else if (is_gates(neighbor)){
        health -= 1;
        ball->pixel.x = rocket->elems[1].x;
        ball->pixel.y = rocket->elems[1].y - 1;
        is_barrier_1 = true;
    }else if (is_wall(neighbor)){
        is_barrier_1 = true;
    }else if (is_rocket(rocket, neighbor)){
        is_barrier_1 = true;
    }

    return is_barrier_1;
}
bool is_game_over(int* health){
    return (*health <= 0) && false;
}