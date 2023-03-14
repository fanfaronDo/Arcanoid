#include "game_components.h"
#include "game.h"

void game(){
    char field[WIDTH][HEIGHT];
    default_state(field);
    render(field);
}

void default_state(char field[WIDTH][HEIGHT]){
    rocket rocket;
    ball ball;  
    //block blocks[(WIDTH / 2) + (HEIGHT / 2)];
    rocket.style = '_';
    int len_elem_rocket = (int)length(rocket.elems);
    for(int i = 0; i < len_elem_rocket; ++i){
        rocket.elems[i].x = (WIDTH / 2) + i;
        rocket.elems[i].y = HEIGHT - 1;
    }
    ball.style = '*';
    ball.pixel.x = rocket.elems[1].x;
    ball.pixel.y = rocket.elems[1].y - 1;

    for (int y = 0; y < HEIGHT; ++y){
        for (int x = 0; x < WIDTH; ++x){
            if (is_rocket(rocket, x, y)){
                field[x][y] = rocket.style;
            }else if (is_ball(ball, x, y)){
                field[x][y] = ball.style;
            }else{
                field[x][y] = ' ';
            }
        }
    }
}
void render(char field[WIDTH][HEIGHT]){
    for (int y = 0; y < HEIGHT; ++y){
        for (int x = 0; x < WIDTH; ++x){
            char pxl = field[x][y];
            printf("%c", pxl);
        }
        printf("\n");
    }
}