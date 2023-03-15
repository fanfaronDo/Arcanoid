#include "game.h"

void game(){
    rocket rocket;
    ball ball; 
    block* blocks;
    char field[WIDTH][HEIGHT];
    int cnt_blocks = 12;  
    blocks = malloc(cnt_blocks * sizeof(block));
    build_start_blocks(blocks, cnt_blocks);
    default_state(field, &rocket, &ball);
    set_start_blocks(field, blocks, cnt_blocks);
    
    render(field);

    free(blocks);
}

void build_start_blocks(block* blocks, int cnt_blocks){
    int x = 0;
    int y = 1;
    printf("count blocks = %d\n", cnt_blocks);
    for (int i = 0; i < cnt_blocks; ++i){  
        block block;
        block.elems[0].x = x++;
        block.elems[0].y = y;
        block.elems[1].x = x++;
        block.elems[1].y = y;
        block.style = '#';
        blocks[i] = block; 
        if (x == WIDTH - 2){
            y++;
            x = 2;
        }
    }
}

void set_start_blocks(char field[WIDTH][HEIGHT], block* blocks, int cnt_blocks){
    for (int i = 0; i < cnt_blocks; ++i){
        field[blocks[i].elems[0].x][blocks[i].elems[0].y] = blocks[i].style;
        field[blocks[i].elems[1].x][blocks[i].elems[1].y] = blocks[i].style;

        printf("x = %d y = %d\n", blocks[i].elems[0].x, blocks[i].elems[0].y);
        printf("x = %d y = %d\n\n", blocks[i].elems[1].x, blocks[i].elems[1].y); 
    }
}

void default_state(char field[WIDTH][HEIGHT], rocket* rocket, ball* ball){
      
    //block blocks[(WIDTH / 2) + (HEIGHT / 2)];
    rocket->style = '_';
    int len_elem_rocket = (int)length(rocket->elems);
    for(int i = 0; i < len_elem_rocket; ++i){
        rocket->elems[i].x = ((WIDTH / 2) - 1) + i;
        rocket->elems[i].y = HEIGHT - 1;
    }
    ball->style = '*';
    ball->pixel.x = rocket->elems[1].x;
    ball->pixel.y = rocket->elems[1].y - 1;

    for (int y = 0; y < HEIGHT; ++y){
        for (int x = 0; x < WIDTH; ++x){
            if (is_rocket(rocket, x, y)){
                field[x][y] = rocket->style;
            }else if (is_ball(ball, x, y)){
                field[x][y] = ball->style;
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