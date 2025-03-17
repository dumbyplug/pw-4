#include<stdio.h>

int is_move_possible(char grid[6][7], int move);

int main(){
    char grid[6][7]={
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };

    printf("%d\n", is_move_possible(grid, 0));

    drop_disk(grid, 2, '*');
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            printf("%c ", grid[i][j]);
        }printf("\n");
    }

    return 0;
}

int is_move_possible(char grid[6][7], int move){
    /*
    This function checks if the move is possible through that column
    Input:
        grid[6][7]: a matrix consisting of characters '*' or 'o'
        move: integer, a number between 1 and 7
    Output:
        is_possible: either 0 - move is not possible or 1 -move is possible
    */
    int is_possible = 1;

    //invalid move that exceeds the row count
    if (move < 0 || move >6){
        is_possible = 0;
    }

    //if 6th row of the grid is empty
    if (grid[0][move] != ' '){
        is_possible = 0;
    }

    return is_possible;
}
