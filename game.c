#include "game.h"

// вынести инициализацию в другой модуль для возможносте переиспользовать ф-ю init rocket and init ball


void game(){
    rocket rocket;
    ball ball;
    block** blocks;
    invertion invert;
    char field[WIDTH][HEIGHT];  
    bool error = false;
    int health = 4;
    invert.x_inversion = 1;
    invert.y_inversion = 1;
    blocks = allocete_memory(len_blocks_n, len_blocks_m, &error);

    if (error) exit(1);

    init_rocket(&rocket);
    init_ball(&ball, rocket.elems[1].x, rocket.elems[1].y - 1);
    init_blocks(blocks, len_blocks_n, len_blocks_m);
    init_field(field, &rocket, &ball, blocks);
    render(field);

    do {
        char ch = getchar();
        system("cls");
        control_rocket(&rocket, ch);
        init_field(field, &rocket, &ball, blocks);
        movement_ball(&ball, &rocket, &invert, blocks);
        render(field);
    }while (health);
    free_memory(blocks, len_blocks_n);
}

void control_rocket(rocket* rocket, char ch){
    switch (ch)
    {
    case 'a':
        move_rocket(rocket, -1);
        break;
    case 'd':
        move_rocket(rocket, 1);
        break;
    default:
        break;
    }
}

void init_field(char field[WIDTH][HEIGHT], rocket* rocket, ball* ball, block** blocks){
    for (int y = 0; y < HEIGHT; ++y){
        for(int x = 0; x < WIDTH; ++x){
            if (is_rocket(rocket, x, y))
                field[x][y] = rocket->style;
            else if (is_ball(ball, x, y))
                field[x][y] = ball->style;
            else if (is_block_range(x, y))
                field[x][y] = blocks[y - 1][x - 1].style;
            else
                field[x][y] = ' ';
        }
    }
}

void init_rocket(rocket* rocket){
    rocket->style = '-';
    int x = (WIDTH / 2) - 2;
    int y = HEIGHT -1;
    for (int i = 0; i < 3; ++i){
        rocket->elems[i].x = x + i;  
        rocket->elems[i].y = y;
    } 
}

void init_ball(ball* ball, int start_x, int start_y){
    ball->style = '0';
    ball->pixel.x = start_x;
    ball->pixel.y = start_y;
}

void init_blocks(block** blocks, int n, int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            block block;
            block.pixel.x = i + 1;
            block.pixel.y = j + 1;
            block.style = '#';
            blocks[i][j] = block;
        }
}

void move_rocket(rocket* rocket, int step){
    int left_edge = 0;
    int right_edge = WIDTH - 1;
    int pivod = rocket->elems[1].x + step;

    if (left_edge < pivod && pivod < right_edge)
        for (int i = 0; i < 3; ++i)
            rocket->elems[i].x += step;
}

void ball_behavior(ball* ball, rocket* rocket, invertion* invert, block** blocks){
    pixel neighbor;
    for (int x = -1; x <= 1; ++x)
        for (int y = -1; y <= 1; ++y){
            if (x == 0 && y == 0) continue;
            if (x != 0 && y != 0) continue;
            neighbor.x = x + ball->pixel.x;
            neighbor.y = y + ball->pixel.y;
            //by X
            if ((x == 0 && y != 0) && (is_barrier(neighbor, rocket, blocks))){
                invert->y_inversion *= -1;
            }else if ((x != 0 && y == 0) && (is_barrier(neighbor, rocket, blocks))){
                invert->x_inversion *= -1;
            }
        }
}

void movement_ball(ball* ball, rocket* rocket, invertion* invert, block** blocks){
    ball_behavior(ball, rocket, invert, blocks);
    int step_x = invert->x_inversion;
    int step_y = invert->y_inversion;
    ball->pixel.x += step_x;
    ball->pixel.y += step_y;
}

block** allocete_memory(int n, int m, bool* error){
    block** array;
    array = malloc(n * sizeof(block*));
    if (array != NULL){
        for (int i = 0; i < m; i++){
            array[i] = malloc(m * sizeof(block));
            if (array[i] == NULL)
                *error = true;
        }
    }else
        *error = true;
    return array;
}

void free_memory(block** blocks, int n){
    for (int i = 0; i < n; ++i)
        free(blocks[i]);
    free(blocks);
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