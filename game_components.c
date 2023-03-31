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
bool is_wall(pixel pixel){ 
    return pixel.x == 0 || pixel.x == WIDTH - 1 || pixel.y == 0; 
}
bool is_block_range(int x, int y){
    return (1 <= x && x <= len_blocks_m) && (1 <= y && y <= len_blocks_n);
}
/*{
    return true;
}*/
bool is_gates(pixel pix){
    return pix.y >= HEIGHT - 1;
}
bool is_barrier(pixel neighbor, rocket* rocket, block** blocks){
    if (is_block_range(neighbor.x, neighbor.y)){
        blocks[neighbor.x][neighbor.y].style = ' ';
        return true;
    }
    return is_wall(neighbor) || is_rocket(rocket, neighbor.x, neighbor.y);
}
bool is_game_over(int* health){
    return (*health <= 0) && false;
}
