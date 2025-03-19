int drop_disk(char grid[6][7], int move, char character){
    /*
    This function drops a disk into the aviable place in the grid if possible, if it's not possible it does nothing
    Input:
        grid: matrix consiting of characters
        move: integer, the column it will fall
        character: character, that basically shows whose turn it is
    Output:
        void: it drops a disk into the empty place
    */
    for(int i = 5; i >= 0; i--){
        if(grid[i][move] == ' '){
            grid[i][move] = character;
            return i;
        }
    }
}
