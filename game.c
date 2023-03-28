#include "game.h"

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
    int len_blocks_n = HEIGHT / 3;
    int len_blocks_m = WIDTH - 2;
    blocks = allocete_memory(len_blocks_n, len_blocks_m, &error);

    if (error) exit(1);
    
    
    init_rocket(&rocket);
    init_ball(&ball, rocket.elems[1].x, rocket.elems[1].y - 1);
    init_field(field, &rocket, &ball, blocks);
    render(field);

    do {
        char ch = getchar();
        system("cls");
        control_rocket(&rocket, ch);
        init_field(field, &rocket, &ball, blocks);
        movement_ball(field, &ball, &rocket, &invert, blocks);
        render(field);
    }while (health);
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

void init_field(char field[WIDTH][HEIGHT], rocket* rocket, ball* ball, char block){
    for (int y = 0; y < HEIGHT; ++y)
        for(int x = 0; x < WIDTH; ++x){
            if (is_rocket(rocket, x, y))
                field[x][y] = rocket->style;
            else if (is_ball(ball, x, y))
                field[x][y] = ball->style;
            else if (is_block_range(x, y))
                field[x][y] = block;
            else
                field[x][y] = ' ';
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

void ball_behavior(char field[WIDTH][HEIGHT], ball* ball, rocket* rocket, invertion* invert, char block){
    pixel neighbor;
    for (int i_x = -1; i_x <= 1; ++i_x)
        for (int j_y = -1; j_y <= 1; ++j_y){
            if (i_x == 0 && j_y == 0) continue;
            if (i_x != 0 && j_y != 0) continue;
            neighbor.x = i_x + ball->pixel.x;
            neighbor.y = j_y + ball->pixel.y;
            //by X
            if ((i_x == 0 && j_y != 0) && (is_barrier(field, neighbor, rocket, block))){
                invert->y_inversion *= -1;
            }else if ((i_x != 0 && j_y == 0) && (is_barrier(field, neighbor, rocket, block))){
                invert->x_inversion *= -1;
            }
        }
}



void movement_ball(char field[WIDTH][HEIGHT], ball* ball, rocket* rocket, invertion* invert, char block){
    ball_behavior(field, ball, rocket, invert, block);
    int step_x = invert->x_inversion;
    int step_y = invert->y_inversion;
    //printf("step x = %d\n", step_x);
    //printf("step y = %d\n", step_y);
    ball->pixel.x += step_x;
    ball->pixel.y += step_y;
}

block** allocete_memory(int n, int m, bool* error){
    block** array;
    array = malloc(n * sizeof(block*));
    if (*array != NULL){
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