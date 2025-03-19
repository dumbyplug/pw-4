int is_move_possible(char grid[6][7], int move){
    /*
    This function checks if the move is possible through that column
    Input:
        grid[6][7]: a matrix consisting of characters '*' or 'o'
        move: integer, a number between 1 and 7
    Output:
        is_possible: either 0 - move is not possible or 1 -move is possible
    */
    //invalid move that exceeds the row count
    if ((move < 0) || (move > 6)){
		return 0;
    }

    //if 6th row of the grid is empty
    if (grid[0][move] != ' '){
		return 0;
    }

    return 1;
}
