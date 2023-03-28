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
    return (1 <= y && y <= (HEIGHT / 3)) && (1 <= x && x <= WIDTH - 2);
}
bool is_block(char field[WIDTH][HEIGHT], pixel pixel, char block){
    return field[pixel.x][pixel.y] == block;
}
bool is_gates(pixel pix){
    return pix.y >= HEIGHT - 1;
}
bool is_barrier(char field[WIDTH][HEIGHT], pixel neighbor, rocket* rocket, char block){
    if (is_block(field, neighbor, block)){
        field[neighbor.x][neighbor.y] = ' ';
        return true;
    }
    return is_wall(neighbor) || is_rocket(rocket, neighbor.x, neighbor.y);
}
bool is_game_over(int* health){
    return (*health <= 0) && false;
}
