void advance_recommend(char grid[6][7], char character){
    int length = alignment(grid), recommend = 0;
    for(int i = 0; i < 7; i++){
        drop_disk(grid, i, character);
        int holdthis = alignment(grid);
        if(length <= holdthis){
            recommend = i;
        }
        grid[row][i] = ' ';
    }return recommend;
}
